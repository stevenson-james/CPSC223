// filename binarysearchtree.cpp
// authors James Stevenson and Cade Newell
// username: jstevenson4
// date October 25, 2018
// Implementation of Abstract Data Type BinarySearchTree
//
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


#include "binarysearchtree.h"

// recursive helper functions

// searches a binary search tree for a certain text
// pre: treep is assigned a pointer to a root node of a binary search tree
//      targetText is assigned
// post: if targetText is found in the tree whose root node is treep
//          then the item in the root node is copied into anItem and
//          returns true; otherwise, returns false
// usage: isFound = searchHelper(root, targetText, anItem);
bool searchHelper(TreeNode* treep, const Key& targetText, Item& anItem)
{
   if (treep != nullptr)
   {
      if (targetText == treep -> item)
      {
         anItem = treep -> item;
         return true;
      } else if (targetText < treep -> item) {
         return searchHelper(treep -> leftChild, targetText, anItem);
      } else {
         return searchHelper(treep -> rightChild, targetText, anItem);
      }
   } else {
      return false;
   }
}

// adds an item to binary search tree
// pre: treep is assigned a pointer to a root node of a binary search tree
//      newItem is assigned and count is assigned to numberOfItems
// post: if newItem is already in binary search tree, then exception is thrown
//       else the item is added to dictionary in following sorting specifications
//       of binary search tree
// usage: addHelper(root, newItem, numberOfItems);
void addHelper(TreeNode*& treep, const Item& newItem, int& count) throw (Exception)
{
   if (treep != nullptr)
   {
      if (newItem == treep -> item)
      {
        throw Exception("The item you entered is already in the dictionary");
	  }
      else if (newItem < treep -> item) {
         addHelper(treep -> leftChild, newItem, count);
      } else{
         addHelper(treep -> rightChild, newItem, count);
      }
   }
   else
   {
     treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
	 if (treep == nullptr)
	 {
	   throw Exception("Not enough room to add another item");
	 }
	 count++;
   }
}

void deleteHelper (TreeNode*& treep, const Key& targetText, int& count) throw (Exception)
{
   if (treep != nullptr)
   {
      if (targetText == treep -> item)
      {
        if((treep -> leftChild == nullptr) && (treep -> rightChild == nullptr))
        {
	      delete treep;
        treep = nullptr;
	      count--;
        }
        else if ((treep -> leftChild == nullptr) && (treep -> rightChild != nullptr))
        {
          TreeNode* delptr;
          delptr = treep;
          treep = delptr -> rightChild;
          delete delptr;
		  count--;
        }
        else if ((treep -> leftChild != nullptr) && (treep -> rightChild == nullptr))
                {
          TreeNode* delptr;
          delptr = treep;
          treep = delptr -> leftChild;
          delete delptr;
		  count--;
        }
	    }
      else if (targetText < treep -> item) {
         deleteHelper(treep -> leftChild, targetText, count);
      } else{
         deleteHelper(treep -> rightChild, targetText, count);
      }
   }
   else
   {
    throw Exception("The text you are looking for is not in the dictionary");
   }
   
}

// prints items from binary search tree to output in inorder fashion
// pre: treep is assigned a pointer to a root node of a binary search tree
//      output is assigned
// post: items from binary search tree are printed to output in inorder fashion
// usage: inorderHelper (root, output);
void inorderHelper (TreeNode* treep, ostream& output)
{
	if (treep != nullptr)
	{
		inorderHelper(treep -> leftChild, output);
		output << treep -> item << endl;
		inorderHelper(treep -> rightChild, output);
	}
}

// readTree algorithm that rebalances a binary search tree
// recursive helper in binarysearchtree
// makes minimum height tree
// pre: infile has items with keys in sorted order
//      treep is assigned a pointer to a root node of a binary search tree
//      and numberOfEntries is filled with number of items in
// post: items from infile are in binarysearchtree of minimum height following
//       sorting specifications of binarysearchtree
// usage: rebalanceHelper(infile, root, numberOfEntries);
void rebalanceHelper (istream& infile, TreeNode*& treep, int numberOfEntries) throw (Exception)
{
   if (numberOfEntries > 0)
   {
      treep = new (nothrow) TreeNode;
	  if (treep == nullptr)
	  {
		  throw Exception("Not enough room to add another Item");
	  }
      rebalanceHelper(infile, treep -> leftChild, numberOfEntries / 2);
	  infile >> treep -> item;
      rebalanceHelper(infile, treep -> rightChild, (numberOfEntries - 1) / 2);
   }
}

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
ostream& operator<< (ostream& output, const BinarySearchTree& rightHandSideDictionary)
{
	return output;
}

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
istream& operator>> (istream& input, BinarySearchTree& rightHandSideDictionary)
{
	return input;
}

// creates a new binary search tree
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree myBinarySearchTree;	
BinarySearchTree::BinarySearchTree()
{
	numberOfItems = 0;
}

// destroys a binary search tree
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
BinarySearchTree::~BinarySearchTree()
{
	numberOfItems = 0;
}

// searches for a meaning with a given text
// pre targetText has been assigned 
// post if an item with texting abbreviation the same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myBinarySearchTree.searchForMeaning(targetText, anItem, isFound);
void BinarySearchTree::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
	isFound = searchHelper(root, targetText, anItem);
}

// inserts a new text item into the binary search tree
// pre: newItem has been assigned
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there, isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myBinarySearchTree.addNewEntry(myItem);
void BinarySearchTree::addNewEntry(const Item& newItem) throw (Exception)
{
	addHelper(root, newItem, numberOfItems);
}

// removes the item associated with a given text from the binary search tree
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and 
//           targetText is found in BinarySearchTree object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the BinarySearchTree object 
//       else isFound is false or isEmpty is true depending
// usage: myBinarySearchTree.deleteEntry(myText);
void BinarySearchTree::deleteEntry(const Key& targetText) throw (Exception)
{
	deleteHelper(root, targetText, numberOfItems);
}

// prints number of items followed by items from binary 
// search tree to output in inorder fashion
// pre: output is assigned
// post: number of items and items from binary search tree are printed to output in 
// inorder fashion
// outfile is able to be read in to create rebalanced binary search tree
// usage: myBinarySearchTree.inorderTraverse(outfile);
void BinarySearchTree::inorderTraverse (ostream& output)
{
	output << numberOfItems << endl;
	inorderHelper (root, output);
}

// creates minimum height binary search tree from input file
// pre: infile has number of items followed by each item with keys in sorted order,
//      each followed by an endline
// post: binary search tree of minimum height is created, filled with items of
//       infile. numberOfItems is equal to the number of items in infile
// usage: myBinarySearchTree.rebalanceBinaryTree(infile);
void BinarySearchTree::rebalanceBinaryTree(istream& infile) throw (Exception)
{
	int numberOfEntries;
	infile >> numberOfEntries;
	rebalanceHelper(infile, root, numberOfEntries);
	numberOfItems = numberOfEntries;
}