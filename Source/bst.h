// File contains prototypes pertaining to the Binary Search Tree

#include "user_service_obj.h"
#include <fstream>
#pragma once

class BST{
public:
	BST();
	BST(const char * file, int flag);
	~BST();
  
  bool AddToBST(Provider & to_add); // add a Provider to the tree; root must be provider obj
  bool AddToBST(Member & to_add); // add a Member to the tree; root must be member obj
  bool AddToBST(Service & to_add); // add a service to the tree; root must be service obj

  bool EditBST(Provider & to_edit); // edit a provider in the tree; root must be provider obj
  bool EditBST(Member & to_edit); // edit a member in the tree; root must be member obj

  bool RemoveFromBST(Provider & to_remove);
  bool RemoveFromBST(Member & to_remove);

  void Display(); // displays everything
  int CountRight();

private:

  int CountRight(ID* root); // counts all data on the right
  void Display(ID * root); // recursive display all
	void destroy(ID*& root); // called in the destructor; destroys all

  bool AddToBST(ID *& root, Provider & to_add); // recursive private function; for add
  bool AddToBST(ID *& root, Member & to_add); // recursive private function; for add
  bool AddToBST(ID *& root, Service & to_add); // recursive private function; for add

  bool EditBST(ID *& root, Provider & to_edit); // recursive private function; for edit
  bool EditBST(ID *& root, Member & to_edit); // recursive private function; for edit
  
  bool RemoveFromBST(ID *& root, Provider & to_remove);
  bool RemoveFromBST(ID *& root, Member & to_remove);

	void destroy(ID*& root);
	ID * root;
};
