#include "pch.h"
#include <iostream>
using namespace std;
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"

// insert at the top and delete at the top
// push - one insert function
// pop - one delete function

//Default Constructor. Will properly initialize a stack to
//be an empty stack, to which values can be added.
LIFOStackClass::LIFOStackClass() {
	head = 0;
	tail = 0;
}


//Prints out the contents of the stack. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end.

// the first thing that prints out should be at the front 
// of the stack, which is also the first one to be removed.
// it should be the last element inserted.
void LIFOStackClass::print() const {
	LinkedNodeClass* printPtr = head;
	while (printPtr != 0) {
		cout << printPtr->getValue();
		cout << " ";
		printPtr = printPtr->getNext();
	}
	cout << endl;
}

//Returns the number of nodes contained in the stack.
int LIFOStackClass::getNumElems() const {
	int countNumber = 0;
	LinkedNodeClass* countPtr = head;
	while (countPtr != 0) {
		countNumber = countNumber + 1;
		countPtr = countPtr->getNext();
	}
	return countNumber;
}

//Inserts the value provided (newItem) into the stack.
void LIFOStackClass::push(const int &newItem) {
	// put the new node in the head position
	LinkedNodeClass* insertStackPtr;
	if (head == 0) {
		insertStackPtr = new LinkedNodeClass(0, newItem, 0);
		// head and tail point to this node
		// the only node in this list
		head = insertStackPtr;
		tail = insertStackPtr;
	}
	else {
		// insert at the first position
		insertStackPtr = new LinkedNodeClass(0, newItem, head);
		insertStackPtr->setBeforeAndAfterPointers();
		// update head and tail
		head = insertStackPtr;
	}
}

//Attempts to take the next item out of the stack. If the
//stack is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//stack is not empty, the function returns true and outItem
//becomes a copy of the next item in the stack, which is
//removed from the data structure.
bool LIFOStackClass::pop(int &outItem) {
	if (getNumElems() == 0) {
		// list is empty
		return false;
	}
	else {
		// list is not empty then remove the head
		outItem = head->getValue();
		// delete the pointer and first dynamic allocation node
		head = head->getNext();
		delete head->getPrev();
		head->setPreviousPointerToNull();
		return true;
	}
}


//Clears the stack to an empty state without resulting in any
//memory leaks.
void LIFOStackClass::clear() {
	LinkedNodeClass* toDeletePtr = head;
	LinkedNodeClass* currentPtr = head;
	// delete dynamic allocation nodes one by one
	while (currentPtr != 0) {
		currentPtr = currentPtr->getNext();
		delete toDeletePtr;
		toDeletePtr = currentPtr;
	}
	head = 0;
	tail = 0;
}

//Destructor. Responsible for making sure any dynamic memory
	//associated with an object is freed up when the object is
	//being destroyed.
LIFOStackClass::~LIFOStackClass() {
	clear();
}