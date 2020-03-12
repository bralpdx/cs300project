// This file contains the class definitions of the user
// and service classes.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//Abstract Base Class
class Record{
public:
	Record();
	~Record();
	Record *& go_next();
	int get_file_address(std::string& copy);
	void set_next(Record*& ptr);
	int add(std::string address);
	int remove(std::string address);
	private:
	std::string file_address;
	Record * next;
};

//Provider record derived from Record
class Provider_record : public Record {
public: 
	Provider_record();
	~Provider_record();
protected:
	std::string memberName;
	std::string memberNum;
	std::string svcCode;
	int feeOwed_dollars;    //Using two ints is more exact than float
	int feeOwed_cents;
	std::string currDate;	//MM-DD-YYYY
	std::string currTime;	//HH:MM:SS
	std::string svcDate;	//MM-DD-YYYY
};

//Member record derived from Records
class Member_record : public Record {
public: 
	Member_record();
	~Member_record();
protected:
	std::string name;
	std::string number;
	std::string address;
	std::string city;
	std::string state;
	int zip;
	std::string currDate;	//MM-DD-YYYY
	std::string currTime;	//HH:MM:SS
	std::string svcDate;	//MM-DD-YYYY
};

// Abstract Base Class (ID numbers)
class ID{
public:
	ID();
	virtual ~ID();
	ID *& go_left();
	ID *& go_right();
	bool is_leaf();
  std::string get_hash();
  virtual void Display();
  virtual void Edit(class Provider&);
  virtual void Edit(class Member&);
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
  Service(Service & to_copy);
protected:
	std::string svcName;
	int svcFee_dollars;
	int svcFee_cents;
};

// Person class derived from ID
class Person : public ID {
public:
	Person();
	~Person();
	int add_record(Record *&to_add);
	int remove_record(std::string to_remove);
protected:
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
  Provider(ID *& to_copy);
  Provider(Provider & to_copy);
  void Insert(std::string name, std::string address, std::string city, std::string state, int zip, std::string hash_value);
  void Display();
protected:
  void Edit(Provider&);

};

// Member class derived from Person
class Member : public Person {
public:
	Member();
	~Member();
  Member(ID *& to_copy);
  Member(Member & to_copy);
  void Insert(std::string name, std::string address, std::string city, std::string state, int zip, std::string hash_value); 
  void Display();


protected:
  void Edit(Member&);
};
