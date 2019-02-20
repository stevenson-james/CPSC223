// filename dictionary.cpp
// authors James Stevenson and Cade Newell
// username: jstevenson4
// date October 2, 2018
// Implementation of Abstract Data Type Dictionary
//
//     data object: a bunch of texting abbreviations and their meanings
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output

#include "dictionary.h"
#include "stack.h"

const int TABLESIZE = 11;

// prints stack to screen
// pre: object myStack exists
// post: prints what is in myStack using pass by value
void printStack(Stack myStack)
{
    Item topItem;
    while (not myStack.isEmpty())
    {
        myStack.getTop(topItem);
        cout << "\t->\t"<< topItem;
        myStack.pop();
    }
}

// looks for an item with same texting abbreviation as targetText
// pre: object myStack exists, isFound is false
// post: if found, saves texting abbreviation and meaning to anItem and sets isFound to true
// else isFound is false and anItem is empty
void searchStack (Stack myStack, const Key& targetText, Item& anItem, bool& isFound)
{
	Item myItem;
	while (not myStack.isEmpty() && not isFound)
	{
		myStack.getTop(myItem);
		myStack.pop();
		if (myItem == targetText)
		{
			anItem = myItem;
			isFound = true;
		}
	}
}

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
	Stack* hashTablePtr;
	int numberStored;
};

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example (caveat: these texts may hash to a different address)
//       address       text  meaning
//           0:
//                ->   lol   laugh out loud
//                ->   ttyl  talk to you later
//           1:
//                ->   smh   shake my head
// usage: outfile << myDictionary;
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	Item copyItem;
	output << "address\t\ttext\tmeaning\t" << endl;
	for (int i = 0; i < TABLESIZE; i++)
    {
		output << i << ":" << endl;
		printStack(rightHandSideDictionary.dictionaryPtr->hashTablePtr[i]);
    }
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
	bool isFull = false, isAlreadyThere = false;
	input >> numberOfInputs;
	input.ignore();
	Item myItem;
	for (int i = 0; i < numberOfInputs; i++)
	{
		input >> myItem;
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
	dictionaryPtr->hashTablePtr = new Stack[TABLESIZE];
	dictionaryPtr->numberStored = 0;
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
	dictionaryPtr = nullptr;
}

// searches for a meaning with a given text
// pre targetText has been assigned a value not already in the hash table
// post if an item with texting abbreviation the same as targetText is found then
//          isFound is true and anItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void Dictionary::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
    isFound = false;
	int address = hashFunction(targetText);
	searchStack(dictionaryPtr->hashTablePtr[address], targetText, anItem, isFound);
}

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object and newItem's text
//            is not already there  isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);

//did this guy in class
void Dictionary::addNewEntry(const Item& newItem, bool& isFull, bool& isAlreadyThere)
{
	int address = hashFunction(newItem);
	isAlreadyThere = false;
	isFull = false;
	bool isAdded;
    dictionaryPtr->hashTablePtr[address].push(newItem, isAdded);
    dictionaryPtr->numberStored++;
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
	isEmpty = dictionaryPtr->numberStored == 0;
    isFound = false;
	if (not isEmpty)
	{
	    int address = hashFunction(targetText);
	    Stack copyStack;
	    Item copyItem;
	    bool isAdded;
		while (not isFound and not dictionaryPtr->hashTablePtr[address].isEmpty())
		{
		    dictionaryPtr->hashTablePtr[address].getTop(copyItem);
		    isFound = copyItem == targetText;
			dictionaryPtr->hashTablePtr[address].pop();
			if (not isFound)
                copyStack.push(copyItem, isAdded);
		}
		if (isFound)
		{
		    while (not copyStack.isEmpty())
            {
                copyStack.getTop(copyItem);
                dictionaryPtr->hashTablePtr[address].push(copyItem, isAdded);
                copyStack.pop();
            }
            dictionaryPtr->numberStored--;
		}
	}
}
