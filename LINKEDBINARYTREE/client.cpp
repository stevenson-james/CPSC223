//file client.cpp
//author Cade Newell, James Stevenson
//username jstevenson4
//date October 15, 2018
//operations test the functions from binarytree.cpp in user friendly fashion

#include "binarytree.h"
#include "exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

//prints out all three of the traversals
//pre: mytree exists
//post: traversals of mytree are printed
//usage: printAllThreeTraversals(fullTree)
void printAllThreeTraversals(BinaryTree& mytree);

//prints out numberOfLines number of new lines
//pre: numberOfLines is an int
//post: prints numberOfLines number of new lines
//usage: printNewLines(3)
void printNewLines(int numberOfLines);

//Prints the tree using a recursive preorder
//pre: mytree exists
//post: prints items of mytree recursive preorder method
//usage: printPreorder(fullTree)
void printPreorder (BinaryTree& mytree);

//Prints the tree using a recursive inorder function
//pre: mytree exists
//post: prints items of mytree recursive inorder method
//usage: printInorder(fullTree)
void printInorder (BinaryTree& mytree);

//Prints the tree using a recursive postorder function
//pre: mytree exists
//post: prints items of mytree recursive postorder method
//usage: printPostorder(fullTree)
void printPostorder (BinaryTree& mytree);

// prints the abbreviations of full tree in reader-friendly fashion, and prints 
// the traversals preorder, inorder, and postorder
// post: the picture of the tree has been displayed on the screen, with the traversals
// usage: printTree(fullTree);
void printTree (BinaryTree& mytree);

//makes and prints full tree of height 3 with traversals
//pre: mytree is empty and there is a pointer to the inFile that has just been opened
//post: makes a full tree of height 3 as well as prints out the tree while looking for 
// an exception in the try and catch block
//makeAndPrintFullTree(fullTree, inFile)
void makeAndPrintFullTree (BinaryTree& mytree, ifstream& infile);

//makes and prints complete tree of height 4 with traversals
//pre: mytree is empty and there is a pointer to the inFile that has been opened
//post: makes a complete tree of height 4 as well as prints out the tree while looking for 
// an exception in the try and catch block
//makeAndPrintCompleteTree(completeTree, inFile)
void makeAndPrintCompleteTree(BinaryTree& mytree, ifstream& infile);

//copies rightHandSideTree to mytree and prints mytree with traversals
//pre: mytree and rightHandsideTree exist
//post: makes a copy of a full tree of height 3 and a complete tree of height 4, 
// as well as prints out the tree while looking for an exception in the try and catch block
//makeAndPrintCopiedTree(completeTree, fullTree)
void makeAndPrintCopiedTree (BinaryTree& mytree, BinaryTree& rightHandSideTree);

int main()
{
	BinaryTree fullTree, completeTree;
	ifstream infile;
	
	openInputFile(infile, "in.dat");
	
	makeAndPrintFullTree (fullTree, infile);
	
	makeAndPrintCompleteTree(completeTree, infile);
	
	makeAndPrintCopiedTree(completeTree, fullTree);
	
	return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename) 
{
	inputFile.open(filename);
	if (inputFile.fail())
	{
		cout << "File failed to open!!!!" << endl;
		exit(1);
	}
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except)
{
	cout << endl << endl;
	cout << except.what();
	cout << endl << endl;
}
   
//prints out all three of the traversals
//pre: mytree exists
//post: traversals of mytree are printed
//usage: printAllThreeTraversals(fullTree)
void printAllThreeTraversals(BinaryTree& mytree)
{
	printPreorder(mytree);
	printInorder(mytree);
	printPostorder(mytree);
}

//prints out numberOfLines number of new lines
//pre: numberOfLines is an int
//post: prints numberOfLines number of new lines
//usage: printNewLines(3)
void printNewLines(int numberOfLines)
{
	for (int k = 0; k < numberOfLines; k++)
		cout << endl;
}

//Prints the tree using a recursive preorder
//pre: mytree exists
//post: prints items of mytree recursive preorder method
//usage: printPreorder(fullTree)
void printPreorder (BinaryTree& mytree)
{
	cout << "Preorder Traversal:";
	printNewLines(2);
	mytree.preorderTraverse();
	printNewLines(1);
}

//Prints the tree using a recursive inorder function
//pre: mytree exists
//post: prints items of mytree recursive inorder method
//usage: printInorder(fullTree)
void printInorder (BinaryTree& mytree)
{
	cout << "Inoder Traversal:";
	printNewLines(2);
	mytree.inorderTraverse();
	printNewLines(1);
}

//Prints the tree using a recursive postorder function
//pre: mytree exists
//post: prints items of mytree recursive postorder method
//usage: printPostorder(fullTree)
void printPostorder (BinaryTree& mytree)
{
	cout << "Postorder Traversal:";
	printNewLines(2);
	mytree.postorderTraverse();
	printNewLines(1);
}


// prints the abbreviations of full tree in reader-friendly fashion, and prints 
// the traversals preorder, inorder, and postorder
// post: the picture of the tree has been displayed on the screen, with the traversals
// usage: printTree(fullTree);
void printTree (BinaryTree& mytree)
{
	mytree.prettyDisplay();
	cout << endl;
	printAllThreeTraversals(mytree);
}

//makes and prints full tree of height 3 with traversals
//pre: mytree is empty and there is a pointer to the inFile that has just been opened
//post: makes a full tree of height 3 as well as prints out the tree while looking for 
// an exception in the try and catch block
//makeAndPrintFullTree(fullTree, inFile)
void makeAndPrintFullTree (BinaryTree& mytree, ifstream& infile)
{
	cout << endl << "Full Tree of Height 3:" << endl << endl;
	try
	{
		mytree.makeFullTreeHeight3(infile);
	}
	catch(Exception except)
	{
	   printExceptionMessage(except);
	}
	printTree(mytree);
}

//makes and prints complete tree of height 4 with traversals
//pre: mytree is empty and there is a pointer to the inFile that has been opened
//post: makes a complete tree of height 4 as well as prints out the tree while looking for 
// an exception in the try and catch block
//makeAndPrintCompleteTree(completeTree, inFile)
void makeAndPrintCompleteTree (BinaryTree& mytree, ifstream& infile)
{
	cout << "Complete Tree of Height 4:" << endl;
	try
	{
		mytree.makeCompleteTreeHeight4(infile);
	}
	catch(Exception except)
	{
		printExceptionMessage(except);
	}
	printTree(mytree);
}

//copies rightHandSideTree to mytree and prints mytree with traversals
//pre: mytree and rightHandsideTree exist
//post: makes a copy of a full tree of height 3 and a complete tree of height 4, 
// as well as prints out the tree while looking for an exception in the try and catch block
//makeAndPrintCopiedTree(completeTree, fullTree)
void makeAndPrintCopiedTree (BinaryTree& mytree, BinaryTree& rightHandSideTree)
{
	cout << endl << "Full Tree Copied to Completed Tree:" << endl << endl;
	try
	{
		mytree = rightHandSideTree;
	}
	catch(Exception except)
	{
		printExceptionMessage(except);
	}
	printTree(mytree);
}
