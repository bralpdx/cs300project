#include <iostream>
#include "utilities.h"
#include "param.h"
#include "hash-library-master/sha256.h"
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
	std::cout << "[2] Manager\n";
	std::cout << "[3] Operator\n";
	std::cout << "[4] Display Read in Data\n";
	std::cout << "Enter: ";
	while (!(std::cin >> select) || select <= 0 || select > 4) {
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
		return 1;
	}
	else if (select == 2) {
		// Manager
		return 2;
	}
	else if (select == 3) {
		// Operator
		return 3;
	}
	else if (select == 4) {
		// Display read in data
		return 4;
	}
	else
		return RETURN_FAILURE;
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

// Function to read in the time from the operator terminal
// Bound checks for length and formatting (:)
int get_time(std::string& time){
    std::cout << "Enter the current time (HH:MM:SS): ";
    std::cin >> time;

    if(time.at(2) == ':' && time.at(5) == ':' && time.length() == 8)
        return 1;
    else
        return 0;
}

// Function to read in the date from the operator terminal
// Bound checks for  length and formatting (-)
int get_date(std::string& date){
    std::cout << "Date (DD-MM-YYYY): ";
    std::cin >> date;

    if(date.at(2) == '-' && date.at(5) == '-' && date.length() == 10)
        return 1;
    else
        return 0;
}