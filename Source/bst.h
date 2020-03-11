// File contains prototypes pertaining to the Binary Search Tree

#include "user_service_obj.h"
#pragma once

class BST{
public:
	BST();
	BST(const char * file, int flag);
	~BST();
	int add(ID *)
private:
	void destroy(ID*& root);
	ID * root;
};