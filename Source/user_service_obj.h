// This file contains the class definitions of the user
// and service classes.

#pragma once

#include <string>

// Abstract Base Class (ID numbers)
class ID{
public:
	ID();
	~ID();
protected:
	ID *left;
	ID *right;
	std::string data; // Contains the objects ID number
};

// Person class derived from ID
class Person : public ID {
public:
	Person();
	~Person();
protected:
	// Needs pointer to head of record list
};

// Provider class derived from Person
class Provider : public Person {
public:
	Provider();
	~Provider();
protected:
};

// Member class derived from Person
class Member : public Person {
public:
	Member();
	~Member();
protected:
};

//Abstract Base Class
class Record{
public:
	Record();
	~Record();
protected:
	Record * next;
};

//Provider record derived from Record
class Provider_record : public Record {
public: 
	Provider_record();
	~Provider_record();
protected:

};

//Member record derived from Records
class Member_record : public Record {
public: 
	Member_record();
	~Member_record();
protected:

};
