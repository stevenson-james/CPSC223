//file clientprogram.cpp
//names: Cade Newell and James Stevenson
//username: jstevenson4
//date: 11/20/18
/*
This program runs case tests for different AVL Trees based upon the six cases of 
addNewEntryAndMakeSearchPath in avltree.cpp. There is no user input, rather the inputs
and outputs are from in.dat and to avl.dat respectively
*/

#include "avltree.h"
#include "exception.h"
#include <string>
#include <fstream>
using namespace std;

// opens an input file with a chosen name
// pre filename is assigned
// post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
// usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename);

// opens an output file with a chosen name
// pre: filename is assigned
// post: if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
// usage: openOutputFile(infile, filename);
void openOutputFile(ofstream& outfile, string filename);

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been outputted to outputFile
// usage: makeNewLines(3, outputFile);
void printNewLines(int numberOfLines, ofstream& outputFile);

// prints an exception message
// pre: except has been thrown
// post: except is printed to the screen with two newlines before and after
// usage: PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

// runs cases using input file by printing case name, as well as pre and post trees
// pre: inputFile, myCase, and outputFile exist and inputFile and outputFile are open
// post: items are added to AVL tree from inputFile and pre and post trees are outputted
//       to outputFile
// usage: doCaseHelper(inputFile, "CASE1", outputFile);
void doCaseHelper (istream& inputFile, string myCase, ofstream& outputFile);

//tests the cases where the AVL tree does not have a pivot
//pre: a binary tree exists with items 
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testPivotCases(myAVLTree, inputFile, outputFile)
void testPivotCases (ifstream& inputFile, ofstream& outputFile);

//tests the cases where a new item is added to the short side of the AVL tree
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testShortSideCases(myAVLTree, inputFile, outputFile)
void testShortSideCases (ifstream& inputFile, ofstream& outputFile);

//tests the cases where in the AVL tree the search path goes right then right
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testSingleRotateLeftCases(myAVLTree, inputFile, outputFile)
void testSingleRotateLeftCases (ifstream& inputFile, ofstream& outputFile);

//tests the cases where in the AVL tree the search path goes left then left
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testSingleRotateRightCases(myAVLTree, inputFile, outputFile)
void testSingleRotateRightCases (ifstream& inputFile, ofstream& outputFile);

//tests the cases in the AVL tree where the search path goes left then right
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testDoubleRotateLeftRightCases(myAVLTree, inputFile, outputFile)
void testDoubleRotateLeftRightCases (ifstream& inputFile, ofstream& outputFile);

//tests the cases in the AVL tree where the search path goes right then left
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testDoubleRotateRightLeftCases(myAVLTree, inputFile, outputFile)
void testDoubleRotateRightLeftCases (ifstream& inputFile, ofstream& outputFile);

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	openInputFile(inputFile, "in.dat");
	openOutputFile(outputFile, "avl.dat");
	testPivotCases (inputFile, outputFile);
	testShortSideCases (inputFile, outputFile);
	testSingleRotateLeftCases (inputFile, outputFile);
	testSingleRotateRightCases (inputFile, outputFile);
	testDoubleRotateLeftRightCases (inputFile, outputFile);
	testDoubleRotateRightLeftCases (inputFile, outputFile);
	return 0;
}

// opens an input file with a chosen name
// pre filename is assigned
// post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
// usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename) 
{
	inputFile.open(filename);
	if (inputFile.fail())
	{
		cout << "File failed to open!!!!" << endl;
		exit(1);
	}
}

// opens an output file with a chosen name
// pre: filename is assigned
// post: if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
// usage: openOutputFile(infile, filename);
void openOutputFile(ofstream& outfile, string filename)
{
	outfile.open(filename);
	if (outfile.fail())
	{
		cout << "ERROR: cannot open in.dat. BOLTING" << endl;
		exit(1); 
	}
}

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines, ofstream& outputFile)
{
	for (int k = 0; k < numberOfLines; k++)
		outputFile << endl;
}

// prints an exception message
// pre except has been thrown
// post except is printed to the screen with two newlines before and after
// usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except)
{
	cout << endl << endl;
	cout << except.what();
	cout << endl << endl;
}

// runs cases using input file by printing case name, as well as pre and post trees
// pre: inputFile, myCase, and outputFile exist and inputFile and outputFile are open
// post: items are added to AVL tree from inputFile and pre and post trees are outputted
//       to outputFile
// usage: doCaseHelper(inputFile, "CASE1", outputFile);
void doCaseHelper (istream& inputFile, string myCase, ofstream& outputFile)
{
	AVLTree myAVLTree;
	int count;
	Item myItem;
	inputFile >> count;
	for (int i = 0; i < count - 1; i++)
	{
		inputFile >> myItem;
		try
		{
			myAVLTree.addNewEntry(myItem);
		}
		catch (Exception except)
		{
			printExceptionMessage(except);
		}
	}
	outputFile << myCase;
	printNewLines(2, outputFile);
	outputFile << "Pre Tree:" << endl;
	myAVLTree.prettyDisplay(outputFile);
	printNewLines(1, outputFile);
	inputFile >> myItem;
	outputFile << "Adding " << myItem << "to AVL tree" << endl << endl;
	outputFile << "Post Tree: " << endl;
	myAVLTree.addNewEntry(myItem);
	myAVLTree.prettyDisplay(outputFile);
	printNewLines(1, outputFile);
}

//tests the cases where the AVL tree does not have a pivot
//pre: a binary tree exists with items 
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testPivotCases(myAVLTree, inputFile, outputFile)
void testPivotCases (ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "----------------------------------PIVOT CASES----------------------------------";
	printNewLines(2, outputFile);
	doCaseHelper(inputFile, "CASE1: EMPTY TREE", outputFile);
	doCaseHelper(inputFile, "CASE2: ADDED TO TREE OF HEIGHT 1 LEFTCHILD", outputFile);
	doCaseHelper(inputFile, "CASE3: ADDED TO TREE OF HEIGHT 1 RIGHTCHILD", outputFile);
	doCaseHelper(inputFile, "CASE4: ADDED TO BALANCED TREE OF HEIGHT 2", outputFile);
	doCaseHelper(inputFile, "CASE5: ADDED TO BALANCED TREE OF HEIGHT 2", outputFile);
	doCaseHelper(inputFile, "CASE6: ADDED TO BALANCED TREE OF HEIGHT 2", outputFile);
}

//tests the cases where a new item is added to the short side of the AVL tree
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testShortSideCases(myAVLTree, inputFile, outputFile)
void testShortSideCases (ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------------SHORT SIDE CASES--------------------------------";
	printNewLines(2, outputFile);
	doCaseHelper(inputFile, "CASE1: ADDED TO TREE OF HEIGHT 2 SHORT LEFTCHILD", outputFile);
	doCaseHelper(inputFile, "CASE2: ADDED TO TREE OF HEIGHT 2 SHORT RIGHTCHILD", outputFile);
	doCaseHelper(inputFile, "CASE3: ADDED TO LEFTCHILD OF LEFTCHILD OF TREE HEIGHT 3", outputFile);
	doCaseHelper(inputFile, "CASE4: ADDED TO LEFTCHILD OF RIGHTCHILD OF TREE HEIGHT 3", outputFile);
	doCaseHelper(inputFile, "CASE5: ADDED TO RIGHTCHILD OF LEFTCHILD OF TREE HEIGHT 3", outputFile);
	doCaseHelper(inputFile, "CASE6: ADDED TO RIGHTCHILD OF RIGHTCHILD OF TREE HEIGHT 3", outputFile);
} 

//tests the cases where in the AVL tree the search path goes right then right
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testSingleRotateLeftCases(myAVLTree, inputFile, outputFile)
void testSingleRotateLeftCases (ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "---------------------------SINGLE ROTATE LEFT CASES----------------------------";
	printNewLines(2, outputFile);
	doCaseHelper(inputFile, "CASE1: PIVOT IS THE ROOT AND T1 - T3 ARE HEIGHT 0", outputFile);
	doCaseHelper(inputFile, "CASE2: PIVOT IS THE ROOT AND T1 - T3 ARE HEIGHT 1", outputFile);
	doCaseHelper(inputFile, "CASE3: PIVOT IS THE RIGHTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 0", outputFile);
	doCaseHelper(inputFile, "CASE4: PIVOT IS THE RIGHTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 1", outputFile);
	doCaseHelper(inputFile, "CASE5: PIVOT IS THE LEFTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 0", outputFile);
	doCaseHelper(inputFile, "CASE6: PIVOT IS THE LEFTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 1", outputFile);
} 

//tests the cases where in the AVL tree the search path goes left then left
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testSingleRotateRightCases(myAVLTree, inputFile, outputFile)
void testSingleRotateRightCases (ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "---------------------------SINGLE ROTATE RIGHT CASES---------------------------";
	printNewLines(2, outputFile);
	doCaseHelper(inputFile, "CASE1: PIVOT IS THE ROOT AND T1 - T3 ARE HEIGHT 0", outputFile);
	doCaseHelper(inputFile, "CASE2: PIVOT IS THE ROOT AND T1 - T3 ARE HEIGHT 1", outputFile);
	doCaseHelper(inputFile, "CASE3: PIVOT IS THE RIGHTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 0", outputFile);
	doCaseHelper(inputFile, "CASE4: PIVOT IS THE RIGHTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 1", outputFile);
	doCaseHelper(inputFile, "CASE5: PIVOT IS THE LEFTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 0", outputFile);
	doCaseHelper(inputFile, "CASE6: PIVOT IS THE LEFTCHILD OF THE CLOUD AND T1 - T3 ARE HEIGHT 1", outputFile);
}

//tests the cases in the AVL tree where the search path goes left then right
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testDoubleRotateLeftRightCases(myAVLTree, inputFile, outputFile)
void testDoubleRotateLeftRightCases (ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------DOUBLE ROTATE LEFT RIGHT CASES-------------------------";
	printNewLines(2, outputFile);
	doCaseHelper(inputFile, "CASE1: PIVOT IS THE RIGHT CHILD OF THE CLOUD", outputFile);
	doCaseHelper(inputFile, "CASE2: PIVOT IS THE LEFT CHILD OF THE CLOUD", outputFile);
	doCaseHelper(inputFile, "CASE3: PIVOT IS THE ROOT OF THE TREE", outputFile);
	doCaseHelper(inputFile, "CASE4: PIVOT IS THE ROOT OF THE TREE AND T4 IS HEIGHT OF 1", outputFile);
	doCaseHelper(inputFile, "CASE5: PIVOT IS THE ROOT OF THE TREE AND T2 IS HEIGHT OF 1", outputFile);
	doCaseHelper(inputFile, "CASE6: PIVOT IS THE ROOT OF THE TREE AND T3 IS HEIGHT OF 1", outputFile);
	doCaseHelper(inputFile, "CASE7: PIVOT IS THE ROOT OF THE TREE AND T1 AND T4 ARE HEIGHTS OF 2", outputFile);
}

//tests the cases in the AVL tree where the search path goes right then left
//pre: a binary tree exists with items
//post: a new item is added to the tree, the AVL tree stays balanced, and
//      pre and post trees along with cases are outputted to avl.dat
//usage: testDoubleRotateRightLeftCases(myAVLTree, inputFile, outputFile)
void testDoubleRotateRightLeftCases (ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------DOUBLE ROTATE RIGHT LEFT CASES-------------------------";
	printNewLines(2, outputFile);
	doCaseHelper(inputFile, "CASE1: PIVOT IS THE RIGHT CHILD OF THE CLOUD", outputFile);
	doCaseHelper(inputFile, "CASE2: PIVOT IS THE LEFT CHILD OF THE CLOUD", outputFile);
	doCaseHelper(inputFile, "CASE3: PIVOT IS THE ROOT OF THE TREE", outputFile);
	doCaseHelper(inputFile, "CASE4: PIVOT IS THE ROOT OF THE TREE AND T4 IS HEIGHT OF 1", outputFile);
	doCaseHelper(inputFile, "CASE5: PIVOT IS THE ROOT OF THE TREE AND T2 IS HEIGHT OF 1", outputFile);
	doCaseHelper(inputFile, "CASE6: PIVOT IS THE ROOT OF THE TREE AND T3 IS HEIGHT OF 1", outputFile);
	doCaseHelper(inputFile, "CASE7: PIVOT IS THE ROOT OF THE TREE AND T1 AND T4 ARE HEIGHTS OF 2", outputFile);
}