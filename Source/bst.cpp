#include "bst.h"

//////////////////////////////////
//      Provider_BST Class      //
//////////////////////////////////
Provider_BST::Provider_BST() {
	root = NULL;
}

Provider_BST::~Provider_BST() {

	//Need to Deallocate Tree
	if(root)
		root = NULL;
}

//////////////////////////////////
//      Member_BST Class        //
//////////////////////////////////
Member_BST::Member_BST() {
	root = NULL;
}

Member_BST::~Member_BST() {

	//Need to Deallocate Tree
	if(root)
		root = NULL;
}

//////////////////////////////////
//      Service_BST Class       //
//////////////////////////////////
Service_BST::Service_BST() {
	root = NULL;
}

Service_BST::~Service_BST() {

	//Need to Deallocate Tree
	if(root)
		root = NULL;
}