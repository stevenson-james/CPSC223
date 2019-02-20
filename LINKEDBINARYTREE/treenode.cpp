//file: treenode.cpp
// author Dr. Y
// date October 16, 2018
// Implementation of ADT TreeNode

#include "treenode.h"

//constructs treenode which consists of treenode pointers leftChild and rightChild
//and an Item object called item
//pre treenode exists
//post treenode is empty
//usage TreeNode treep;
TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
}

//constructs treenode which consists of treenode pointers leftChild and rightChild
//and an Item object called item and sets each equal to some values
//pre treenode exists
//post treenode is filled with newItem, theLeft, and theRight
//usage TreeNode (item, lefttreep, righttreep);
TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
}
