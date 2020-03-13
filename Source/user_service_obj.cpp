#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include "user_service_obj.h"
#include "hash-library-master/sha256.h"
#include "param.h"

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
	int size1 = this->hash_value.length();
	int size2 = to_compare.length();
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

std::string ID::get_hash() {
  return hash_value;
}



void ID::Display(){}
void ID::Edit(Provider&){}
void ID::Edit(Member&){}
void ID::CopyData(Provider&){}
void ID::CopyData(Member&){}
void ID::CopyData(Service&){}
bool ID::good_standing() { return true; }

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

int Person::report(){
	return 0;
}

void Person::Read(){
	std::string id = "";
	SHA256 hash;

	std::cout << "Name: ";
	std::cin >>name;
;
	std::cout << "Address: ";
	std::cin >>address;
 ;
	std::cout << "City: ";
	std::cin >>city;
;
	std::cout << "State: ";
	std::cin >>state;
;
	std::cout << "Zip Code: ";
	std::cin >>zip;

	std::cin.clear();
	std::cin.ignore(MAX_CHAR, '\n');
;
	std::cout << "Enter ID (9-Digits): ";
	while (!(std::cin >>id ) || id.size() != ID_SIZE) {
		std::cout << "Error: Incorrect value entered. Use only numerical digits.\n";
		std::cin.clear();
		std::cin.ignore(MAX_CHAR, '\n');
		std::cout << "Enter ID (9-Digits): ";
	}

	hash_value = hash(id);
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

int Person::get_name(std::string & to_copy) {
	if (!name.compare("")) return 0;
	to_copy = name;
	return 1;
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
	int size = temp.length();
	head->get_file_address(temp);
	array[i] = new char[size + 1];
	for (int j = 0; j < size; ++j) {
		array[i][j] = temp[j];
	}
	array[i][size] = '\0';
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

Provider::Provider(ID *& to_copy) {

}
/* = = = = = = = = = = = = = = = = = = = = = = */
//            Provider Copy Constructor
//
//INPUT: Provider object by reference.
//
//OUTPUT: Technically nothing.
//
//DESC: Copies the input provider object.
//
Provider::Provider(Provider & to_copy) {
  name = to_copy.name;
  address = to_copy.address;
  city = to_copy.city;
  state = to_copy.state;
  zip = to_copy.zip;
  hash_value = to_copy.ID::get_hash();

  //need a copy lll function
  //head = to_copy.head;
  
  left = NULL;
  right = NULL;
}

void Provider::Read(){
	Person::Read();
}
int Provider::report() {
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
	file_in << this->provider_number;
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
	char** array = new char* [num];
	check = get_filenames(array);
	//char text[100];
	char* text2 = new char[100];
	char* text3 = new char[1000];
	char delim = '&';
	const int SIZE = 100;
	char s[SIZE];


	for (int i = 0; i < check; ++i) {
		ifstream file_out;
		file_out.open(array[i]);
		if (!file_out) return -1 - i;
		file_out.get(text3, 1000, '#');
		file_out.ignore(size, '#');
		do {
			file_out.get(&s[0], SIZE, '&');// if doesn't work try this
			//file_out.get(text2, size, delim);
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

/* = = = = = = = = = = = = = = = = = = = = = = */
//              Insert Function
//
//INPUT: Strings and ints.
//
//OUTPUT: Technically nothing.
//
//DESC: Primarily used for testing, used to input
//      data into a Provider object.
//
void Provider::Insert(std::string cpyname, std::string cpyaddress, std::string cpycity, std::string cpystate, int cpyzip, std::string cpyhash_value) {
	//cant access head, and shouldn't need to.
	//head = NULL;

  left = NULL;
  right = NULL;
  hash_value = cpyhash_value;
  name = cpyname;
  address = cpyaddress;
  city = cpycity;
  state = cpystate;
  zip = cpyzip;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              Display Function
//
//INPUT: Nothing.
//
//OUTPUT: Returns nothing.
//
//DESC: Used primarily for testing. Displays
//      The provider object's data.
//
void Provider::Display() {                          
  std::cout << "\n\nHash Value: " << hash_value;
  std::cout << "\nName is: " << name;
  std::cout << "\nAddress is: " << address;
  std::cout << "\ncity is: " << city;
  std::cout << "\nstate is: " << state;
  std::cout << "\nzip is: " << zip;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              Edit Function
//
//INPUT: Provider object by reference.
//
//OUTPUT: Returns nothing.
//
//DESC: Copies the data from the input provider object.
//
void Provider::Edit(Provider& to_copy){
  hash_value = to_copy.ID::get_hash();
  name = to_copy.name;
  address = to_copy.address;
  city = to_copy.city;
  state = to_copy.state;
  zip = to_copy.zip;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//
//
//INPUT:
//
//OUTPUT:
//
//DESC:
//
//
void Provider::CopyData(Provider& copy_to){
  copy_to.hash_value = hash_value;
  copy_to.name = name;
  copy_to.address = address;
  copy_to.city = city;
  copy_to.state = state;
  copy_to.zip = zip;
}

/*
int Provider::report() {
	return 0;
}*/
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
	//char text[100];
	char* text2 = new char [100];
	char delim = '&';

	for (int i = 0; i < check; ++i) {
		ifstream file_out;
		file_out.open(array[i]);
		if (!file_out) return -1 - i;
		do {
			file_out.get(text2, size, delim);
			file_out.ignore(size, '&');
			file_out.get();
			if (strcmp(text2, "STOP")) break;
			file_in << text2;
			file_in << "\n";
		} while (!file_out.eof());
		file_out.close();
	}
	return check;
}

/* Do we need this?
Member::Member(ID *&  to_copy) {
}*/

/* = = = = = = = = = = = = = = = = = = = = = = */
//            Member copy Constructor
//
//INPUT: Member object by reference.
//
//OUTPUT: Returns nothing.
//
//DESC: Copies the data from the Member object
//      that is passed in for the new Member object.
//
Member::Member(Member & to_copy) {
  name = to_copy.name;
  address = to_copy.address;
  city = to_copy.city;
  state = to_copy.state;
  zip = to_copy.zip;
  hash_value = to_copy.ID::get_hash();

  //Need a copy function for a LLL
  //head = to_copy.head;

  left = NULL;
  right = NULL;
}

void Member::Read(){
	Person::Read();
}

int Member::Write_report(std::string filename, Provider & obj1, Service & obj2) {
	std::ofstream file_in;
	time_t now = time(0);
	struct tm* timeinfo;
	std::string dt = ctime(&now);
	timeinfo = localtime(&now);
	char time[9];

	char today[11];

	if (timeinfo->tm_mon < 9) today[0] = '0';
	else today[0] = '1';

	char mon = timeinfo->tm_mon + 49;

	today[1] = mon;
	today[2] = '-';
	today[3] = dt[8];
	today[4] = dt[9];
	today[5] = '-';
	today[6] = dt[20];
	today[7] = dt[21];
	today[8] = dt[22];
	today[9] = dt[23];
	today[10] = '\0';

	for (int i = 0; i < 9; ++i) {
		time[i] = dt[i + 11];
	}
	time[8] = '\0';

	std::string provider_name;
	std::string service_name;
	obj1.get_name(provider_name);
	obj2.get_service(service_name);
	int dol, cen;
	int serv_num = obj2.get_num();
	member_account.get_balance(dol, cen); // Trying to fix an error

	file_in.open(filename);
	if (!file_in) return -1;

	file_in << '&';
	file_in << today;
	file_in << '&';
	file_in << provider_name;
	file_in << '&';
	file_in << service_name;
	file_in << "&STOP&#\n"; // Trying to fix an error
	file_in << '&';
	file_in << today; //should be the date service recieved
	file_in << '&';
	file_in << today;
	file_in << ' ';
	file_in << time;
	file_in << '&';
	file_in << this->name;
	file_in << '&';
	file_in << this->member_number;
	file_in << '&';
	file_in << serv_num;
	file_in << '&';
	file_in << dol;
	file_in << '&';
	file_in << cen;
	file_in << '&';

	
	file_in.close();

	return 1;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//          Insert Function
//
//INPUT: strings and an int.
//
//OUTPUT: returns nothing.
//
//DESC: Used primarily for testing. Input the passed in data
//      into the Member object that called it.
//
void Member::Insert(std::string cpyname, std::string cpyaddress, std::string cpycity, std::string cpystate, int cpyzip, std::string cpyhash_value){
  
	//shouldn't need to change head
	//head = NULL;
  left = NULL;
  right = NULL;
  hash_value = cpyhash_value;
  name = cpyname;
  address = cpyaddress;
  city = cpycity;
  state = cpystate;
  zip = cpyzip;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//          Display function
//
//INPUT: Nothing.
//
//OUTPUT: Returns nothing.
//
//DESC: Displays the data of the Member object.
//
void Member::Display() {                          
  std::cout << "\n\nHash Value: " << hash_value;
  std::cout << "\nName is: " << name;
  std::cout << "\nAddress is: " << address;
  std::cout << "\ncity is: " << city;
  std::cout << "\nstate is: " << state;
  std::cout << "\nzip is: " << zip;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//        Edit Function
//
//INPUT: Member object by reference.
//
//OUTPUT: Returns nothing.
//
//DESC: Edit function that copies the
//      data from the passed in Member object.
//
void Member::Edit(Member& to_copy){
  name = to_copy.name;
  address = to_copy.address;
  city = to_copy.city;
  state = to_copy.state;
  zip = to_copy.zip;
  hash_value = to_copy.ID::get_hash();
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//
//
//INPUT:
//
//OUTPUT:
//
//DESC:
//
//
void Member::CopyData(Member& copy_to){
  copy_to.name = name;
  copy_to.address = address;
  copy_to.city = city;
  copy_to.state = state;
  copy_to.zip = zip;
  copy_to.hash_value =  hash_value;
}

/*
int Member::report() {
	return 0;
}
*/

bool Member::good_standing(){
	return member_account.good_standing();
}

//////////////////////////////////
//         Service Class        //
//////////////////////////////////

/* = = = = = = = = = = = = = = = = = = = = = = */
//              Display Function
//
//INPUT: Input is nothing.
//
//OUTPUT: Returns nothing.
//
//DESC: Displays all of the current service object's
//      data.
//
void Service::Display(){
  std::cout << "\nHash Value is: " << hash_value;
  std::cout << "\nService Name is: " << svcName;
  std::cout << "\nNeed to display service fee stuff!!!!\n\n";
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//
//
//INPUT:
//
//OUTPUT:
//
//DESC:
//
void Service::CopyData(Service& copy_to){
  copy_to.hash_value = hash_value;
  copy_to.svcName = svcName;
  copy_to.service_fee = service_fee;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            Service Copy Constructor
//
//INPUT: A service object by reference.
//
//OUTPUT: Returns nothing, technically.
//
//DESC: Copy constructor for service object
//

Service::Service(Service & to_copy){
  left = NULL;
  right = NULL;
  hash_value = to_copy.ID::get_hash();
  svcName = to_copy.svcName;
  service_fee = to_copy.service_fee;

/*
  // was in my merge, unsure if necessary or if something was changed
  // keeping it in here just in case for quick fix
  svcProvider = to_copy.svcProvider;
*/
}

Service::Service(): ID() {
	svcName = "";
	svcProvider = "";
}

Service::~Service() {
	svcName = "";
	svcProvider = "";
}

void Service::SvcRead(){
	int select = 0;
	std::string id;

	std::cout << "Select a Service Provider\n";
	std::cout << "-----------------\n";
	std::cout << "[1] Dietitian\n";
	std::cout << "[2] Internist\n";
	std::cout << "[3] Exercise Specialist\n";
	std::cout << "Select a Service Provider: ";

	while (!(std::cin >> select) || select <= 0 || select > 3) {
		std::cout << "Invalid input.\n";
		std::cout << "Enter: ";
		std::cin.clear();
		std::cin.ignore(MAX_CHAR, '\n');
	}

	if(select == 1){
		svcProvider = "Dietitian";
		hash_value = "d";

		std::cout << "Enter Service ID (6-Digits): ";
		while (!(std::cin >> id) || id.size() != SVC_ID_SIZE) {
			std::cout << "Error: Incorrect value entered. Use only numerical digits.\n";
			std::cin.clear();
			std::cin.ignore(MAX_CHAR, '\n');
			std::cout << "Enter ID: ";
		}

		hash_value.append(id);
	}

	if(select == 2){
		svcProvider = "Internist";
		hash_value = "i";

		std::cout << "Enter Service ID (6-Digits): ";
		while (!(std::cin >> id) || id.size() != SVC_ID_SIZE) {
			std::cout << "Error: Incorrect value entered. Use only numerical digits.\n";
			std::cin.clear();
			std::cin.ignore(MAX_CHAR, '\n');
			std::cout << "Enter ID: ";
		}

		hash_value.append(id);
	}

	if(select == 3){
		svcProvider = "Exercise Specialist";
		hash_value = "e";

		std::cout << "Enter Service ID (6-Digits): ";
		while (!(std::cin >> id) || id.size() != SVC_ID_SIZE) {
			std::cout << "Error: Incorrect value entered. Use only numerical digits.\n";
			std::cin.clear();
			std::cin.ignore(MAX_CHAR, '\n');
			std::cout << "Enter ID: ";
		}

		hash_value.append(id);

	}

	std::cout << "Service Name: ";
 	std::cin >> svcName;

	service_fee.svcFee();

}


int Service::get_service(std::string& to_copy) {
	if (!svcName.compare("")) return 0;
	to_copy = svcName;
	return 1;
}

int Service::get_num() {
	return service_num;
}


int Service::print_alpha() {
	//Service array[]
	return 0;
}


int Service::quick_sort(Service *& array, int lo, int hi) {
	if (hi <= lo) return 0;
	int count = 0;
	std::string key;
	Service key_data;
	//hold on to copy key data								key_data = array[lo]
	array[lo].get_service(key);

	int j = hi;
	int i = lo + 1;
	while (i <= j) {
		std::string temp;
		array[i].get_service(temp);
		if (key.compare(temp)> 0) i++; //advance the left finger
		else if (key.compare(temp) <=0) j--; // advance the right finger
		else { //swap data
			Service swap;
			//function copy data from array[i] into swap:	swap = array[i]
			//same func copy array[j] into array[i]:		array[i] = array[j]
			//same func copy swap into array[j]				array[j] = array[i]
		}
	}
	//place the key
	//function to copy data from array[j] into array[lo]	array[lo] = array[j]
	//function to copy data from key into array[j]			array[j] = key_data	

	count = quick_sort(array, lo, j - 1) + quick_sort(array, j + 1, hi) + 1;
	return count;
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

// Reads in service fee
// Generates substrings and then converts substrings to ints
void Account::svcFee(){
	std::string temp = "";
	std::string sDollar = "";
	std::string sCent = "";
	std::size_t found;

	std::cout << "Service Fee: $";
	std::cin >> temp;

    found = (temp.find('.'));

	sDollar = temp.substr(0, found);
	sCent = temp.substr(found+1, 2);

	dollar = std::stoi(sDollar);
	cent = std::stoi(sCent);

	std::cin.clear();
	std::cin.ignore(MAX_CHAR, '\n');
}

void Account::get_balance(int& dol, int& cen) {
	dol = dollar;
	cen = cent;
	return;
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
