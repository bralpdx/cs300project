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
  
  bool CopyFromBST(std::string & to_find, Provider & copy_to);
  bool CopyFromBST(std::string & to_find, Member & copy_to);
  bool CopyFromBST(std::string & to_find, Service & copy_to);

  int print_alpha();
  int CountTree();
  int VerifyFromBST(std::string id, int type);
  void Display(); // displays everything
  bool Search(ID & to_search); // search for a specific hash value in the tree

private:

  int CountTree(ID* root); // counts all data on the right 

  int quick_sort(Service*& array, int lo, int hi);

  void Display(ID * root); // recursive display all
	void destroy(ID*& root); // called in the destructor; destroys all
  bool Search(ID * root, ID & to_search);

  bool AddToBST(ID *& root, Provider & to_add); // recursive private function; for add
  bool AddToBST(ID *& root, Member & to_add); // recursive private function; for add
  bool AddToBST(ID *& root, Service & to_add); // recursive private function; for add

  bool EditBST(ID *& root, Provider & to_edit); // recursive private function; for edit
  bool EditBST(ID *& root, Member & to_edit); // recursive private function; for edit
  
  bool RemoveFromBST(ID *& root, Provider & to_remove);
  bool RemoveFromBST(ID *& root, Member & to_remove);


  bool CopyFromBST(ID * root, std::string & to_find, Provider & copy_to);
  bool CopyFromBST(ID * root, std::string & to_find, Member & copy_to);
  bool CopyFromBST(ID * root, std::string & to_find, Service & copy_to);

  bool FindInOrderSuccessor(ID *& root, ID *& to_get); // called in the removal function.


  int VerifyFromBST(ID * root, std::string id, int type);

	ID * root;
};
