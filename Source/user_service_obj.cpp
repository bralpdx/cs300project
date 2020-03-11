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

//////////////////////////////////
//         Member Class         //
//////////////////////////////////

Member::Member() {

}
Member::~Member() {

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
