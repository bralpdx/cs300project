#include <iostream>
#include <string>
#include "utilities.h"
#include "param.h"


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

	return RETURN_SUCCESS;
}