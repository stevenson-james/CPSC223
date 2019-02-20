//names: James Stevenson and Cade Newell
//date: December 4, 2018
//username: jstevenson4
//clientprogram.cpp
/*
This program runs case tests for different 234 Trees based upon the five cases outlined in the
programming assignment document in two34treenode.cpp. There is no user input, rather the inputs
and outputs are from in.dat and to two.dat respectively
*/

#include"two34tree.h"
#include<iostream>
#include<fstream>
#include <string>

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

//adds keys to tree based upon file inputFile and outputs the pre tree,
//		last key being added, and post tree to outputFile
//pre: input and output file are open
//post: pre tree, last key add to 234 tree, and post tree are outputted
//		to outputFile with nice formatting
//usage: addingEntries(inputFile, outputFile);
void addingEntries(ifstream& inputFile, ofstream& outputFile);

// this function runs tests for adding an item into the root node
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseOne(inputFile, outputFile)
void caseOne(ifstream& inputFile, ofstream& outputFile);

// this function runs tests for adding an item into the root node and splits it
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseTwo(inputFile, outputFile)
void caseTwo(ifstream& inputFile, ofstream& outputFile);

// this function runs tests for adding an item into the 2nd level nodes 
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseThree(inputFile, outputFile)
void caseThree(ifstream& inputFile, ofstream& outputFile);

// this function runs tests for adding an item to split 2nd level nodes 
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseFour(inputFile, outputFile)
void caseFour(ifstream& inputFile, ofstream& outputFile);

// this function runs tests for adding an item into pre-split 2nd level nodes 
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseFive(inputFile, outputFile)
void caseFive(ifstream& inputFile, ofstream& outputFile);

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	
	openInputFile(inputFile, "in.dat");
	openOutputFile(outputFile, "two.dat");

	caseOne(inputFile, outputFile);
	caseTwo(inputFile, outputFile);
	caseThree(inputFile, outputFile);
	caseFour(inputFile, outputFile);
	caseFive(inputFile, outputFile);
	inputFile.close();
	outputFile.close();
	
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

//adds keys to tree based upon file inputFile and outputs the pre tree,
//		last key being added, and post tree to outputFile
//pre: input and output file are open
//post: pre tree, last key add to 234 tree, and post tree are outputted
//		to outputFile with nice formatting
//usage: addingEntries(inputFile, outputFile);
void addingEntries(ifstream& inputFile, ofstream& outputFile)
{	
	Key myKey;
	Two34Tree myTree;
	int stop;
	
	inputFile >> stop;
	for (int i = 0; i < stop - 1; i++)
	{
		inputFile >> myKey;
		myTree.addNewEntry(myKey);
	}
	
	outputFile << endl << "PRE TREE: " << endl;
	myTree.display(outputFile, 'p');
	outputFile << endl;
	
	inputFile >> myKey;
	outputFile << "Adding...(" << myKey << ")" << endl;
	myTree.addNewEntry(myKey);
	
	outputFile << endl << "POST TREE: " << endl;
	myTree.display(outputFile, 'p');
	outputFile << endl;
}

// this function runs tests for adding an item into the root node
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseOne(inputFile, outputFile)
void caseOne(ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------CASE 1: ADDING TO THE ROOT-------------------------" << endl;
	outputFile << "ADDING TO ROOT; ADDING TO AN EMPTY TREE" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO ROOT; ONE ITEM IN THE TREE, ADDING BEFORE THE ITEM" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO ROOT; ONE ITEM IN THE TREE, ADDING AFTER THE ITEM" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO ROOT; TWO ITEMS IN THE TREE, ADDING BEFORE THE ITEMS" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO ROOT; TWO ITEMS IN THE TREE, ADDING INBETWEEN THE ITEMS" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO ROOT; TWO ITEMS IN THE TREE, ADDING AFTER THE ITEMS" << endl;
	addingEntries(inputFile, outputFile);
}

// this function runs tests for adding an item into the root node and splits it
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseTwo(inputFile, outputFile)
void caseTwo(ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------CASE 2: SPLITTING THE ROOT-------------------------" << endl;
	outputFile << "ADDING TO THE BEGINING OF THE FIRST CHILD" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE END OF THE FIRST CHILD" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE BEGINING OF THE SECOND CHILD" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE END OF THE SECOND CHILD" << endl;
	addingEntries(inputFile, outputFile);
}

// this function runs tests for adding an item into the 2nd level nodes 
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseThree(inputFile, outputFile)
void caseThree(ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------CASE 3: ADDING TO LEVEL TWO-------------------------" << endl;
	outputFile << "ADDING TO THE BEGINING OF THE FIRST CHILD NODE" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE MIDDLE OF THE FIRST CHILD NODE" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE END OF THE FIRST CHILD NODE" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE BEGINING OF THE SECOND CHILD NODE" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE MIDDLE OF THE SECOND CHILD NODE" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO THE END OF THE SECOND CHILD NODE" << endl;
	addingEntries(inputFile, outputFile);
}

// this function runs tests for adding an item to split 2nd level nodes 
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseFour(inputFile, outputFile)
void caseFour(ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-------------------------CASE 4: SPLITTING LEVEL TWO-------------------------" << endl;
	outputFile << "SPLITTING FIRST CHILD, ADDING BEFORE FIRST CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING FIRST CHILD, ADDING AFTER FIRST CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING FIRST CHILD, ADDING BEFORE SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING FIRST CHILD, ADDING AFTER SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING SECOND CHILD, ADDING BEFORE SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING SECOND CHILD, ADDING AFTER SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING SECOND CHILD, ADDING BEFORE THIRD CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "SPLITTING SECOND CHILD, ADDING AFTER THIRD CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	
}

// this function runs tests for adding an item into pre-split 2nd level nodes 
// pre: input and output files are open
// post: subcases are run based on subcase titles and outputted to outputFile
// usage: caseFive(inputFile, outputFile)
void caseFive(ifstream& inputFile, ofstream& outputFile)
{
	outputFile << "-----------------------CASE 5: ADDING TO SPLIT LEVEL TWO-----------------------" << endl;
	outputFile << "ADDING TO BEGINNING OF THE FIRST CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO MIDDLE OF THE FIRST CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO END OF THE FIRST CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO BEGINNING OF THE SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO MIDDLE OF THE SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO END OF THE SECOND CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO BEGINNING OF THE THIRD CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO MIDDLE OF THE THIRD CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
	outputFile << "ADDING TO END OF THE THIRD CHILD OF ROOT" << endl;
	addingEntries(inputFile, outputFile);
}


	
	
	
	
	