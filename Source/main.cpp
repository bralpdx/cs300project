#include "param.h"
#include "utilities.h"
#include "bst.h"
#include <iostream>

int main() {
	pre_hash_id(); // See utilities.h for desc

	std::cout << "=======================\n"; 
	std::cout << "== Welcome to ChocAn ==\n";
	std::cout << "=======================\n";
	
	BST service_bst("svc_codes.txt",3);
	BST provider_bst("user_info.txt",1);
	BST member_bst("",2);

	if(sign_in_prompt() == RETURN_FAILURE)
		std::cout << "ERROR SIGNING IN.\n";

	std::cin.get();
	return RETURN_SUCCESS;
}