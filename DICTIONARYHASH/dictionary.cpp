// filename dictionary.cpp
// authors James Stevenson and Jalen Tacsiat
// username: jstevenson4
// date September 25, 2018
// Implementation of Abstract Data Type Dictionary
//
//     data object: a bunch of texting abbreviations and their meanings 
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output

#include "dictionary.h"

const int TABLESIZE = 11;

// returns address of some texting abbreviation
// using function convert to integer and modding
// with size of dictionary hash table
// pre: myKey is a texting abbreviation, TABLESIZE is
//	    greater than or equal to zero
// post: returns address of myKey (texting abbreviation)
int hashFunction(const Key& myKey)
{
	return myKey.convertToInteger() % TABLESIZE;
}

struct DictionaryRecord
{
	Item* hashTablePtr;
	int numberStored;
};

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address    text       meaning
//          0        lol       laugh out loud
//          1        ttyl      talk to you later
// usage: outfile << myDictionary;     
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	Item myItem;
	output << "address\ttext\tmeaning\t" << endl;
	for (int i = 0; i < TABLESIZE; i++)
		output << i << "\t" << rightHandSideDictionary.dictionaryPtr->hashTablePtr[i];
	return output;
}

// inputs items into a dictionary using linear probing
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      2
//      lol
//      laugh out loud
//      ttyl
//      talk to you later
// post: if there is room, 
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
istream& operator>> (istream& input, Dictionary& rightHandSideDictionary)
{
	int numberOfInputs;
	bool isFull, isAlreadyThere;
	input >> numberOfInputs;
	input.ignore();
	Item myItem;
	for (int i = 0; i < numberOfInputs; i++)
	{
		input >> myItem;
		isFull = rightHandSideDictionary.dictionaryPtr->numberStored == TABLESIZE;
		isAlreadyThere = rightHandSideDictionary.dictionaryPtr->hashTablePtr[hashFunction(myItem)] == myItem;
		rightHandSideDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
	}
	return input;
}

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;	
Dictionary::Dictionary()
{
	dictionaryPtr = new DictionaryRecord;
	dictionaryPtr->hashTablePtr = new Item[TABLESIZE];
	dictionaryPtr->numberStored = 0;
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
	dictionaryPtr = NULL;
}

// searches for a meaning with a given text
// pre targetText has been assigned 
// post if an item with texting abbreviation the same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void Dictionary::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
	int address = hashFunction(targetText);
	int previousAddress = (address - 1) % TABLESIZE;
	isFound = dictionaryPtr->hashTablePtr[address] == targetText;
	while (not isFound and previousAddress != address and not dictionaryPtr->hashTablePtr[address].isEmpty())
	{
		address = (address + 1) % TABLESIZE;
		isFound = dictionaryPtr->hashTablePtr[address] == targetText;
	}
	if (isFound)
		anItem = dictionaryPtr->hashTablePtr[address];
}

// inserts a new text item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object and newItem's text
//            is not already there  isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
void Dictionary::addNewEntry(const Item& newItem, bool& isFull, bool& isAlreadyThere)
{
	int address = hashFunction(newItem);
	isFull = dictionaryPtr->numberStored == TABLESIZE;
	if (not isFull)
	{
		isAlreadyThere = dictionaryPtr->hashTablePtr[address] == newItem;
		while (not dictionaryPtr->hashTablePtr[address].isEmpty() and not isAlreadyThere 
			   and not dictionaryPtr->hashTablePtr[address].hasBeenMarked())
		{
			address = (address + 1) % TABLESIZE;
			isAlreadyThere = dictionaryPtr->hashTablePtr[address] == newItem;
		}
		if (not isAlreadyThere)
		{
			dictionaryPtr->hashTablePtr[address] = newItem;
			dictionaryPtr->numberStored++;
		}
	}
}

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if Dictionary object is not empty and 
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the Dictionary object 
//       else isFound is false or isEmpty is true depending
// usage: myDictionary.deleteEntry(myText, isEmpty, isFound);
void Dictionary::deleteEntry(const Key& targetText, bool& isEmpty, bool& isFound)
{
	int address = hashFunction(targetText);	
	int previousAddress = (address - 1) % TABLESIZE;
	isEmpty = dictionaryPtr->numberStored == 0;
	if (not isEmpty)
	{ 
		isFound = dictionaryPtr->hashTablePtr[address] == targetText;
		while (not isFound and previousAddress != address and not dictionaryPtr->hashTablePtr[address].isEmpty())
		{
			address = (address + 1) % TABLESIZE;
			isFound = dictionaryPtr->hashTablePtr[address] == targetText;
		}
		if (isFound)
		{
			dictionaryPtr->hashTablePtr[address].markIt();
			dictionaryPtr->numberStored--;
		}
	}
}

// returns number of entries in dictionary
// pre: Dictionary object exists
// post: returns numberStored (number of entries in dictionary)
// usage: myDictionary.getNumberOfEntries();
int Dictionary::getNumberOfEntries()
{
	return dictionaryPtr->numberStored;
}
