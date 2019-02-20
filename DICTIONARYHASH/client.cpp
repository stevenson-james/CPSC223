// filename client.cpp
// authors James Stevenson and Jalen Tacsiat
// username: jstevenson4
// date September 25, 2018

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

void testInsertTextingAbbreviations(Dictionary& myDictionary, fstream& input)
{
	input >> myDictionary;
	cout << myDictionary << endl;
}

void testHashToSameAddress(Dictionary& myDictionary, fstream& input)
{
	input >> myDictionary;
	cout << myDictionary << endl;
}

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