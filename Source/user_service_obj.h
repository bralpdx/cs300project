// This file contains the class definitions of the user
// and service classes.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

//Abstract Base Class
class Record{
public:
	Record();
	~Record();
	Record *& go_next();
	int get_file_address(std::string & copy);
	void set_next(Record*& ptr);
	int add(std::string address);
	int remove(std::string address);
private:
	std::string file_address;
	Record * next;
};

class Account {
public:
	Account();
	Account(int dol, int cen);
	Account(const Account& obj);
	~Account();
	void add(int dol, int cen);
	void subtract(int dol, int cen);
	bool good_standing();
	Account& operator = (const Account&);
	Account& operator += (const Account&);
	Account& operator -= (const Account&);
	Account operator + (const Account&)const; 
	Account operator - (const Account&)const;
	bool operator == (const Account&)const;
	bool operator != (const Account&)const;
	bool operator < (const Account&)const;
	bool operator > (const Account&)const;
	bool operator <= (const Account&)const;
	bool operator >= (const Account&)const;
private:
	int dollar;
	int cent;
};

// Abstract Base Class (ID numbers)
class ID{
public:
	ID();
	virtual ~ID();
	ID *& go_left();
	ID *& go_right();
	bool is_leaf();
protected:
	ID *left;
	ID *right;
	std::string hash_value; // Contains the objects ID number
};

// Service class derived from ID
// Service stored as: id,fee,name,provider-type
class Service : public ID {
public:
	Service();
	~Service();
protected:
	std::string svcName;
	Account service_fee;
};

// Person class derived from ID
class Person : public ID {
public:
	Person();
	~Person();
	int add_record(Record *& to_add);
	int remove_record(std::string to_remove);
	virtual int report();
private:
	int remove_record(std::string to_remove, Record*& head);
	void destroy(Record*& head);
	Record * head;
	std::string name;		//25 characters
	std::string address;	//25 characters
	std::string city;		//14 characters
	std::string state;		//2 characters
	int zip;				//5 characters
};

// Provider class derived from Person
class Provider : public Person {
public:
	Provider();
	~Provider();
	int report();
protected:
};

// Member class derived from Person
class Member : public Person {
public:
	Member();
	~Member();
	int report();
private:
	Account member_account;
};

