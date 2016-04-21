

#include "AbstractCollection.h"

AbstractCollection::AbstractCollection() {
	// TODO Auto-generated constructor stub
	size_ = 0;
	cout<<endl<<"Default constructor for AbstractCollection";
}

AbstractCollection::~AbstractCollection() {
	// TODO Auto-generated destructor stub
	cout<<endl<<"Default destructor for AbstractCollection";
}

//copy constructor
AbstractCollection::AbstractCollection(AbstractCollection &copyObj)
{
	cout<<endl<<"Copy constructor for AbstractCollection";
	*this = copyObj;
}

int AbstractCollection::getSize()
{
	return this->size_;
}

void AbstractCollection::setSize(int newSize)
{
	this->size_ = newSize;
}

AbstractCollection* AbstractCollection::add(int value, int index)
{
	return this->add(value,index);
}

AbstractCollection* AbstractCollection::remove(int value)
{
	return this->remove(value);
}

int& AbstractCollection::operator[](int index)
{
	cout<<endl<<"Inside [] overloaded function, abstract collection :"<<endl;
	return this->operator[](index);
}

void AbstractCollection::print()
{
	return this->print();
}

AbstractCollection& AbstractCollection::operator=(AbstractCollection &current)
{
	cout<<endl<<"Inside = overloaded function, abstract collection :"<<endl;
	return this->operator=(current);
}

