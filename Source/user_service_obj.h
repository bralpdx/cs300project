// This file contains the class definitions of the user
// and service classes.

#pragma once

#include <iostream>
#include <fstream>
#include <string>

// Abstract Base Class (ID numbers)
class ID{
public:
	ID();
	~ID();
	ID *& go_left();
	ID *& go_right();
private:
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
	Record* head;
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

class Record {
public:
	Record();
	~Record();
	Record *& go_next();
private:
	std::string file_address;
	Record* next;
};