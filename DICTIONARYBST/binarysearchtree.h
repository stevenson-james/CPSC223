// Specification of ADT Binary Search Tree
//     data object: a binary search tree T that is either empty or in the form
//                  in the form of     r
//                                  /    \
//                                TL     TR
//                 where keys in keys in TL < key in r < keys in TR and TL and
//                 TR are binary search trees
//     operations: create, destroy
//                 search the binary search tree for an item given its text
//                 insert a new item into the binary search tree
//                 remove an item from the binary search tree given its text
//   associated operations: input and output
// filename binarysearchtree.h
// authors: James Stevenson and Cade Newell
// username: jstevenson4
// date October 25, 2018

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "item.h"
#include "treenode.h"
#include "binarytree.h"
#include "exception.h"

class BinarySearchTree: public BinaryTree
{
// outputs a binary search tree
// pre: output has been opened if it is a file
//      rightHandSideBinarySearchTree has been assigned items
//post: outputs the tree as in the example below 
//
//                            stack
//                  pointer
//                            nullptr
//  root ->  list
//                            item
//                  hashtable
//                            array
//nodes at the same level are indented the same.
//Viewer must rotate head 90 degrees in order to look like a cs tree
// usage: outfile << myBinarySearchTree;    
friend ostream& operator<< (ostream& output, const BinarySearchTree& rightHandSideDictionary);

// inputs items into a binary search tree
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      2
//      lol
//      laugh out loud
//      ttyl
//      talk to you later
// post: if there is enough memory, 
//       item or items are added to the binary search tree
// usage: infile >> myBinarySearchTree;
friend istream& operator>> (istream& input, BinarySearchTree& rightHandSideDictionary);

public:

// creates a new binary search tree
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree myBinarySearchTree;	
BinarySearchTree();

// destroys a binary search tree
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
~BinarySearchTree();

// searches for a meaning with a given text
// pre targetText has been assigned 
// post if an item with texting abbreviation the same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myBinarySearchTree.searchForMeaning(targetText, anItem, isFound);
void searchForMeaning(const Key& targetText, Item& anItem, bool& isFound);

// inserts a new text item into the binary search tree
// pre: newItem has been assigned
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there, isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myBinarySearchTree.addNewEntry(myItem, isFull, isAlreadyThere);
void addNewEntry(const Item& newItem) throw (Exception);

// removes the item associated with a given text from the binary search tree
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and 
//           targetText is found in BinarySearchTree object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the BinarySearchTree object 
//       else isFound is false or isEmpty is true depending
// usage: myBinarySearchTree.deleteEntry(myText, isEmpty, isFound);
void deleteEntry(const Key& targetText) throw (Exception);

// prints number of items followed by items from binary 
// search tree to output in inorder fashion
// pre: output is assigned
// post: number of items and items from binary search tree are printed to output in 
// inorder fashion
// outfile is able to be read in to create rebalanced binary search tree
// usage: myBinarySearchTree.inorderTraverse(outfile);
void inorderTraverse (ostream& output);

// creates minimum height binary search tree from input file
// pre: infile has number of items followed by each item with keys in sorted order,
//      each followed by an endline
// post: binary search tree of minimum height is created, filled with items of
//       infile. numberOfItems is equal to the number of items in infile
// usage: myBinarySearchTree.rebalanceBinaryTree(infile);
void rebalanceBinaryTree(istream& infile) throw (Exception);
private:
   int numberOfItems;
};
#endif

