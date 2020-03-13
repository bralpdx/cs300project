// File contains prototypes pertaining to the Binary Search Tree

#include "user_service_obj.h"
#pragma once

class BST{
public:
	BST();
	BST(const char * file, int flag);
	~BST();
  
  //bool AddToBST(ID *& to_add);
  bool AddToBST(Provider & to_add);
  bool AddToBST(Member & to_add);
  void Display();
  int CountRight();
private:
  int CountRight(ID* root);
  void Display(ID * root);
	void destroy(ID*& root);
  bool AddToBST(ID *& root, Provider & to_add);
  bool AddToBST(ID *& root, Member & to_add);
  //bool AddToBST(ID *& root, ID *& to_add);
  

	ID * root;
};
