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

	int terminal_rc;

	std::cout << "What terminal would you like to access?\n\n";

	do {
		/*
		std::cout << "a) Provider Terminal\n";
		std::cout << "b) Manager Terminal\n";
		std::cout << "c) Operator Terminal\n";
		std::cout << "d) Display Read in Data\n";
		
		std::cin >> option;
		option = tolower(option);
		*/
		terminal_rc = sign_in_prompt();

		//Provider Terminal
		if (terminal_rc == 1) {
			do {
				std::cout << "=======================\n";
				std::cout << "== Welcome to ChocAn ==\n";
				std::cout << "=======================\n\n";


				std::cout << "a) Validate Member\n";
				std::cout << "b) Bill Member\n";
				std::cout << "c) Display Services\n";
				std::cout << "x) Logout\n";

				std::cin >> option;
				option = tolower(option);

				//Validate member
				if (option == 'a') {

				}

				//Bill member
				if (option == 'b') {

				}

				//display Services
				if (option == 'c') {

				}

			} while (option != 'x');
		}

		//Manager Terminal
		if (terminal_rc == 2) {
			do {

				std::cout << "a) Member Report\n";
				std::cout << "b) Provider Report\n";
				std::cout << "x) Logout\n";

				std::cin >> option;
				option = tolower(option);

				//Member Report
				if (option == 'a') {

				}

				//Provider Report
				if (option == 'b') {

				}

			} while (option != 'x');
		}

		//Operator Terminal
		if (terminal_rc == 3) {
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
				option = tolower(option);

				//Add Member
				if (option == 'a') {

				}

				//Remove Member
				if (option == 'b') {

				}

				//Edit Member
				if (option == 'c') {

				}

				//Add Provider
				if (option == 'd') {

				}

				//Remove Provider
				if (option == 'e') {

				}

				//Edit Provider
				if (option == 'f') {

				}

				//Add Service
				if (option == 'g') {

				}

				//Remove Service
				if (option == 'h') {

				}

				//Edit Service
				if (option == 'i') {

				}

			} while (option != 'x');
		}

		//dispay read in data from text file
		if (terminal_rc == 4) {

		}


		std::cout << "Access another terminal? (y/n) \n";
		std::cin >> again;
		again = tolower(again);
	} while (again == 'y');



/*
	if(sign_in_prompt() == RETURN_FAILURE)
		std::cout << "ERROR SIGNING IN.\n";

	std::cin.get();
	return RETURN_SUCCESS;
	*/
	return 0;
}
