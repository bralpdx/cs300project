#include "param.h"
#include "utilities.h"
#include "bst.h"
#include <iostream>
using namespace std;
int main() {
	//pre_hash_id(); // See utilities.h for desc
  BST member_tree;
  BST provider_tree;
  string name = "andrew bonham";
  string address = "200 s the place dr";
  string city = "oregon city";
  string state = "oregon";
  int zip = 9999;
  string hash = "123456";
  Provider to_add;
  to_add.Insert(name, address, city, state, zip, hash);
  //to_add.Display();
  if(provider_tree.AddToBST(to_add))
    cout << "\n\nSuccessfully added!\n";
  name = "joe blow";
  address = "portland buttvew";
  city = "portland";
  state = "oregon";
  zip = 55555;
  hash = "987654";
  to_add.Insert(name, address, city, state, zip, hash);
  //to_add.Display();
  if(provider_tree.AddToBST(to_add))
    cout << "\n\nSuccessfully added!\n";
  Member AddMember;
  name = "nogoe";
  address = "fdaklfjdka";
  city = "fjekla;jfea";
  state = "SAFJKLDFS";
  zip = 12345;
  hash = "119999";
  to_add.Insert(name, address, city, state, zip, hash);

  AddMember.Insert(name, address, city, state, zip, hash);
  if(provider_tree.AddToBST(to_add))
    cout << "\n\nSuccessfully added!\n";

  if(provider_tree.AddToBST(AddMember))
    cout << "\n\nSuccessfully added!\n";
  cout << "\n\nThere are " << provider_tree.CountRight() << " nodes on the right side!\n";
  provider_tree.Display();




  cout << "\n\nNow to attempt to edit a node\n";
  name = "nogoe Joe";
  address = "Big Butt Drive";
  city = "The hot Spot";
  state = "Oregon";
  zip = 97045;
  to_add.Display();
  to_add.Insert(name, address, city, state, zip, hash);

  to_add.Display();
  if(provider_tree.EditBST(to_add))
    cout << "\n\nSuccessfully Edited!\n";
  provider_tree.Display();


/*
	std::cout << "=======================\n"; 
	std::cout << "== Welcome to ChocAn ==\n";
	std::cout << "=======================\n";
	
	BST service_bst("svc_codes.txt",3);
	BST provider_bst("user_info.txt",1);
	BST member_bst("",2);

	if(sign_in_prompt() == RETURN_FAILURE)
		std::cout << "ERROR SIGNING IN.\n";

	std::cin.get();*/
	return RETURN_SUCCESS;
}
