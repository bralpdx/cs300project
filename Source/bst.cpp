#include "bst.h"
#include <fstream>
#include <cstring>

//////////////////////////////////
//      BST Class				//
//////////////////////////////////


BST::BST() {
  root = NULL;
}


BST::BST(const BST & b) {
    root = NULL;
    //function to copy
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
    //ID * temp;
    //temp = dynamic_cast<Provider*>(root);
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
    //ID * temp;
    //temp = dynamic_cast<Member*>(this->root);
    //if(temp){
      return EditBST(this->root, to_edit);
    //}
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
    if(root->is_leaf() == true){// no children exist
      delete root;
      root = NULL;
      return true;
    }
    if(root->go_left() != NULL && root->go_right() != NULL){ // both children exist
      // child on the right becomes
      // the new current root
      // must assign old root's left child to 
      ID * TempIOS;
      if(FindInOrderSuccessor(root->go_right(), TempIOS) == false){
        std::cerr << "Something went very during Removal. Exiting Removal!!";
        return false;
      }
      else{
        root->Edit(((Provider&)*TempIOS));
        delete TempIOS;
        TempIOS = NULL;
        return true;
      }
    }

    if((root->go_left() != NULL) && (root->go_right() == NULL)){ // left child exists only
      ID * TempRoot = root;
      root = root->go_left();
      delete TempRoot;
      return true;
    }
    if((root->go_left() == NULL) &&  (root->go_right() != NULL)){ // right child exists only
      ID * TempRoot = root;
      root = root->go_right();
      delete TempRoot;
      return true;
    }
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
bool BST::RemoveFromBST(ID *& root, Member & to_remove){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_remove.ID::get_hash()){
    if(root->is_leaf() == true){// no children exist
      delete root;
      root = NULL;
      return true;
    }
    if(root->go_left() != NULL && root->go_right() != NULL){ // both children exist
      // child on the right becomes
      // the new current root
      // must assign old root's left child to 
      ID * TempIOS;
      if(FindInOrderSuccessor(root->go_right(), TempIOS) == false){
        std::cerr << "Something went very during Removal. Exiting Removal!!";
        return false;
      }
      else{
        root->Edit(((Member&)*TempIOS));
        delete TempIOS;
        TempIOS = NULL;
        return true;
      }
    }

    if((root->go_left() != NULL) && (root->go_right() == NULL)){ // left child exists only
      ID * TempRoot = root;
      root = root->go_left();
      delete TempRoot;
      return true;
    }
    if((root->go_left() == NULL) &&  (root->go_right() != NULL)){ // right child exists only
      ID * TempRoot = root;
      root = root->go_right();
      delete TempRoot;
      return true;
    }
  }
  else{
    if(root->ID::get_hash() > to_remove.ID::get_hash()){
      return RemoveFromBST(root->go_left(), to_remove);
    }
    return RemoveFromBST(root->go_right(), to_remove);
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//          VerifyFromBST Function
//
//INPUT: String id by value and int type by value
//
//OUTPUT: Returns int -- 1 if found and validated/ 0 if found and 
//        member suspended/ -1 if invalid number
//
//DESC: Public wrapper function. Verifies that an ID is present 
//      in the appropriate tree of data. Then calls the below recursive 
//      private function.
//
int BST::VerifyFromBST(std::string id, int type){
  if(root == NULL){
    return -1;
  }
  else{

    if(root){
      return VerifyFromBST(this->root, id, type);
    }
    return -1;
  }
}


/* = = = = = = = = = = = = = = = = = = = = = = */
//          VerifyFromBST Function
//
//INPUT: String id by value and int type by value
//
//OUTPUT: Returns int -- 1 if found and validated/ 0 if found and 
//        member suspended/ -1 if invalid number
//
//DESC: Private recursive function called in the above function. 
//      Verifies that an ID is present in the appropriate tree of data
//      by searching for a matching hash_value by comparing the root's
//      data and string id. Recursively searches. When found, int type 
//      is used to distinguish between a Provider and a Member. Members
//      will have their standing checked by calling a Member method that
//      returns a bool.
//      
//
int BST::VerifyFromBST(ID * root, std::string id, int type){
  //stopping condition
  if(!root)
      return -1;

  if(root->ID::get_hash() == id){
    if(type == 1)
      return 1;

    if(type == 2) {
      if(root->good_standing())
        return 1;
      else
        return 0;
    }
  }
  else{
    if(root->ID::get_hash() > id) 
      return VerifyFromBST(root->go_left(), id, type);
    else
      return VerifyFromBST(root->go_right(), id, type);
  }
}


/* = = = = = = = = = = = = = = = = = = = = = = */
//            FindInOrderSuccessor Function
//
//INPUT: ID pointer by reference (root)
//       A second ID pointer by reference, the In Order Successor.
//
//OUTPUT: Returns true/false for success/failure.
//
//DESC: This is a private function.
//      Called in the removal functions.
//      This function finds the In Order successor.
//
bool BST::FindInOrderSuccessor(ID *& root, ID *& to_grab){
  if(root == NULL){
    return false;
  }
  if(root->go_left() != NULL){
    return FindInOrderSuccessor(root->go_left(), to_grab);
  }
  if(root->go_left() == NULL && root->go_right() == NULL){
    to_grab = root;
    root = NULL;
    return true;
  }
  if(root->go_left() == NULL && root->go_right() != NULL){
    to_grab = root;
    root = root->go_right();
    return true;
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */                                         
//              CopyFromBST Function
//
//INPUT: a string contaning the ID number to find.
//       And an empty Provider object to copy the data into.
//
//OUTPUT: Returns True/False for Success/Failure.
//
//DESC:
//
//
bool BST::CopyFromBST(std::string& to_find, Provider & copy_to){
  if(this->root == NULL){
    return false;
  }
  ID * temp;
  temp = dynamic_cast<Provider*>(this->root);
  if(temp){
    return CopyFromBST(this->root, to_find, copy_to);
  }
  return false;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              CopyFromBST Function
//
//INPUT: ID pointer by value to traverse the tree (root),
//       A string containing the ID to find.
//       And an empty provider object to copy the data into.
//
//OUTPUT: Returns True/False for Success/Failure.
//
//DESC:
//
//
bool BST::CopyFromBST(ID * root, std::string& to_find, Provider & copy_to){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_find){// they match; copy data
    root->CopyData(copy_to);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_find){
      return CopyFromBST(root->go_left(), to_find, copy_to);
    }
    return CopyFromBST(root->go_right(), to_find, copy_to);
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            CopyFromBST Function
//
//INPUT: a string containing the ID number to find.
//       An empty member object to copy the data into.
//
//OUTPUT: Returns True/False for Success/Failure.
//
//DESC:
//
//
bool BST::CopyFromBST(std::string& to_find, Member & copy_to){
  if(this->root == NULL){
    return false;
  }
  ID * temp;
  temp = dynamic_cast<Member*>(this->root);
  if(temp){
    return CopyFromBST(this->root, to_find, copy_to);
  }
  return false;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            CopyFromBST Function
//
//INPUT: ID pointer by value to traverse the tree (root),
//       A string containing the ID to find.
//       And an empty Member object to copy the data into.
//
//OUTPUT: Returns True/False for Success/Failure.
//
//DESC:
//
//
bool BST::CopyFromBST(ID * root, std::string& to_find, Member & copy_to){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_find){
    root->CopyData(copy_to);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_find){
      return CopyFromBST(root->go_left(), to_find, copy_to);
    }
    return CopyFromBST(root->go_right(), to_find, copy_to);
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */                                         
//              CopyFromBST Function
//
//INPUT: a string contaning the ID number to find.
//       And an empty Service object to copy the data into.
//
//OUTPUT: Returns True/False for Success/Failure.
//
//DESC:
//
//
bool BST::CopyFromBST(std::string& to_find, Service & copy_to){
  if(this->root == NULL){
    return false;
  }
  ID * temp;
  temp = dynamic_cast<Service*>(this->root);
  if(temp){
    return CopyFromBST(this->root, to_find, copy_to);
  }
  return false;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              CopyFromBST Function
//
//INPUT: ID pointer by value to traverse the tree (root),
//       A string containing the ID to find.
//       And an empty Service object to copy the data into.
//
//OUTPUT: Returns True/False for Success/Failure.
//
//DESC:
//
//
bool BST::CopyFromBST(ID * root, std::string& to_find, Service & copy_to){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_find){// they match; copy data
    root->CopyData(copy_to);
    return true;
  }
  else{
    if(root->ID::get_hash() > to_find){
      return CopyFromBST(root->go_left(), to_find, copy_to);
    }
    return CopyFromBST(root->go_right(), to_find, copy_to);
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            Search Function
//
//INPUT: an ID pointer to search for
//
//OUTPUT: T/F for Success/failure
//
//DESC: Hasn't been used, might be useful.
//      This is the public wrapper
//
bool BST::Search(ID & to_search){
  if(root == NULL){
    return false;
  }
  else{
    return Search(root, to_search);
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//              Search function
//
//INPUT: ID pointer by value (root)
//       ID by reference to search for.
//
//OUPUT: T?F for success/failure.
//
//DESC: This is the private function.
//      Has not been used yet, made just in case.
//
//
bool BST::Search(ID * root, ID & to_search){
  if(root == NULL){
    return false;
  }
  if(root->ID::get_hash() == to_search.get_hash()){
    return true;
  }
  else{
    if(root->ID::get_hash() > to_search.get_hash()){
      return Search(root->go_left(), to_search);
    }
    return Search(root->go_right(), to_search);
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
    temp = dynamic_cast<Service*>(root);
    if(temp){
      temp->Display();
    } 
    Display(root->go_left());
    Display(root->go_right());
  }
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//          CountTree Function
//
//INPUT: Nothing.
//
//OUTPUT: Returns an int, the number of items
//        in the tree.
//
//DESC: Public Function. Counts the total
//      number of data inside of the tree.
int BST::CountTree(){
  if(root == NULL){
    return 0;
  }
  else{
    return CountTree(this->root);
  }
}

int BST::copy_tree(ID * source, Service *& array, int i) {
    int success = 0;
    if (!root) return success;
    ID* temp;
    temp = dynamic_cast<Service*>(source);
    if (temp) {
        source->CopyData(array[i]);
        success = copy_tree(source->go_right(), array, ++i) + 1;
        source->CopyData(array[i]);
        success = copy_tree(source->go_left(), array, ++i) + 1;
        source->CopyData(array[i]);
    }
    return success;
}

int BST::print_alpha() {
    ID* temp;
    temp = dynamic_cast<Service*>(root);
    if (temp) {
        int num = CountTree();
        Service * array = new Service[num];
        copy_tree(root, array, 0);
        quick_sort(array, 0, num-1);
        for (int i = 0; i < num; ++i) {
            array[i].Display();
        }
        return num;
    }
    else return 0;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
//            CountTree Function
//
//INPUT: ID pointer by value, the root.
//
//OUTPUT: Returns an int for every item that exists.
//
//DESC: Recursively traverses the entire tree. 
//      Counts the data that exists inside the tree.
//
int BST::CountTree(ID * root){
  if(root == NULL){
    return 0;
  }
  else{
    return 1 + CountTree(root->go_right()) + CountTree(root->go_left());
  }
}

int BST::quick_sort(Service*& array, int lo, int hi) {
    if (hi <= lo) return 0;
    int count = 0;
    std::string key;
    Service key_data;
    array[lo].CopyData(key_data);
    //hold on to copy key data	key_data = array[lo]
    array[lo].get_service(key);

    int j = hi;
    int i = lo + 1;
    while (i <= j) {
        std::string temp;
        std::string temp2;
        array[i].get_service(temp);
        array[j].get_service(temp2);
        if (key.compare(temp) > 0) i++; //advance the left finger
        else if (key.compare(temp2) <= 0) j--; // advance the right finger
        else { //swap data
            Service swap;
            array[i].CopyData(swap);
            array[j].CopyData(array[i]);
            swap.CopyData(array[j]);

        }
    }
    //place the key
    array[j].CopyData(array[lo]);
    key_data.CopyData(array[j]);

    count = quick_sort(array, lo, j - 1) + quick_sort(array, j + 1, hi) + 1;
    return count;
}

BST::BST(std::string file, int flag) {
	root = NULL;

	std::ifstream inFile;
    inFile.open(file);
    if (!inFile) {
        flag = 50;
        std::cout << "FILE NOT OPEN: " <<  file <<std::endl;
    }

	//File is a Provider file
	//if (flag == 1) {
      /*  std::string temp_hash;
        std::string dol;
        std::string cen;
        std::string temp_name;
        std::string temp_street;
        std::string temp_city;
        std::string temp_state;
        std::string temp_zip;

        getline(inFile, temp_hash, ',');
        while (getline(inFile, temp_hash, ',')) {
            getline(inFile, temp_name, ',');
            getline(inFile, temp_street, ',');
            getline(inFile, temp_city, ',');
            getline(inFile, temp_state, ',');
            getline(inFile, temp_zip, ',');

            //Provider new_obj(temp_hash, temp_name, temp_type, dol, cen);
            getline(inFile, temp_hash, ',');
            //if (!AddToBST(root, new_obj)) std::cout << "Not added to BST\n";*/
     /*   }

       // inFile.close();

	}

	//File is a Member file
	if (flag == 2) {

	}*/

	//File is a Service file
	if (flag == 3) {

        std::string temp_hash;
        std::string dol;
        std::string cen;
        std::string temp_job;
        std::string temp_type;

        getline(inFile, temp_hash, ',');
        while (getline(inFile, temp_hash, ',')) {

            getline(inFile, dol, ',');
            getline(inFile, cen, ',');
            getline(inFile, temp_job, ',');
            getline(inFile, temp_type, ',');
            Service new_obj(temp_hash, temp_job, temp_type, dol, cen);
            getline(inFile, temp_hash, ',');
            if (!AddToBST(root, new_obj)) std::cout << "Not added to BST\n";
        }  

        inFile.close();
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
