

#ifndef SRC_ARRAYLIST_H_
#define SRC_ARRAYLIST_H_

#include <iostream>
#include <stdexcept>
#include "AbstractCollection.h"

using namespace std;

class ArrayList : public AbstractCollection
{
private:
	int *arrayValues;

public:

	//parameterised constructor for Array List - int denotes the size of the array
	ArrayList(int);

	//copy constructor for array list
	ArrayList(ArrayList&);

	//default destructor for Array List
	virtual ~ArrayList();


	//get the values of Array List at a particular index
	int getArrayValues(int);

	//set the values for Array List
	void setArrayValues(int,int);

	//map function for accpeting a value returned by fn - applying that value to the entire list
	virtual ArrayList* map(int);

	//add new elements to the array.
	virtual ArrayList* add(int,int);

	//remove method removes the occurrences of the integer from the array list
	virtual ArrayList* remove(int);

	//this method returns the index of the integer given as input in the linked list
	virtual int& operator[](int);

	//print the elements present in array;
	virtual void print();

	//deep copies the argument into the receiver.
	virtual ArrayList& operator=(ArrayList&);

	//contains operation - check whether the input integer is there in the current list or not
	virtual bool contains(int checkValue);

	//virtual copy scheme
	virtual ArrayList* virtualCopy();
};

#endif /* SRC_ARRAYLIST_H_ */
