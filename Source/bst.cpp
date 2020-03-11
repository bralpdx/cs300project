#include "bst.h"
#include <fstream>

//////////////////////////////////
//      BST Class				//
//////////////////////////////////
BST::BST() {
	root = NULL;
}

BST::BST(const char * file, int flag) {
	root = NULL;

	ifstream file_in;
	file_in.open(file);

	//File didn't open
	if (!file_in) flag = 50;

	//File is a Provider file
	if (flag == 1) {
		do {

		} while (!file_in.eof());
	}

	//File is a Member file
	if (flag == 2) {
		do {

		} while (!file_in.eof());
	}

	//File is a Service file
	if (flag == 3) {
		do {

		} while (!file_in.eof());
	}
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
	return;
}
