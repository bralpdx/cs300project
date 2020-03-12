#pragma once

#include <string>

int sign_in_prompt();                  // Prompts user to enter their ID number
int pre_hash_id();					   // Opens access_codes.txt
int hash_file(std::ifstream &inFile);  // Creates user_info.txt w/ hashed info

//operator functions
int read_time(std::string& time);            // reads in time with proper formatting
int read_date(std::string& date);            // reads in date with proper formatting