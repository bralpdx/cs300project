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
  }
  return;
}

/*
   bool BST::AddToBST(ID *& to_add){
// if root doesn't exist, create it
if(root == NULL){
ID * temp = to_add;
temp = dynamic_cast<Provider*>(to_add);
if(temp){
root = new Provider(to_add);
}
temp = dynamic_cast<Member*>(to_add);
if(temp){
root = new Member(to_add);
}
return true;
}
//return AddToBST(this->root, to_add);
}

bool BST::AddToBST(ID *& root, ID *& to_add){
// recursively find the NULL root
if(root == NULL){

//ID * temp = to_add;
//temp = dynamic_cast<Provider*>(to_add);
root = dynamic_cast<Provider*>(to_add);
if(root){
root = new Provider(to_add);
return true;
}
//temp = dynamic_cast<Member*>(to_add);
root = dynamic_cast<Member*>(to_add);
if(root){
root = new Member(to_add);
return true;
}

return false;
}

else{
if(root->ID::get_hash() > to_add->ID::get_hash()){
return AddToBST(root->go_left(), to_add);
}
else{
return AddToBST(root->go_right(), to_add);
}
}
}*/
bool BST::AddToBST(Provider & to_add){                          
  if(root == NULL){ // if root is null make the first one
    this->root = new Provider(to_add);
    return true;
  }
  else{
    ID * temp;
    temp = dynamic_cast<Provider*>(this->root);
    if(temp){
      return AddToBST(this->root, to_add);
    }
    return false;
  }
}

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

bool BST::AddToBST(Member & to_add){                          
  if(root == NULL){ // if root is null make the first one
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
}
