#pragma once

#include <string>

int sign_in_prompt();                  // Prompts user to enter their ID number
int pre_hash_id();        // Searches user_info.txt file for ID match
int hash_file(std::ifstream &inFile);  // Creates user_info.txt w/ hashed info

// *NOTE TO SELF
// Since using a hashing algorithm rather than encryption, store ID and name together in file.
// Then search another file for hashed name, with other information.
// Example: hashed id,Firstname Lastname (in file 1)
// hashed(firstname lastname),street,city,state,zip,type (in file 2)
// Either do this, or find an encryption algorithm that isn't terrible to use.