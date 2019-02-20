//file clientprogram.cpp
//names: Cade Newell and James Stevenson
//username: jstevenson4
//date: 10/31/18
/*
This program creates a dictinoary of texting abbreviations and lets the client decide what
	they want to do with the texting abbreviations. The client has the option to insert
	a new texting abbreviation, search for an abbreviation, list the abbreviations on the
	screen, print the texting abbreviations (in a PRETTY fashion) to the screen, rebalance 
	the texting abbreviation(which involves turning the inorder texting abbreviations into 
	a full tree), save the dictionary that was created to a file(dictionary.dat) and finally 
	exiting the program.
*/

#include "binarysearchtree.h"
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
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines);

// prints an exception message
// pre: except has been thrown
// post: except is printed to the screen with two newlines before and after
// usage: PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

// initializes the BinarySearchTree by putting items in it from dictinoary.dat
// pre: BinarySearchTree exists, but its empty
// post: items have been added to the BinarySearchTree from dictionary.dat
// usage: fillBinarySearchTree(myItem, infile);
void fillBinarySearchTree (BinarySearchTree& myTree, ifstream& infile);

// creates a USER-FRIENDLY menu that shows the options the client can select
// pre: BinarySearchTree exists
// post: a user friendly menu has been printed to the screen with the ability to 
//       choose what option they wants to proceed with 
// usage: diplayMenu();
void displayMenu();

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

// lists the items in the dictionary using a recursive inorder helper
// pre: BinarySearchTree exists, with Items stored in it
// post: the items in the dictionary have been listed in alphabetical order to the screen
// usage: listItemsInDictionary(myBinarySearchTree);
void listItemsInDictionary(BinarySearchTree& myBinarySearchTree);

// prints the dictionary keys to the screen in a pretty manner
// pre: BinarySearchTree exists, with Items stored in it
// post: texting abbreviations are printed to the screen in the shape of a binary tree 
// usage: printTreeToScreen(myBinarySearchTree);
void printTreeToScreen(BinarySearchTree& myBinarySearchTree);

// rebalances the tree by reordering the tree from left to right
// pre: BinarySearchTree exists, with Items stored in it
// post: the BinarySearchTree is reordered in a fashion to be printed out
// usage: rebalanceTree(Infile, myBinarySearchTree);
void rebalanceTree(ifstream& infile, ofstream& outfile, BinarySearchTree& myBinarySearchTree);

// saves the BinarySearchTree to the file "dictionary.dat"
// pre: BinarySearchTree exists, with Items stored in it, and the output file is opened
// post: the texting items from the BinarySearchTree are saved to a file
// usage: saveDictionaryToFile(outfile, myBinarySearchTree);
void saveDictionaryToFile(ofstream& outfile, BinarySearchTree& mybinarysearchtree);

// checks to see if the option the user selected is a valid state
// the menu has been opened and the user has made a selection
// post: the program checks to see if the selection that the user made is valid 
// usage: isAnOption(myBinarySearchTree);
bool isAnOption(char& selection);

// the options for which part the user can run are listed, then the user takes an input
// pre: the command options for the program are listed
// post: the program takes an input for the user
// usage: inputMenuOption(myBinarySearchTree);
void inputMenuOption(char& selection);

// takes the client input and decides which funciton to run
// pre: the client has made an input selection that are one of the options
// post: the program runs whichever function that the client requested 
// usage: runMenuOption(myBinarySearchTree);
void runMenuOption(char& selection, ifstream& infile, ofstream& outfile, BinarySearchTree& myBinarySearchTree);

// deletes an item from the dictioanry
// pre: the BinarySearchTree is filled with Items
// post: an Item, of the users choice, is deleted
// usage: deleteDictionaryItem(outfile, myBinarySearchTree);
void deleteDictionaryItem(ofstream& outfile, BinarySearchTree& myBinarySearchTree);

// saves the BinarySearchTree to the file "dictionary.dat" and outputs a nice message
// pre: BinarySearchTree exists, with Items stored in it, and the output file is opened
// post: the texting items from the BinarySearchTree are saved to a file and message
//       is printed to screen
// usage: exitDictionary(outfile, myBinarySearchTree);
void exitDictionary(ofstream& outfile, BinarySearchTree& myBinarySearchTree);

int main()
{
	char selection;
	ifstream infile;
	ofstream outfile;
	BinarySearchTree myBinarySearchTree;
	
	printNewLines(1);
	fillBinarySearchTree(myBinarySearchTree, infile);
	while (selection != 'e')
	{
		displayMenu();
		inputMenuOption(selection);
		runMenuOption(selection, infile, outfile, myBinarySearchTree);
	}
	exitDictionary(outfile, myBinarySearchTree);
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

// creates a USER-FRIENDLY menu that shows the options the client can select
// pre: BinarySearchTree exists
// post: a user friendly menu has been printed to the screen with the ability to 
//       choose what option they wants to proceed with 
// usage: diplayMenu();
void displayMenu()
{
	cout << "Your options are:";
	printNewLines(2);
	cout << "f  : find the meaning of a texting abbreviation, given the text" << endl;
	cout << "i  : insert a new item (texting abbreviation and meaning ) into the dictionary" << endl;
	cout << "l  : list the items of the entire dictionary on the screen in inorder fashion" << endl;
	cout << "p  : print the tree in pretty fashion (showing only the texts)" << endl;
	cout << "r  : rebalance the tree" << endl;
	cout << "d  : delete an item from the dictionary (only a leaf or a parent with one child)" << endl;
	cout << "s  : save the dictionary to the file in sorted order -– inorder --  ready to be read" << endl;
	cout << "e  : exit the program which automatically does option s";
	printNewLines(2);
	cout << "Enter your option > ";
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
	cout << "Enter a texting abbreviation to search for" << endl;
	cin >> targetText;
	myBinarySearchTree.searchForMeaning(targetText, myItem, isFound);
	printNewLines(1);
	if (isFound)
	{
		cout << "Matching meaning to the texting abbreviation..." << endl;
		cout << myItem;
		printNewLines(2);
	}
	else
	{
		cout << targetText << " was not found in dictionary";
		printNewLines(2);
	}
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
	printNewLines(1);
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

// lists the items in the dictionary using a recursive inorder helper
// pre: BinarySearchTree exists, with Items stored in it
// post: the items in the dictionary have been listed in alphabetical order to the screen
// usage: listItemsInDictionary(myBinarySearchTree);
void listItemsInDictionary(BinarySearchTree& myBinarySearchTree)
{
	printNewLines(1);
	myBinarySearchTree.BinaryTree::inorderTraverse(cout);
	printNewLines(2);
}

// prints the dictionary keys to the screen in a pretty manner
// pre: BinarySearchTree exists, with Items stored in it
// post: texting abbreviations are printed to the screen in the shape of a binary tree 
// usage: printTreeToScreen(myBinarySearchTree);
void printTreeToScreen(BinarySearchTree& myBinarySearchTree)
{
	myBinarySearchTree.prettyDisplay();
	printNewLines(1);
}

// rebalances the tree by reordering the tree from left to right
// pre: BinarySearchTree exists, with Items stored in it
// post: the BinarySearchTree is reordered in a fashion to be printed out
// usage: rebalanceTree(Infile, myBinarySearchTree);
void rebalanceTree(ifstream& infile, ofstream& outfile, BinarySearchTree& myBinarySearchTree)
{
	saveDictionaryToFile(outfile, myBinarySearchTree);
	openInputFile(infile, "dictionary.dat");
	try
	{
		myBinarySearchTree.rebalanceBinaryTree(infile);
	}
	catch (Exception except)
	{
		printExceptionMessage(except);
	}
	infile.close();
}

// saves the BinarySearchTree to the file "dictionary.dat"
// pre: BinarySearchTree exists, with Items stored in it, and the output file is opened
// post: the texting items from the BinarySearchTree are saved to a file
// usage: saveDictionaryToFile(outfile, myBinarySearchTree);
void saveDictionaryToFile(ofstream& outfile, BinarySearchTree& myBinarySearchTree)
{
	openOutputFile(outfile, "dictionary.dat");
	myBinarySearchTree.inorderTraverse(outfile);
	outfile.close();
	printNewLines(1);
}

// checks to see if the option the user selected is a valid state
// the menu has been opened and the user has made a selection
// post: the program checks to see if the selection that the user made is valid 
// usage: isAnOption(myBinarySearchTree);
bool isAnOption(char& selection)
{
	return selection != 'f' && selection != 'i' && selection != 'l' && 
	selection != 'p' && selection != 'r' && selection != 's' && selection != 'e'
	&& selection != 'd';
}

// the options for which part the user can run are listed, then the user takes an input
// pre: the command options for the program are listed
// post: the program takes an input for the user
// usage: inputMenuOption(myBinarySearchTree);
void inputMenuOption(char& selection)
{
	cin >> selection;
	while (isAnOption(selection))
	{
		cout << "Enter one of the listed letters > ";
		cin >> selection;
	}
}

// takes the client input and decides which funciton to run
// pre: the client has made an input selection that are one of the options
// post: the program runs whichever function that the client requested 
// usage: runMenuOption(myBinarySearchTree);
void runMenuOption(char& selection, ifstream& infile, ofstream& outfile, BinarySearchTree& myBinarySearchTree)
{
	if (selection == 'f')
		findAbbreviation(myBinarySearchTree);
	else if (selection == 'i')
		insertNewItem(infile, myBinarySearchTree);
	else if (selection == 'l')
		listItemsInDictionary(myBinarySearchTree);
	else if (selection == 'p')
		printTreeToScreen(myBinarySearchTree);
	else if (selection == 'r')
		rebalanceTree(infile, outfile, myBinarySearchTree);
	else if (selection == 's')
		saveDictionaryToFile(outfile, myBinarySearchTree);
	else if (selection == 'd')
		deleteDictionaryItem(outfile, myBinarySearchTree);
}

// deletes an item from the dictioanry
// pre: the BinarySearchTree is filled with Items
// post: an Item, of the users choice, is deleted
// usage: deleteDictionaryItem(outfile, myBinarySearchTree);
void deleteDictionaryItem(ofstream& outfile, BinarySearchTree& myBinarySearchTree)
{
	openOutputFile(outfile, "dictionary.dat");

	Key targetText;

	printNewLines(1);
	cout << "Enter in a target abbreviation to delete (must be a leaf or parent with only one child) > ";
	cin >> targetText;
	
	try
	{
	myBinarySearchTree.deleteEntry(targetText);
	}
	catch(Exception except)
	{
		printExceptionMessage(except);
	}
	printNewLines(1);
	outfile.close();
}

// saves the BinarySearchTree to the file "dictionary.dat" and outputs a nice message
// pre: BinarySearchTree exists, with Items stored in it, and the output file is opened
// post: the texting items from the BinarySearchTree are saved to a file and message
//       is printed to screen
// usage: exitDictionary(outfile, myBinarySearchTree);
void exitDictionary(ofstream& outfile, BinarySearchTree& myBinarySearchTree)
{
	saveDictionaryToFile(outfile, myBinarySearchTree);
	cout << "Dictionary saved and exited. Thank you for using Cade and James's dictionary!";
	printNewLines(2);
	outfile.close();
}