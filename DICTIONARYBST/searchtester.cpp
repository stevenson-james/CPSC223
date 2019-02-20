//file searchtester.cpp
//authors James Stevenson and Cade Newell
//username: jstevenson4
//date October 28, 2018

// searchtester.cpp: this tester checks the ability to add a new Item into the 
//             BinarySearchTree as well as being able to search for it
//			   this also loads all the inputed new files to "dictionary.dat"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "binarysearchtree.h"
using namespace std;

// prints an exception message
// pre except has been thrown
// post except is printed to the screen with two newlines before and after
// usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines);

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

// initializes the BinarySearchTree by putting items in it from dictinoary.dat
// pre: BinarySearchTree exists, but its empty
// post: items have been added to the BinarySearchTree from dictionary.dat
// usage: fillBinarySearchTree(myItem, infile);
void fillBinarySearchTree (BinarySearchTree& myTree, ifstream& infile);

// finds a texting abbreviation in the BinarySearchTree 
// pre: BinarySearchTree exists, texting abbreviation is entered in the terminal
// post: displays the texting abbreviation followed by the meaning of the Key entered
// usage: findAbbreviation(myBinarySearchTree);
void findAbbreviation(BinarySearchTree& myBinarySearchTree);

// inserts a new Item into the BinarySearchTree
// pre: BinarySearchTree exists, with Items stored in it
// post: an item is inserted into the BinarySearchTree 
// usage: insertNewItem(infile, myBinarySearchTree);
void insertNewItem(ifstream& infile, BinarySearchTree& myBinarySearchTree);


int main()
{
	BinarySearchTree myBinarySearchTree;
	ifstream infile;
	
    fillBinarySearchTree (myBinarySearchTree, infile);
	insertNewItem(infile, myBinarySearchTree);
	findAbbreviation(myBinarySearchTree);
	
	cout << endl;
	
	
	return 0;
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
		cout << "ERROR: cannot open dictionary.dat. BOLTING" << endl;
		exit(1); 
	}
}

// initializes the BinarySearchTree by putting items in it from dictinoary.dat
// pre: BinarySearchTree exists, but its empty
// post: items have been added to the BinarySearchTree from dictionary.dat
// usage: fillBinarySearchTree(myItem, infile);
void fillBinarySearchTree (BinarySearchTree& myTree, ifstream& infile)
{
	openInputFile(infile, "dictionary.dat");
	int num;
	Item myItem;
	infile >> num;
	for (int i = 0; i < num; i++)
	{
		infile >> myItem;
		myTree.addNewEntry(myItem);
	}
	infile.close();
}

// inserts a new Item into the BinarySearchTree
// pre: BinarySearchTree exists, with Items stored in it
// post: an item is inserted into the BinarySearchTree 
// usage: insertNewItem(infile, myBinarySearchTree);
void insertNewItem(ifstream& infile, BinarySearchTree& myBinarySearchTree)
{
	Item myItem;
	openInputFile(infile, "dictionary.dat");
	printNewLines(1);
	cout << "Enter in an Item to add to the BinarySearchTree (texting abbreviation and meaning) > ";
	cin >> myItem;
	try
	{
		myBinarySearchTree.addNewEntry(myItem);
	}
	catch(Exception except)
	{
		printExceptionMessage(except);
	}
	infile.close();
}



// finds a texting abbreviation in the BinarySearchTree 
// pre: BinarySearchTree exists, texting abbreviation is entered in the terminal
// post: displays the texting abbreviation followed by the meaning of the Key entered
// usage: findAbbreviation(myBinarySearchTree);
void findAbbreviation(BinarySearchTree& myBinarySearchTree)
{
	Key targetText;
	Item myItem;
	bool isFound;
	printNewLines(1);
	cout << "Enter a texting abbreviation to search for > ";
	cin >> targetText;
	myBinarySearchTree.searchForMeaning(targetText, myItem, isFound);
	printNewLines(1);
	cout << "Matching meaning to the texting abbreviation..." << endl;
	cout << myItem << endl;
	printNewLines(1);
}




