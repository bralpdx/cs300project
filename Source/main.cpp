#include "param.h"
#include "utilities.h"
#include "bst.h"
#include <iostream>

int main() {
	pre_hash_id(); // See utilities.h for desc
	BST service_bst("svc_codes.txt", 3);
	BST provider_bst("user_info.txt", 1);
	BST member_bst("", 2);

	char again;
	char option;

	std::cout << "What terminal would you like to access?\n\n";

	do {
		std::cout << "a) Provider Terminal\n";
		std::cout << "b) Manager Terminal\n";
		std::cout << "c) Operator Terminal\n";
		std::cout << "d) Display Read in Data\n";

		std::cin >> option;
		tolower(option);
		
		//Provider Terminal
		if (option == 'a') {
			do{
				std::cout << "=======================\n";
				std::cout << "== Welcome to ChocAn ==\n";
				std::cout << "=======================\n\n";


				std::cout << "a) Validate Member\n";
				std::cout << "b) Bill Member\n";
				std::cout << "c) Display Services\n";
				std::cout << "x) Logout\n";

				std::cin >> option;
				tolower(option);

				if (option == 'a') {

				}

				if (option == 'b') {

				}

				if (option == 'c') {

				}

			while (option != 'x');
		}

		//Manager Terminal
		if (option == 'b') {
			do {

				std::cout << "a) Member Report\n";
				std::cout << "b) Provider Report\n";
				std::cout << "x) Logout\n";

				std::cin >> option;
				tolower(option);

				if (option == 'a') {

				}

				if (option == 'b') {

				}

				if (option == 'c') {

				}

			while (option != 'x');
		}

		//Operator Terminal
		if (option == 'c') {
			do {
				std::cout << "a) Add Member\n";
				std::cout << "b) Remove Member\n";
				std::cout << "c) Edit Member\n";
				std::cout << "d) Add Provider\n";
				std::cout << "e) Remove Provider\n";
				std::cout << "f) Edit Provider\n";
				std::cout << "g) Add Service\n";
				std::cout << "h) Remove Service\n";
				std::cout << "i) Edit Service\n";
				std::cout << "x) logout\n";

				std::cin >> option;
				tolower(option);

				if (option == 'a') {

				}

				if (option == 'b') {

				}

				if (option == 'c') {

				}

				if (option == 'd') {

				}

				if (option == 'e') {

				}

				if (option == 'f') {

				}

				if (option == 'g') {

				}

				if (option == 'h') {

				}

				if (option == 'i') {

				}

			while (option != 'x');
		}

		//dispay read in data from text file
		if (option == 'd') {

		}

		std::cout << "Access another terminal? (y/n) \n";
		std::cin >> again;
		tolower(again);
	} while (again == 'y');



/*
	if(sign_in_prompt() == RETURN_FAILURE)
		std::cout << "ERROR SIGNING IN.\n";

	std::cin.get();
	return RETURN_SUCCESS;
	*/
	return 0;
}