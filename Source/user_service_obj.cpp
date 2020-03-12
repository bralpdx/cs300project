#include "user_service_obj.h"

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

Person::Person() {
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


int Person::add_record(Record *&to_add) {
  if (!head) {
    head = to_add;
    return 1;
  }
  else {
    to_add -> set_next(head);
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
  if (head->get_file_address(grab) < 0) {
    //panic!!!!
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

Provider::Provider() {

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


//////////////////////////////////
//         Member Class         //
//////////////////////////////////

Member::Member() {

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



//////////////////////////////////
//         Service Class        //
//////////////////////////////////

Service::Service() {
  svcName = "";
  svcFee_dollars = 0;
  svcFee_cents = 0;
}

Service::~Service() {
  svcName = "";
  svcFee_dollars = 0;
  svcFee_cents = 0;
}

Service::Service(Service & to_copy){
  left = NULL;
  right = NULL;
  hash_value = to_copy.ID::get_hash();
  svcName = to_copy.svcName;
  svcFee_dollars = to_copy.svcFee_dollars;
  svcFee_cents = to_copy.svcFee_cents;
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
//     Provider_record Class    //
//////////////////////////////////
Provider_record::Provider_record() {

  memberName = "";
  memberNum = "";
  svcCode = "";
  feeOwed_dollars = 0;
  feeOwed_cents = 0;
  currDate = "";
  currTime = "";
  svcDate = "";
}
Provider_record::~Provider_record() {

  memberName = "";
  memberNum = "";
  svcCode = "";
  feeOwed_dollars = 0;
  feeOwed_cents = 0;
  currDate = "";
  currTime = "";
  svcDate = "";

}

//////////////////////////////////
//     Member_record Class    //
//////////////////////////////////
Member_record::Member_record() {

  name = "";
  number = "";
  address = "";
  city = "";
  state = "";
  zip = 0;
  currDate = "";
  currTime = "";
  svcDate = "";
}
Member_record::~Member_record() {
  name = "";
  number = "";
  address = "";
  city = "";
  state = "";
  zip = 0;
  currDate = "";
  currTime = "";
  svcDate = "";

}
