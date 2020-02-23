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

ID *& ID::go_right() {
	return right;
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
	svcFee = 0;
}

Service::~Service() {
	svcName = "";
	svcFee = 0;
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

//////////////////////////////////
//     Provider_record Class    //
//////////////////////////////////
Provider_record::Provider_record() {

	memberName = "";
	memberNum = "";
	svcCode = "";
	feeOwed = 0;
	currDate = "";
	currTime = "";
	svcDate = "";
}
Provider_record::~Provider_record() {

	memberName = "";
	memberNum = "";
	svcCode = "";
	feeOwed = 0;
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
