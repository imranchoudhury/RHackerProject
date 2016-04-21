

#ifndef ABSTRACTCOLLECTION_H_
#define ABSTRACTCOLLECTION_H_
#include <iostream>
using namespace std;
class AbstractCollection
{
private:
	int size_;

protected:
	//copy constructor
	AbstractCollection(AbstractCollection&);
public:
	//default constructor
	AbstractCollection();

	//default virtual destructor
	virtual ~AbstractCollection();


	//get the size
	int getSize();

	//set the size
	void setSize(int);

	//check whether the input integer is present in the list or not.
	virtual bool contains(int) = 0;

	//map function maps the value passed into the function to the receiver
	virtual AbstractCollection* map(int) = 0;

	//this function will be used to add integers to the specific list.
	virtual AbstractCollection* add(int,int);

	//this function will be used to remove the occurrences of all integers in the specific list.
	virtual AbstractCollection* remove(int);

	//this function is used to return the element at the index- takes as input an index integer
	virtual int& operator[](int);

	//prints the list - array or linked list as required.
	virtual void print();

	//this function is used to deep copy the argument into the receiver and modified receiver is returned.
	virtual AbstractCollection& operator=(AbstractCollection&);

	//virtual copy scheme.
	virtual AbstractCollection* virtualCopy()=0;
};

#endif /* ABSTRACTCOLLECTION_H_ */
