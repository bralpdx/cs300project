#include "user_service_obj.h"
#include <string>

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

  head = to_copy.head;
  left = NULL;
  right = NULL;

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
void Provider::Insert(std::string cpyname, std::string cpyaddress, std::string cpycity, std::string cpystate, int cpyzip, std::string cpyhash_value){
  head = NULL;
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

int Provider::report() {
	return 0;
}
//////////////////////////////////
//         Member Class         //
//////////////////////////////////

Member::Member(): Person() {

}
Member::~Member() {

}

Member::Member(ID *&  to_copy) {
}

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

  head = to_copy.head;
  left = NULL;
  right = NULL;
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
  head = NULL;
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

int Member::report() {
	return 0;
}

//////////////////////////////////
//         Service Class        //
//////////////////////////////////


Service::Service(Service & to_copy){
  left = NULL;
  right = NULL;
  hash_value = to_copy.ID::get_hash();
  svcName = to_copy.svcName;
  service_fee = to_copy.service_fee;
}

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