#include <iostream>
#include "utilities.h"
#include "param.h"
#include "hash-library-master\sha256.h"
#include <fstream>


// Prompts the user to enter their ID number
// Will accept BST as arg, and call bst search function w/id
int sign_in_prompt() {
	std::string id = "";
	std::string hashedID = "";
	int select = 0;
	SHA256 hash;

	std::cout << "Select login type\n";
	std::cout << "-----------------\n";
	std::cout << "[1] Provider\n";
	std::cout << "[2] Member\n";
	std::cout << "[3] Manager\n";
	std::cout << "Enter: ";
	while (!(std::cin >> select) || select <= 0 || select > 3) {
		std::cout << "Invalid input.\n";
		std::cout << "Enter: ";
		std::cin.clear();
		std::cin.ignore(MAX_CHAR, '\n');
	}

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

	// Will search tree for hashedID match
	hashedID = hash(id);
	// call tree
	if (select == 1) {
		// Provider tree
	}
	else if (select == 2) {
		// Member tree
	}
	else if (select == 3) {
		// Manager
	}
	else
		return RETURN_FAILURE;

	system("pause");
	return RETURN_SUCCESS;
}

// Opens pre-hashed file, and passes it to be hashed.
int pre_hash_id() {
	std::ifstream fileIn;

	fileIn.open("Source/access-codes.txt");

	if (!fileIn) {
		std::cout << "Error: File not found.\n";
		return RETURN_FAILURE;
	}

	hash_file(fileIn);
	fileIn.close();

	return RETURN_SUCCESS;
}

// Function to read data from text file and create secure hashed file.
// Reads user info and hashes it then writes it to a new file.
int hash_file(std::ifstream &inFile) {
	SHA256 hash;
	std::string id;
	std::string name;
	std::string street;
	std::string city;
	std::string state;
	std::string zip;
	std::string type;

	std::ofstream oFile("Source/user_info.txt");

	if (!inFile) {
		std::cout << "Error: File not found.\n";
		return RETURN_FAILURE;
	}
	while (getline(inFile, id, ',')) {
		getline(inFile, name, ',');
		getline(inFile, street, ',');
		getline(inFile, city, ',');
		getline(inFile, state, ',');
		getline(inFile, zip, ',');
		getline(inFile, type);

		oFile << hash(id) << "," << name << ",";
		oFile << street << "," << city << ",";
		oFile << state << "," << zip << ",";
		oFile << type << std::endl;
	}

	oFile.close();

	return RETURN_SUCCESS;
}