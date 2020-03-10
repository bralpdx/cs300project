#include <iostream>
#include "utilities.h"
#include "param.h"
#include "hash-library-master\sha256.h"
#include <fstream>


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
	//pre_hash_id(id);

	system("pause");
	return RETURN_SUCCESS;
}

// Opens pre-hashed file, and passes it to be hashed.
int pre_hash_id() {
	SHA256 hash;
	std::ifstream fileIn;
	//std::string hashedID = "";
	fileIn.open("Source/access-codes.txt");

	if (!fileIn) {
		std::cout << "Error: File not found.\n";
		return RETURN_FAILURE;
	}

	//hashedID = hash(id);
	//std::cout << "You entered (before hash): " << id << std::endl;
	//std::cout << "After hash: " << hashedID << std::endl;

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

		//inFile.ignore(MAX_CHAR, '\n');
	}

	oFile.close();

	return RETURN_SUCCESS;
}