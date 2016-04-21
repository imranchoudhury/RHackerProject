

#ifndef SRC_LLIST_H_
#define SRC_LLIST_H_

#include <iostream>
#include <string>
#include "AbstractCollection.h"
using namespace std;

class LList : public AbstractCollection {


public:
	struct LLNode
	{
		int value;
		//points to the next element in the linked list.
		LLNode* ptrNext;
	} *ptrHead, *ptrTail, *ptrNode;

	//default constructor for child class llist
	LList();

	//copy constructor for child class
	LList(LList&);

	//default virtual destructor for child class llist
	virtual ~LList();

	//map function for accpeting a value returned by fn - applying that value to the entire list
	virtual LList* map(int);

	//add method to add numbers in the linked list
	virtual LList* add(int,int);

	//remove method removes the occurences of the integer from the list
	virtual LList* remove(int);

	//this method returns the index of the integer given as input in the linked list
	virtual int& operator[](int);

	//prints the linked list
	virtual void print();

	//deep copies the argument into the receiver.
	virtual LList& operator=(LList&);

	//contains operation - check whether the input integer is there in the current list or not
	virtual bool contains(int checkValue);

	//virtual copy scheme
	virtual LList* virtualCopy();
};

#endif /* SRC_LLIST_H_ */
