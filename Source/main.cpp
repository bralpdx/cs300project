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
		option = tolower(option);
		
		//Provider Terminal
		if (option == 'a') {
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
					//need this to be a function, trying to figure out where.
					time_t now = time(0);
					struct tm* timeinfo;
					std::string dt = ctime(&now);
					timeinfo = localtime(&now);
					char time[9];

					char today[11];

					if (timeinfo->tm_mon < 9) today[0] = '0';
					else today[0] = '1';

					char mon = timeinfo->tm_mon + 49;

					today[1] = mon;
					today[2] = '-';
					today[3] = dt[8];
					today[4] = dt[9];
					today[5] = '-';
					today[6] = dt[20];
					today[7] = dt[21];
					today[8] = dt[22];
					today[9] = dt[23];
					today[10] = '\0';

					for (int i = 0; i < 9; ++i) {
						time[i] = dt[i + 11];
					}
					time[8] = '\0';
			

				}

				//display Services
				if (option == 'c') {

				}

			} while (option != 'x');
		}

		//Manager Terminal
		if (option == 'b') {
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

			} while (option != 'x');
		}

		//dispay read in data from text file
		if (option == 'd') {

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