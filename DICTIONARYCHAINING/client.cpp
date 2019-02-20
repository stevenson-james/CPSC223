// filename client.cpp
// authors James Stevenson and Cade Newell
// username: jstevenson4
// date October 2, 2018

#include "dictionary.h"
#include <iostream>
#include <fstream>
using namespace std;

void testInsertTextingAbbreviations(Dictionary&, fstream&);
void testHashToSameAddress(Dictionary&, fstream&);
void testSearchForMeanings(Dictionary&, fstream&);
void testDeleteSecondEntry(Dictionary&, fstream&);
void testSearchingForLastEntry(Dictionary&, fstream&);

int main()
{
	Dictionary myDictionary;
	Item myItem;
	fstream input("in.dat");
	testInsertTextingAbbreviations(myDictionary, input);
	testHashToSameAddress(myDictionary, input);
	testSearchForMeanings(myDictionary, input);
	testDeleteSecondEntry(myDictionary, input);
	testSearchingForLastEntry(myDictionary, input);
	return 0;
}

// testing 3a from assignment specifications
void testInsertTextingAbbreviations(Dictionary& myDictionary, fstream& input)
{
	input >> myDictionary;
	cout << myDictionary << endl;
}

// testing 3b from assignment specifications
void testHashToSameAddress(Dictionary& myDictionary, fstream& input)
{
	input >> myDictionary;
	cout << myDictionary << endl;
}

// testing 3c from assignment specifications
void testSearchForMeanings(Dictionary& myDictionary, fstream& input)
{
	Key firstAbbreviation, secondAbbreviation;
	Item firstEntry, secondEntry;
	bool isFound;
	
	input >> firstAbbreviation >> secondAbbreviation;
	cout << "Searching for " << firstAbbreviation << " and " << secondAbbreviation << endl;
	myDictionary.searchForMeaning(firstAbbreviation, firstEntry, isFound);
	cout << "Dictionary entry for " << firstAbbreviation << " is:  " << firstEntry;
	myDictionary.searchForMeaning(secondAbbreviation, secondEntry, isFound);
	cout << "Dictionary entry for " << secondAbbreviation << " is:  " << secondEntry << endl;
}

// testing 3d from assignment specifications
void testDeleteSecondEntry(Dictionary& myDictionary, fstream& input)
{
	Key secondAbbreviation;
	bool isEmpty, isFound;
	input >> secondAbbreviation;
	cout << "Deleting " << secondAbbreviation << endl;
	myDictionary.deleteEntry(secondAbbreviation, isEmpty, isFound);
	cout << "Printing dictionary with " << secondAbbreviation << " deleted: " << endl;
	cout << myDictionary << endl;
}

// testing 3e from assignment specifications
void testSearchingForLastEntry(Dictionary& myDictionary, fstream& input)
{
	Key lastAbbreviation;
	Item lastEntry;
	bool isFound = true;
	
	input >> lastAbbreviation;
	cout << "Searching for " << lastAbbreviation << endl;
	myDictionary.searchForMeaning(lastAbbreviation, lastEntry, isFound);
	cout << "Dictionary entry for " << lastAbbreviation << " is:  " << lastEntry;
}