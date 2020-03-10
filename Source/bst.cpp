#include "bst.h"

//////////////////////////////////
//      BST Class				//
//////////////////////////////////
BST::BST() {
	root = NULL;
}

BST::BST(std::string file, int flag) {
	root = NULL;

	if (flag == 1) {


	}

	if (flag == 2) {


	}

	if (flag == 3) {


	}
}

BST::~BST() {

	//Need to Deallocate Tree
	if(root)
		root = NULL;
}

void BST::destroy(ID*& root) {
	if (!root) return;
	destroy(root->go_left());
	destroy(root->go_right());
	if (root->is_leaf()) delete root;
	return;
}
