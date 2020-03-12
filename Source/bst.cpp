#include "bst.h"
#include <string>
#include <fstream>

//////////////////////////////////
//      BST Class				//
//////////////////////////////////
BST::BST() {
	root = NULL;
}

BST::BST(const char * file, int flag) {
	
	root = NULL;

	std::ifstream file_in;
	file_in.open(file);

	//File didn't open
	if (!file_in) flag = 50;

	//File is a Provider file
	if (flag == 1) {
		std::string hashedId;
		std::string name;
		std::string street;
		std::string city;
		std::string state;
		std::string zip;
		std::string type;

		while (getline(file_in, hashedId, ',')) {
			getline(file_in, name, ',');
			getline(file_in, street, ',');
			getline(file_in, city, ',');
			getline(file_in, state, ',');
			getline(file_in, zip, ',');
			getline(file_in, type);

			if (type.compare("Provider") == 0) {
				// create provider object
				// pass in variable data
				// add to provider bst
			}
			else if (type.compare("Member") == 0) {
				// create member object
				// pass in variable data
				// add to member bst
			}
		}
	}

	/*
	//File is a Member file
	if (flag == 2) {
		do {

		} while (!file_in.eof());
	}
	*/

	//File is a Service file
	if (flag == 3) {
		std::string svc_code;
		std::string dollars;
		std::string cents;
		std::string name;
		std::string type;

		while (getline(file_in, svc_code, ',')) {
			getline(file_in, dollars, '.');
			getline(file_in, cents, ',');
			getline(file_in, name, ',');
			getline(file_in, type);

			// create service object
			// pass in variable data
			// add to service bst
		}
	}

	file_in.close();
}

BST::~BST() {
	destroy(root);
	root = NULL;
}

void BST::destroy(ID*& root) {
	if (!root) return;
	destroy(root->go_left());
	destroy(root->go_right());
	if (root->is_leaf()){
		delete root;
		root = NULL;
	}
	return;
}
