#pragma once

#include <string>

int sign_in_prompt();                  // Prompts user to enter their ID number
int pre_hash_id();					   // Opens access_codes.txt
int hash_file(std::ifstream &inFile);  // Creates user_info.txt w/ hashed info