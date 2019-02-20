//file client.cpp
//authors James Stevenson and Cade Newell
//username: jstevenson4
//date October 8, 2018

// client.cpp: This program prints a reader-friendly version of a full binary tree
//             of height 2. It will then do the three traversals of that tree.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "binarytree.h"
using namespace std;

// opens a file for reading
// post: infile has been opened with file pointer at beginning of file
// usage: openFile(infile);
void openFile(ifstream& infile);

// makes a full binary tree of height 3
// pre: fullTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: fullTree is now a full binary tree of height 3
// usage: makeFullTreeHeight3(infile, fullTree);
void makeFullTreeHeight3(BinaryTree& fullTree, ifstream& infile);

// makes a degenerateTree binary tree of height 4
// pre: degenerateTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: degenerateTree is now a degenerate binary tree of height 4
// usage: makeDegenerateTreeHeight4(infile, fullTree);
void makeDegenerateTreeHeight4(BinaryTree& degenerateTree, ifstream& infile);

// prints the full tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printFullTreeHeight2();
void printFullTreeHeight3();

// prints the degenerate tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printDegenerateTreeHeight4();
void printDegenerateTreeHeight4();

//this will print both trees
//post: pictures of both trees have been displayed on screen
//usage: printBothTrees();
void printBothTrees();

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines);

//this prints the binary tree using a preorder traversal
//pre: fullTree exists
//post: prints the binary tree using a preorder traversal
//usage: printPreorder(BinaryTree& fullTree)
void printPreorder (BinaryTree& fullTree);

//this prints the binary tree using a inorder traversal
//pre: fullTree exists
//post: prints the binary tree using a inorder traversal
//usage: printInorder(BinaryTree& fullTree)
void printInorder (BinaryTree& fullTree);

//this prints the binary tree using a postorder traversal
//pre: fullTree exists
//post: prints the binary tree using a postorder traversal
//usage: printPostorder(BinaryTree& fullTree)
void printPostorder (BinaryTree& fullTree);

// prints traversals of a tree
// 	(preorder, inorder, postorder)
// pre fullTree and degenerateTree exist
// post all three traversals of a tree is printed
// usage: printTraversalsOfBothTrees (fullTree,degenerateTree);
void printTraversalsOfOneTree (BinaryTree& myTree);

// prints traversals of full and degenerate trees 
// 	(preorder, inorder, postorder)
// pre fullTree and degenerateTree exist
// post all three traversals of both trees are printed
// usage: printTraversalsOfBothTrees (fullTree,degenerateTree);
void printTraversalsOfBothTrees (BinaryTree& fullTree, BinaryTree& degenerateTree);

int main()
{
	BinaryTree fullTree, degenerateTree;
	ifstream infile;
	openFile(infile);
	
	printNewLines(2);
	
	//part a
	makeFullTreeHeight3(fullTree, infile);
	makeDegenerateTreeHeight4(degenerateTree, infile);
	
	//part b
	printBothTrees();
	
	//part c
	printTraversalsOfBothTrees (fullTree,degenerateTree);
	
	printNewLines(1);
	infile.close();
	return 0;
	
}

// opens a file for reading
// post: infile has been opened with file pointer at beginning of file
// usage: openFile(infile);
void openFile(ifstream& infile)
{
	infile.open("in.dat");
	if (infile.fail())
	{
		cout << "ERROR: cannot open in.dat. BOLTING" << endl;
		exit(1);   // the only place we bolt
	}
}

// makes a full binary tree of height 2
// pre: fullTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: fullTree is now a full binary tree of height 2
// usage: makeFullTreeHeight2(infile, fullTree);
void makeFullTreeHeight3(BinaryTree& fullTree, ifstream& infile)
{
	Item newItem;
	
	infile >> newItem;
	fullTree.insert(newItem, 1, 2);
	
	infile >> newItem;
	fullTree.insert(newItem, 3, 4);
	
	infile >> newItem;
	fullTree.insert(newItem, 5, 6);
	
	infile >> newItem;
	fullTree.insert(newItem, -1, -1);
	
	infile >> newItem;
	fullTree.insert(newItem, -1, -1);
	
	infile >> newItem;
	fullTree.insert(newItem, -1, -1);
	
	infile >> newItem;
	fullTree.insert(newItem, -1, -1);
}

// makes a degenerateTree binary tree of height 4
// pre: degenerateTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: degenerateTree is now a degenerate binary tree of height 4
// usage: makeDegenerateTreeHeight4(infile, fullTree);
void makeDegenerateTreeHeight4(BinaryTree& degenerateTree, ifstream& infile)
{
	Item newItem;
	
	infile >> newItem;
	degenerateTree.insert(newItem, -1, 1);
	
	infile >> newItem;
	degenerateTree.insert(newItem, -1, 2);
	
	infile >> newItem;
	degenerateTree.insert(newItem, -1, 3);
	
	infile >> newItem;
	degenerateTree.insert(newItem, -1, -1);
}

// prints the full tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printFullTreeHeight3();
void printFullTreeHeight3()
{
	cout << "A Full Tree of Height 3:" << endl;
	cout << "      		           		 " << "lol: laugh out loud" << endl;
	cout << "         		   /     " << "            		  	     " << "    \\" << endl;
	cout << " 		gtg: got to go" << "              		         " << "ttyl: talk to you later" << endl;
	cout << "      	    /     " << "        " << "    \\";
	cout << "        				    /     " << "        " << "    \\" << endl;
	cout << " smh: shaking my head" << "   " << "tmi: too much information";
	cout << "      "  << "asap: as soon as possible" << "   " << "idk : i don't know" << endl << endl;
}

// prints the degenerate tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printDegenerateTreeHeight4();
void printDegenerateTreeHeight4()
{
	cout << "A Degenerate Tree of Height 4:" << endl;
	cout << "		l8r: later" << endl;
	cout << "  		     \\" << endl;
	cout << "  		  nvm: never mind" << endl;
	cout << "  		        \\" << endl;
	cout << "   		   idc: i don't care" << endl;
	cout << "   		          \\" << endl;
	cout << "   		      jk: just kidding" << endl << endl;
}

//this will print both trees
//post: pictures of both trees have been displayed on screen
//usage: printBothTrees();
void printBothTrees()
{
	printFullTreeHeight3();
	printDegenerateTreeHeight4();
}

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines)
{
	for (int k = 0; k < numberOfLines; k++)
		cout << endl;
}

//this prints the binary tree using a preorder traversal
//pre: fullTree exists
//post: prints the binary tree using a preorder traversal
//usage: printPreorder(BinaryTree& fullTree)
void printPreorder (BinaryTree& fullTree)
{
	cout << "Preorder Traversal:";
	printNewLines(2);
	fullTree.preorder();
	printNewLines(1);
}

//this prints the binary tree using a inorder traversal
//pre: fullTree exists
//post: prints the binary tree using a inorder traversal
//usage: printInorder(BinaryTree& fullTree)
void printInorder (BinaryTree& fullTree)
{
	cout << "Inorder Traversal:";
	printNewLines(2);
	fullTree.inorder();
	printNewLines(1);
}

//this prints the binary tree using a postorder traversal
//pre: fullTree exists
//post: prints the binary tree using a postorder traversal
//usage: printPostorder(BinaryTree& fullTree)
void printPostorder (BinaryTree& fullTree)
{
	cout << "Postorder Traversal:";
	printNewLines(2);
	fullTree.postorder();
	printNewLines(1);
}

// prints traversals of a tree
// 	(preorder, inorder, postorder)
// pre fullTree and degenerateTree exist
// post all three traversals of a tree is printed
// usage: printTraversalsOfBothTrees (fullTree,degenerateTree);
void printTraversalsOfOneTree (BinaryTree& myTree)
{
	printPreorder(myTree);
	printInorder(myTree);
	printPostorder(myTree);
}

// prints traversals of full and degenerate trees 
// 	(preorder, inorder, postorder)
// pre fullTree and degenerateTree exist
// post all three traversals of both trees are printed
// usage: printTraversalsOfBothTrees (fullTree,degenerateTree);
void printTraversalsOfBothTrees (BinaryTree& fullTree, BinaryTree& degenerateTree)
{
	cout << "Traversals of Full Tree of Height 3:" << endl << endl;
	printTraversalsOfOneTree(fullTree);
	printNewLines(1);
	cout << "Traversals of Degenerate Tree of Height 4:" << endl << endl;
	printTraversalsOfOneTree(degenerateTree);
}