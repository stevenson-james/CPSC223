//file treenode.h
//author Dr. Y
//date October 8, 2018

//ADT TreeNode for a binary tree: data object a node with 
//                            an item and a pointer to left and right children
// operations: constructor and copy constructor
// Especially designed for the BinaryTree class

#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>
#include "item.h"
using namespace std;

class TreeNode
{
public:
 

TreeNode();

//constructs treenode which consists of treenode pointers leftChild and rightChild
//and an Item object called item and sets each equal to some values
//pre treenode exists
//post treenode is filled with newItem, theLeft, and theRight
//usage TreeNode (item, lefttreep, righttreep);
TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight);
   
Item item;
TreeNode* leftChild;
TreeNode* rightChild;

};
#endif


