#include "user_service_obj.h"

//////////////////////////////////
//        ID Base Class         //
//////////////////////////////////
ID::ID() {
	left = NULL;
	right = NULL;
	data = "";
}

ID::~ID() {
	left = NULL;
	right = NULL;
	data = "";
}

ID *& ID::go_left() {
	return left;
}

ID*& ID::go_right() {
	return right;
}


//////////////////////////////////
//         Person Class         //
//////////////////////////////////

Person::Person() {

}

Person::~Person() {

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