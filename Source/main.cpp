#include "param.h"
#include "utilities.h"
#include "bst.h"
#include <iostream>
#include <Windows.h>

int main() {
	
	pre_hash_id(); // See utilities.h for desc. creates user_info.txt
	/*
	BST service_bst("svc_codes.txt", 3);
	BST provider_bst("user_info.txt", 1);
	BST member_bst("", 2);
	*/

	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);

	std::cout << "my directory is " << NPath << "\n";
	std::string Sfilename = NPath;
	std::string Pfilename = NPath;
	std::string service_file = "\\svc-codes.txt";

	Sfilename.append(service_file);

	BST service_bst(Sfilename, 3);
	Member member_add;
	Provider provider_add;
	Service service_add;
	//service_bst.Display();
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

		//Enter ID number
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
					//if(sign_in_prompt(member_bst) < 0)
					//	std::cout << "Member ID Invalid\n";
				}


				//Bill member
				if (option == 'b') {
					//need this to be a function, trying to figure out where.
					char input_member_num[20];
					std::cout << "What member would you like to bill?\n";

					std::cin.get(input_member_num, 20, '\n');
					std::cin.clear();
					std::cin.ignore(20, '\n');
									 
				}
			

				//display Services
				if (option == 'c') {
					service_bst.print_alpha();
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
				std::cout << "x) logout\n";

				std::cin >> option;
				option = tolower(option);

				//Add Member
				if (option == 'a') {
					member_add.Read();
					//member_bst.AddToBST(member_add);

				}

				//Remove Member
				if (option == 'b') {

				}

				//Edit Member
				if (option == 'c') {

				}

				//Add Provider
				if (option == 'd') {
					provider_add.Read();
					//provider_bst.AddToBST(provider_add);

				}

				//Remove Provider
				if (option == 'e') {

				}

				//Edit Provider
				if (option == 'f') {

				}

				//Add Service
				if (option == 'g') {
					service_add.SvcRead();
					//service_bst.AddToBST(service_add);

				}

				//Remove Service
				if (option == 'h') {

				}

			} while (option != 'x');
		}

		//dispay read in data from text file
		if (terminal_rc == 4) {
			//service_bst.Display();
		}


		std::cout << "Access another terminal? (y/n) \n";
		std::cin >> again;
		again = tolower(again);
	} while (again == 'y' || terminal_rc == RETURN_FAILURE);

	return 0;
}
