#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include "user_service_obj.h"
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <Windows.h>
#include <stdio.h>
#include <io.h>


//////////////////////////////////
//        ID Base Class         //
//////////////////////////////////
ID::ID() {
	left = NULL;
	right = NULL;
	hash_value = "";
}

ID::~ID() {
	left = NULL;
	right = NULL;
	hash_value = "";
}

ID *& ID::go_left() {
	return left;
}

ID *& ID::go_right() {
	return right;
}

int ID::compare(std::string to_compare) {
	int result1 = 0;
	int result2 = 0;
	int size1 = this->hash_value.length;
	int size2 = to_compare.length;
	int multiplier = 1048576;

	if ((size1 > 5) && (size2 > 5)) {
		for (int i = 0; i < 6; i++) {
			if ((this->hash_value[i] > 47) && (this->hash_value[i] < 58)) {
				result1 += multiplier * (hash_value[i] - 48);
			}
			else if ((this->hash_value[i] > 96) && (this->hash_value[i] < 103)) {
				result1 += multiplier * (hash_value[i] - 86);
			}

			if ((to_compare[i] > 47) && (to_compare[i] < 58)) {
				result2 += multiplier * (to_compare[i] - 48);
			}
			else if ((to_compare[i] > 96) && (to_compare[i] < 103)) {
				result2 += multiplier * (to_compare[i] - 86);
			}
			multiplier = multiplier / 16;
		}
		return result1 - result2;
	}
	else if (size1 > size2) return 100000;
	else if (size1 < size2) return -100000;
	else {
		multiplier = multiplier / ((6-size1) * 16);
		for (int i = 0; i < size1; i++) {
			if ((this->hash_value[i] > 47) && (this->hash_value[i] < 58)) {
				result1 += multiplier * (hash_value[i] - 48);
			}
			else if ((this->hash_value[i] > 96) && (this->hash_value[i] < 103)) {
				result1 += multiplier * (hash_value[i] - 86);
			}

			if ((to_compare[i] > 47) && (to_compare[i] < 58)) {
				result2 += multiplier * (to_compare[i] - 48);
			}
			else if ((to_compare[i] > 96) && (to_compare[i] < 103)) {
				result2 += multiplier * (to_compare[i] - 86);
			}
			multiplier = multiplier / 16;
		}
		return result1 - result2;
	}
}


bool ID::is_leaf() {
	if ((!left) && (!right)) return true;
	else return false;
}
//////////////////////////////////
//         Person Class         //
//////////////////////////////////

Person::Person(): ID() {
	head = NULL;
	name = "";
	address = "";
	city = "";
	state = "";
	zip = 0;
}

Person::~Person() {
	destroy(head);
	name = "";
	address = "";
	city = "";
	state = "";
	zip = 0;
}

int Person::report() {

}


int Person::add_record(Record *& to_add) {
	if (!head) {
		head = to_add;
		return 1;
	}
	else {
		to_add->set_next(head);
		head = to_add;
		return 2;
	}
}

int Person::remove_record(std::string to_remove) {
	return remove_record(to_remove, head);
}

int Person::remove_record(std::string to_remove, Record *& head) {
	int success = 0;
	if (!head) return success;
	std::string grab;
	head->get_file_address(grab);
	if (!grab.compare("")) {
		//panic!!!!
		return -1;
	}
	if (!to_remove.compare(grab)) {
		Record* temp = head;
		head = head->go_next();
		delete temp;
		success++;
	}
	success = remove_record(to_remove, head->go_next());
	return success;
}

int Person::num_records() {
	return num_records(head);
}

int Person::get_filenames(char** array) {
	return get_filenames(head, array, 0);
}

int Person::num_records(Record * head) {
	if (!head) return 0;
	return num_records(head->go_next()) + 1;
}

int Person::get_filenames(Record* head, char** array, int i) {
	int success = 0;
	if (!head) return success;
	std::string temp;
	head->get_file_address(temp);
	array[i] = new char[temp.length() + 1];
	for (int j = 0; j < temp.length(); ++j) {
		array[i][j] = temp[j];
	}
	array[i][temp.length()] = '\0';
	success = get_filenames(head->go_next(), array, ++i) + 1;
	return success;
}

void Person::destroy(Record*& head) {
	if (!head) return;
	destroy(head->go_next());
	delete head;
	return;
}


//////////////////////////////////
//        Provider Class        //
//////////////////////////////////

Provider::Provider(): Person() {

}
Provider::~Provider() {

}

int Provider::report() {
	/* NONSENSE Pure and simple

	int check;
	time_t now = time(0);
	std::string dt = ctime(&now);
	char dir[12];
	for (int i = 0; i < 11; i++) {
		if (i < 3) dir[i] = dt[i + 4];
		else if ((i > 3) && (i < 6)) dir[i] = dt[i + 8];
		else if (i > 6) dir[i] = dt[i + 20];
		else dir[i] = '-';
	}
	dir[11] = '\0';
	check = CreateDirectoryA(dir, NULL);

	Person::report();
	*/

}

//////////////////////////////////
//         Member Class         //
//////////////////////////////////

Member::Member(): Person() {
	member_number = 0;
}
Member::~Member() {
	member_number = 0;
}

int Member::report() {
	using namespace std;
	int num;
	int check;
	streamsize size = 100;
	ofstream file_in;
	time_t now = time(0);
	string dt = ctime(&now);
	string date;
	string filename;
	string text = ".txt";

	date.append(dt, 4, 3);
	date.append("-");
	date.append(dt, 8, 2);
	date.append("-");
	date.append(dt, 20, 4);

	filename.append(this->name);
	filename.append(date);
	filename.append(text);

	file_in.open(filename);

	if (!file_in) return -1;

	file_in << this->name;
	file_in << "\n";
	file_in << this->member_number;
	file_in << "\n";
	file_in << this->address;
	file_in << "\n";
	file_in << this->city;
	file_in << "\n";
	file_in << this->state;
	file_in << "\n";
	file_in << this->zip;
	file_in << "\n";

	num = num_records();
	char** array = new char * [num];
	check = get_filenames(array);
	char text[100];
	char* text2 = new char [100];
	char delim = '&';

	for (int i = 0; i < check; ++i) {
		ifstream file_out;
		file_out.open(array[i]);
		if (!file_out) return -1 - i;
		do {
			file_out.get(text2, size, delim);
			file_out.ignore(size, '&');
			file_out.get(text2, size, delim);
			file_out.ignore(size, '&');
			file_out.get();
			file_in << text2;
			file_in << "\n";
		} while (!file_out.eof());
		file_out.close();
	}

	file_in.close();

	return check;
}

//////////////////////////////////
//         Service Class        //
//////////////////////////////////

Service::Service(): ID() {
	svcName = "";
}

Service::~Service() {
	svcName = "";
}

//////////////////////////////////
//         Record Class         //
//////////////////////////////////
Record::Record() {
	next = NULL;
}

Record::~Record() {
	next = NULL;
}

Record*& Record::go_next() {
	return next;
}


int Record::get_file_address(std::string & copy){
	if (!file_address.compare("")) return -1;
	else {
		copy = file_address;
		return 0;
	}
}


void Record::set_next(Record*& ptr) {
	next = ptr;
}

int Record::add(std::string address) {
	if (!file_address.compare("")) return -1;
	file_address = address;
	return 0;
}

int Record::remove(std::string address) {
	if (!file_address.compare(address)) {
		file_address = "";
		return 0;
	}
	return -1;
}


//////////////////////////////////
//         Account Class        //
//////////////////////////////////


Account::Account() {
	dollar = 0;
	cent = 0;
}

Account::Account(int dol, int cen) {
	dollar = dol;
	cent = cen;
}

Account::Account(const Account& obj) {
	dollar = obj.dollar;
	cent = obj.cent;
}
Account::~Account() {
	dollar = 0;
	cent = 0;
}


void Account::add(int dol, int cen) {
	dollar += dol;
	if ((cent + cen) < 100) cent += cen;
	else {
		dollar++;
		cent = (cent + cen - 100);
	}
}


void Account::subtract(int dol, int cen) {
	dollar -= dol;
	if ((cent - cen) >= 0) cent -= cen;
	else {
		dollar--;
		cent = (cent - cen + 100);
	}
}

bool Account::good_standing() {
	if ((dollar > 0) || ((dollar == 0) && (cent >= 0))) return true;
	else return false;
}

Account& Account::operator = (const Account& a) {
	if (this == &a) return *this;
	this->dollar = dollar;
	this->cent = cent;
	return *this;
}
Account& Account::operator += (const Account& a) {
	this->dollar += a.dollar;
	this->cent += a.cent;
	return *this;
}

Account& Account::operator -= (const Account& a) {
	this->dollar -= a.dollar;
	this->cent -= a.cent;
	return *this;
}

Account Account::operator + (const Account& a) const {
	Account sum;
	sum.dollar = dollar + a.dollar;
	sum.cent = cent + a.cent;
	return sum;
}

Account Account::operator - (const Account& a) const {
	Account diff;
	diff.dollar = dollar - a.dollar;
	diff.cent = cent - a.cent;
	return diff;
}

bool Account::operator == (const Account& a)const {
	if ((dollar == a.dollar) && (cent == a.cent)) return true;
	else return false;
}
bool Account::operator != (const Account& a)const {
	if ((dollar == a.dollar) && (cent == a.cent)) return false;
	else return true;
}
bool Account::operator < (const Account& a)const {
	if (dollar < a.dollar) return true;
	else if ((dollar == a.dollar) && (cent < a.cent)) return true;
	else return false;
}
bool Account::operator > (const Account& a)const {
	if (dollar > a.dollar) return true;
	else if ((dollar == a.dollar) && (cent > a.cent)) return true;
	else return false;
}
bool Account::operator <= (const Account& a)const {
	if (dollar < a.dollar) return true;
	else if ((dollar == a.dollar) && (cent <= a.cent)) return true;
	else return false;
}
bool Account::operator >= (const Account& a)const {
	if (dollar > a.dollar) return true;
	else if ((dollar == a.dollar) && (cent >= a.cent)) return true;
	else return false;
}