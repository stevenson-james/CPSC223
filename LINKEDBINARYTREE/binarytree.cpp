//file binarytree.cpp
//authors James Stevenson and Cade Newell
//username jstevenson4
//date October 16, 2018

//data object: a binary tree which is either empty or
//             in the form of
//                   TL
//             r
//			         TR
//             where TL and TR are binary trees
//data structure: a linked binary tree
//operations: constructor, copy constructor, destructor
//            is empty, print tree, preorder, inorder, and
//            postorder traversals, make full tree of height 3,
//            make complete tree of height 4

#include "binarytree.h"
#include <iostream>
using namespace std;

// ***************** recursive helpers *****************

//Copies one binary tree to another
//pre oldtreep points to the root of a binary tree
//post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
//usage: copyTree (newptr, oldptr);
void copyTree (TreeNode*& newtreep, TreeNode* oldtreep) throw (Exception)
{
	if (oldtreep != nullptr)
	{
		newtreep = new (nothrow) TreeNode(oldtreep -> item, nullptr, nullptr);
		if (newtreep == nullptr)
			throw Exception("in BinaryTree: no memory from heap available for item");
		copyTree(newtreep -> leftChild, oldtreep -> leftChild);
		copyTree(newtreep -> rightChild, oldtreep -> rightChild);
	}
}

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroyTree (TreeNode*& treep)
{
	if (treep != nullptr)
	{
		destroyTree(treep -> leftChild);
		destroyTree(treep -> rightChild);
		delete treep;
		treep = nullptr;
	}
}

// recursive helper for prettyDisplay
// pre: treep exists, level is initially set to 0
// post: prints level number of tabs followed by tree abbreviations,
//       the root will be printed as root -> abbreviations
// usage writePretty(root, 0);

void writePretty (TreeNode* treep, int level)
{
	if (treep != nullptr)
	{
		level++;
		writePretty(treep -> rightChild, level);
		Key myKey;
		myKey = treep -> item;
		if (level == 1)
			cout << "root -> " << myKey << endl;
		else
		{
			for (int i = 0; i < level; i++)
				cout << "\t";
			cout << myKey << endl;
		}
		writePretty (treep -> leftChild, level);
	}
	// not preorder, inorder, or postorder
	// indents depend on the level
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the 
//     specified order. the items are separated by commas
//usage: preorder (mroot);   
//       similarly for the others
void preorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		cout << treep -> item << endl;
		preorder(treep -> leftChild);
		preorder(treep -> rightChild);
	}
}

void inorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		inorder(treep -> leftChild);
		cout << treep -> item << endl;
		inorder(treep -> rightChild);
	}
}


void postorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		postorder(treep -> leftChild);
		postorder(treep -> rightChild);
		cout << treep -> item << endl;
	}
}


// **************************public methods************************


//creates an empty binary tree
//post: object is an empty binary tree
//usage: BinaryTree zags;
BinaryTree::BinaryTree()
{
   root = nullptr;
}

//creates a new binary tree that is a copy of an existing tree
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception)
{
   root = nullptr;
   copyTree(root, rightHandSideTree.root);
}

//releases the memory of a binary tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree::~BinaryTree()
{
   destroyTree(root);
}

// ******************** member functions ********************************************
//@pre: binary tree object exists
// **********************************************************************************

//checks for an empty tree
//post: returns true if the object is empty; else returns false
//usage: if (tree.isEmpty())
bool BinaryTree::isEmpty() const
{
   return (root == nullptr);
}

//copies one tree to another
//pre: rightHandSideTree is an assigned tree.
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: atree = btree = ctree;
BinaryTree& BinaryTree::operator=(const BinaryTree& rightHandSideTree) throw (Exception)
{
	destroyTree(root);
	copyTree(root, rightHandSideTree.root);
	return *this;
}

//prints the tree to look like a computer science tree
//post: outputs the tree as in the example below
//
//                        bar
//                  foo
//                        geeU
//  root ->  queue
//                        stack
//                  list
//                        array
//nodes at the same level are indented the same.
//Viewer must rotate head 90 degrees in order to look like a cs tree
//usage: tree.prettyDisplay();
void BinaryTree::prettyDisplay()
{
	writePretty(root, 0);
}

// *************** on the following traversals

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();  
//similarly for the other traversals
// *****************************************************
void BinaryTree::preorderTraverse ()
{
   preorder(root);
}

void BinaryTree::inorderTraverse ()
{
	inorder(root);
}


void BinaryTree::postorderTraverse()
{
	postorder(root);
}

//makes a full binary tree of height 3
//pre input is either cin or an open file
//    input's pointer is before the first item
//post: object is a full binary tree of height 3
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: makeFullTreeHeight3(infile);
//       within try and catch blocks
void BinaryTree::makeFullTreeHeight3(istream& input) throw (Exception)
{
   Item newguy;
   
   input >> newguy;
   root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for root item");
   
   input >> newguy;
   root -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for right child item");
   
   input >> newguy;
   root -> leftChild -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> leftChild -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> rightChild -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> rightChild -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> rightChild -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> rightChild -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
}

//makes a complete but not full binary tree of height 4 
//pre: input is either cin or an open file
//     input's pointer is before the first item
//post: object is a complete binary tree of height 4
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: makeCompleteTreeHeight4(infile);
//       within try and catch blocks
void BinaryTree::makeCompleteTreeHeight4(istream& input) throw (Exception)
{
	Item newguy;
   
   input >> newguy;
   root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for root item");
   
   input >> newguy;
   root -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for right child item");
   
   input >> newguy;
   root -> leftChild -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> leftChild -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> rightChild -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> rightChild -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> rightChild -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> rightChild -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> leftChild -> leftChild -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> leftChild -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> leftChild -> leftChild -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> leftChild -> rightChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   input >> newguy;
   root -> leftChild -> rightChild -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   if (root -> leftChild -> rightChild -> leftChild == nullptr)
	   throw Exception ("in BinaryTree: no memory from heap available for left child item");
   
   if (root -> leftChild -> rightChild -> leftChild != nullptr)
	   throw Exception ("I am throwing an exception at you Dr. Y. Do you have your catcher's mitt ready?");
}
