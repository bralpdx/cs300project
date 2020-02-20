#include <iostream>
// #include <string>
#include "utilities.h"
#include "param.h"
#include "hash-library-master/sha256.h"


// Prompts the user to enter their ID number
int sign_in_prompt() {
	std::string id = "";

	std::cout << "Enter ID: ";

	// Checks for valid input
	while (!(std::cin >> id) || id.size() != ID_SIZE) {
		std::cout << "Error: Incorrect value entered. Use only numerical digits.\n";
		std::cin.clear();
		std::cin.ignore(MAX_CHAR, '\n');
		std::cout << "Enter ID: ";
	}
	if (id.size() != ID_SIZE)
		return RETURN_FAILURE;

	// Will search file for hashedID match
	search_id(id);

	system("pause");
	return RETURN_SUCCESS;
}

// Hashes and searches file for ID number match
int search_id(std::string id) {
	SHA256 hash;
	std::string hashedID = "";
	std::string dec_hash = "";

	hashedID = hash(id);
	std::cout << "You entered (before hash): " << id << std::endl;
	std::cout << "After hash: " << hashedID << std::endl;

	return RETURN_SUCCESS;
}