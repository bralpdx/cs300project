#include "bst.h"

//////////////////////////////////
//      BST Class				//
//////////////////////////////////
BST::BST() {
	root = NULL;
}

BST::~BST() {

	//Need to Deallocate Tree
	if(root)
		root = NULL;
}
