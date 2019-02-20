// Specification of ADT Dictionary as ADT AVLTree
//    Data object: A binary search tree T that is either empty or in the form
// 	       	   root
//            /    \
//	         Tl     Tr
// where tree left and tree right are AVL Tree. 
// data structure: a linked binary search tree
//     operations: create, destroy
//                 insert a new item into the dictionary
//                 display dictionary
// filename AVLTree.h
// names: James Stevenson and Cade Newell
// username: jstevenson4
// date: November 20, 2018
#include "binarysearchtree.h"
#include <fstream>
class AVLTree: public BinarySearchTree
{
	public:
	
	// creates a new AVL tree
	// post: AVLTree object exists but is empty
	// usage: AVLTree myDictionary;
	AVLTree();
	
	// destroys an AVL tree
	// pre: AVLTree object exists
	// post: all memory for AVLTree object has been freed
	// usage: automatically done at the end of scope
	~AVLTree();
	
	// inserts a new text item into the dictionary
	// pre: newItem has been assigned
	// post: if there is room in the BinarySearchTree object and newItem's text
	//            is not already there then newItem is appropriately added
	//       else it throws an exception for either a full dictionary or
	//            a message that it is already there
	// usage: myDictionary.addNewEntry(myItem);
	void addNewEntry(const Item& newItem) throw (Exception);
	
	//prints the tree to look like a computer science tree
	//pre: treep points to the root of a tree. level >= 0
	//post: outputs the tree as in the example below (items not sorted in example)
	//
	//  					  bar:0
	//                  foo:0
	//                        geeU:0
	//  root ->  queue:0
	//                        stack:0
	//                  list:0
	//                        array:0
	//nodes at the same level are indented the same.
	//Viewer must rotate head 90 degrees in order to look like a cs tree
	//the balances are on the right of the key following the semicolon
	//usage: writePretty(root,0);
	void prettyDisplay(ofstream& outputFile);
	
};