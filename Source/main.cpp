#include "param.h"
#include "utilities.h"
#include <iostream>

int main() {
	std::cout << "=======================\n"; 
	std::cout << "== Welcome to ChocAn ==\n";
	std::cout << "=======================\n";

	if(sign_in_prompt() == RETURN_FAILURE)
		std::cout << "ERROR SIGNING IN.\n";

	std::cin.get();
	return RETURN_SUCCESS;
}