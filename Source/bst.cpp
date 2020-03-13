#include "bst.h"
#include <fstream>

//////////////////////////////////
//      BST Class				//
//////////////////////////////////
BST::BST() {
  root = NULL;
}


/* = = = = = = = = = = = = = = = = = = = = = = */
//              AddToBST Function
//
//INPUT:  Provider object
//
//OUTPUT: Returns True/False for success/failure.
//
//DESC: Pass a provider object by reference when calling
//      this public function. It will first check if root 
//      is null, if so it well create the root.
//      If not null then check to see if the root
//      is a Provider object, if so then call the
//      recursive function (below this one) to
//      add it to the appropriate location.
//      If root is not a Provider object it will return false.
//
bool BST::AddToBST(Provider & to_add){                          
  if(root == NULL){
    this->root = new Provider(to_add);
    return true;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Provider*>(this->root);
    if(temp){
      return AddToBST(this->root, to_add); // recursive function below this one
    }
    return false;
  }
}


/* = = = = = = = = = = = = = = = = = = = = = = */
//              AddToBST Function
//
//INPUT:  ID by pointer reference (root) and
//        a provider object by reference.
//
//OUTPUT: Returns true/false for success/failure.
//
//DESC: This function is private and called in the above
//      public function. This is for adding a Provider
//      object into a tree filled with Provider objects.
//      It will recursively find a NULL root and add there.
//      Sorted by the hash value of each Provider object.
//
bool BST::AddToBST(ID *& root, Provider & to_add){
  if(root == NULL){
    root = new Provider(to_add);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_add.ID::get_hash()){
      return AddToBST(root->go_left(), to_add);
    }
    else{
      return AddToBST(root->go_right(), to_add);
    }
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              AddToBST Function
//
//INPUT: Member object by reference.
//
//OUTPUT: Returnss true/false for success/failure.
//
//DESC: This function is a public function.
//      It does the same thing as the above
//      wrapper function and calls its own
//      appopriate recursive function below this one.
//      The only difference is that it is for
//      Member objects and Member object trees.
//
bool BST::AddToBST(Member & to_add){                          
  if(root == NULL){
    this->root = new Member(to_add);
    return true;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Member*>(this->root);
    if(temp){
      return AddToBST(this->root, to_add);
    }
    return false;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              AddToBST Function
//
//INPUT: ID object pointer by reference (root) and
//       a Member object by reference.
//
//OUTPUT: Returns true/false for success failure.
//
//DESC: This is a private function.
//      It does the same as the above private
//      recursive function, this time for Member Objects.
//
//
bool BST::AddToBST(ID *& root, Member & to_add){          
  if(root == NULL){
    root = new Member(to_add);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_add.ID::get_hash()){
      return AddToBST(root->go_left(), to_add);
    }
    else{
      return AddToBST(root->go_right(), to_add);
    }
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              AddToBST Function
//
//INPUT: Service object by reference.
//
//OUTPUT: True/False.
//
//DESC: Public function, see above.
//      Service object edition.
//
//
bool BST::AddToBST(Service & to_add){                          
  if(root == NULL){
    this->root = new Service(to_add);
    return true;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Service*>(this->root);
    if(temp){
      return AddToBST(this->root, to_add);
    }
    return false;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              AddToBST Function
//
//INPUT: ID object by pointer reference (root) and
//       a Service object by reference.
//
//OUTPUT: Returns true/false.
//
//DESC: Private recursive function, see everything above.
//      This time for Service Objects.
//
bool BST::AddToBST(ID *& root, Service & to_add){
  if(root == NULL){
    root = new Service(to_add);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_add.ID::get_hash()){
      return AddToBST(root->go_left(), to_add);
    }
    else{
      return AddToBST(root->go_right(), to_add);
    }
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              EditBST Function
//
//INPUT: Provider object by reference.
//
//OUTPUT: Returns true/false for success/failure.
//
//DESC: Public function for editing a Provider inside
//      a provider tree. This is the wrapper function.
//      Dynamic Casting used to verify that it is a
//      tree of providers that is calling this function.
//      Below this function is the private recursive function.
//
bool BST::EditBST(Provider & to_edit){
  if(root == NULL){
    return false;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Provider*>(this->root);
    if(temp){
      return EditBST(this->root, to_edit);
    }
    return false;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              EditBST Function
//
//INPUT: ID pointer by reference (root) and
//       Provider object by reference.
//
//OUTPUT: Returns true/false for success/failuer.
//
//DESC: Private recursive function called in above function.
//      searches for the correct Provider data based on 
//      a matching ID hash_value. Then will call the
//      appropriate edit function to edit the data.
//
//
bool BST::EditBST(ID *& root, Provider & to_edit){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_edit.ID::get_hash()){
    ID * temp;
    temp = dynamic_cast<Provider*>(root);
    root->Edit(to_edit);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_edit.ID::get_hash()){
      return EditBST(root->go_left(), to_edit);
    }
    else{
      return EditBST(root->go_right(), to_edit);
    }
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            EditBST Function
//
//INPUT: Member object by reference.
//
//OUTPUT: Returns True/false for success/failure.
//
//DESC: Public wrapper function for changint something
//      that exists in the tree. The dynamic_cast is to
//      verify that the tree is made up of member objects.
//      The wrapper will then call the Recursive Edit below.
//
//
bool BST::EditBST(Member & to_edit){
  if(root == NULL){
    return false;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Member*>(this->root);
    if(temp){
      return EditBST(this->root, to_edit);
    }
    return false;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            EditBST Function
//
//INPUT: ID pointer by reference (root) and
//       a Member object by reference.
//
//OUTPUT: Returns true/false on success/failure.
//
//DESCR: Private recursive function. Called by above function.
//       Recursively searches for the correct node to edit
//       Search condition is based on the to_edit hash_value.
//
//
bool BST::EditBST(ID *& root, Member & to_edit){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_edit.ID::get_hash()){
    root->Edit(to_edit);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_edit.ID::get_hash()){
      return EditBST(root->go_left(), to_edit);
    }
    else{
      return EditBST(root->go_right(), to_edit);
    }
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            RemoveFromBST Function
//
//INPUT: Provider object by reference.
//
//OUTPUT: Returns true/false for success/failuer.
//
//DESC: Public wrapper function. Verifies that the 
//      Data desired to be removed is from the appropriate
//      tree. Then calls the below recursive private function.
//
//
bool BST::RemoveFromBST(Provider & to_remove){
  if(root == NULL){
    return false;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Provider*>(this->root);
    if(temp){
      return RemoveFromBST(this->root, to_remove);
    }
    return false;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            RemoveFromBST Function
//
//INPUT: ID pointer by reference (root) and a
//       Provider object by reference.
//
//OUTPUT: Returns true/false for success/failure.
//
//DESC: Private recursive function called in the above function.
//      Searches for a matching hash_value in both the to_remove
//      and the root's data. Recursively searches
//
//
bool BST::RemoveFromBST(ID *& root, Provider & to_remove){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_remove.ID::get_hash()){
  }
  else{
    if(root->ID::get_hash() > to_remove.ID::get_hash()){
      return RemoveFromBST(root->go_left(), to_remove);
    }
    return RemoveFromBST(root->go_right(), to_remove);
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//          RemoveFromBST Function
//
//INPUT: Member object by reference.
//
//OUTPUT: Returns true/false for success/failure.
//
//DESC: Public wrapper function. Verifies that the
//      Data desired to be removed is from the appropriate
//      tree of data. Then calls the below recursive private function.
//
bool BST::RemoveFromBST(Member & to_remove){
  if(root == NULL){
    return false;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Member*>(this->root);
    if(temp){
      return RemoveFromBST(this->root, to_remove);
    }
    return false;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            RemoveFromBST Function
//
//INPUT: ID pointer by reference (root) and
//       Member object by reference.
//
//OUTPUT: Returns true/false for success/failure.
//
//DESC: Private Recursive function called in the above function.
//
//
bool BST::RemoveFromBST(ID *& root, Member &  to_remove){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_remove.ID::get_hash()){
    
  }
  else{
    if(root->ID::get_hash() > to_remove.ID::get_hash()){
      return RemoveFromBST(root->go_left(), to_remove);
    }
    return RemoveFromBST(root->go_right(), to_remove);
  }
}



/* ========================================================================== */
//      TEST FUNCTIONS BELOW EITHER IGNORE OR WE COULD ADD THEM
void BST::Display(){
  return Display(root);
}
void BST::Display(ID * root){
  if(root == NULL){
    return;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Provider*>(root);
    if(temp){
      temp->Display();
    }
    temp = dynamic_cast<Member*>(root);
    if(temp){
      temp->Display();
    }
    Display(root->go_left());
    Display(root->go_right());
  }
}

int BST::CountRight(){
  if(root == NULL){
    return 0;
  }
  else{
    return CountRight(this->root->go_right());
  }
}

int BST::CountRight(ID * root){
  if(root == NULL){
    return 0;
  }
  else{
    return 1 + CountRight(root->go_right());
  }
	root = NULL;
}

BST::BST(const char * file, int flag) {
	root = NULL;

	std::ifstream file_in;
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
			/*

			Didn't meen to work on this in main, 
			will carry on in my branch

			std::string temp;
			file_in.get(temp, 100, ',');
			file_in.ignore(100, ',');*/
		} while (!file_in.eof());
	}
}

BST::~BST() {
	destroy(root);
	root = NULL;
}

void BST::destroy(ID *& root) {
	if (!root) return;
	destroy(root->go_left());
	destroy(root->go_right());
	if (root->is_leaf()){
		delete root;
		root = NULL;
	}
	return;
}
