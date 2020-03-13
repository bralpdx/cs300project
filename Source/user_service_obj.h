// This file contains the class definitions of the user
// and service classes.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/stat.h>

//Abstract Base Class
class Record{
public:
	Record();
	Record(const Record & obj);
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
	void svcFee();
	void get_balance(int& dol, int& cen);
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
	ID(const ID & obj);
	virtual ~ID();
	ID *& go_left();
	ID *& go_right();
	int compare(std::string to_compare);
	bool is_leaf();
	std::string get_hash();
	virtual void Display();
	virtual void Edit(class Provider&);
	virtual void Edit(class Member&);
	virtual bool good_standing();

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
	Service(const Service & obj);
	~Service();
    Service(Service & to_copy);
	void SvcRead();
	int get_service(std::string& to_copy);
	int get_num(int & to_copy);
protected:
	std::string svcName;
	std::string svcProvider;
	int service_num;
	Account service_fee;
};

// Person class derived from ID
class Person : public ID {
public:
	Person();
	Person(const Person & obj);
	~Person();
	int add_record(Record *& to_add);
	int remove_record(std::string to_remove);
	int get_name(std::string & to_copy);
	virtual int report();
	virtual void Read();
protected:
	int num_records();
	int get_filenames(char ** array);
private:
	int num_records(Record * head);
	int get_filenames(Record* head, char** array, int i);
	int remove_record(std::string to_remove, Record*& head);
	void destroy(Record*& head);
	Record * head;
protected:
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
	Provider(const Provider& obj);
	~Provider();
    Provider(ID *& to_copy);
  	Provider(Provider & to_copy);
  	void Insert(std::string name, std::string address, std::string city, std::string state, int zip, std::string hash_value);
  	void Display();
	int report();
	void Read();
	void Edit(Provider&);
protected:
	int provider_number;
};

// Member class derived from Person
class Member : public Person {
public:
	Member();
	Member(const Member& obj);
	~Member();
    Member(ID *& to_copy);
    Member(Member & to_copy);
    void Insert(std::string name, std::string address, std::string city, std::string state, int zip, std::string hash_value); 
    void Display();
    int report();
    bool good_standing();
	void Read();
	int Write_report(std::string filename, Provider& obj1, Service & obj2);
protected:
    void Edit(Member&);

private:
	Account member_account;
	int member_number;			//9-digit
};