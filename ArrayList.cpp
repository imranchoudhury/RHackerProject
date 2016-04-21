

#include "ArrayList.h"

//parameterized constructor for initializing the array list - dynamically allocate the array size - default values in array as 0
ArrayList::ArrayList(int size) {
	this->arrayValues = new int[size];
	//set the current object array size list as the size dynamically allocated
	this->setSize(size);
	for(int i = 0 ; i < size ; i++)
	{
		this->arrayValues[i] = 0;
	}
}

//default destructor for array list
ArrayList::~ArrayList() {
	// call the destructor for the array list;
	cout<<endl<<"Default destructor for Array List";
}

//copy constructor for array list
ArrayList::ArrayList(ArrayList &objArCopy)
{
	cout<<endl<<"Copy constructor for array list";
	*this = objArCopy;
}

//getter for Array Values
int ArrayList::getArrayValues(int index)
{
	if(index < 0 || index > this->getSize())
	{
		cout<<"Index out of bound";
		return -1;
	}
	else
	{
		return this->arrayValues[index];
	}
}

//setter for Array Values
void ArrayList::setArrayValues(int value,int index)
{
	this->arrayValues[index] = value;
}

//map function - replace each value in the array list with the mapValue as returned by the fn function.
ArrayList* ArrayList::map(int mapValue)
{
	cout<<endl<<"Inside map function of array list "<<endl;
	int arrSize = this->getSize();
	if(arrSize > 0)
	{
		for(int i = 0 ; i < arrSize ; i++)
		{
			this->setArrayValues(mapValue,i);
		}
	}

	return this;
}

//add elements in the array - not possible since array are fixed lenght data structures - just prints an error message
ArrayList* ArrayList::add(int value, int index)
{
	cout<<endl<<"The data structure - Array - does not supports addition";
	return this;
}

//remove element of the value equals to passed argument - prints error message - array does not  supports removal of a node- fixed lenght
ArrayList* ArrayList::remove(int value)
{
	cout<<endl<<"The data structure - Array - does not supports removal";
	return this;
}

//overaload index operator for array list
int& ArrayList::operator[](int index)
{
	//if the index is out of bound - throw and exception
	if(index < 0 || index >= this->getSize())
	{
		cout<<endl<<"Index: "<<index<<" out of bound - array list indexing [] invocation ";
		throw "Array out of bound";
		//return ArrayList::arrVal;
	}

	//return the integer value present on the index
	return ArrayList::arrayValues[index];

}

//prints the element present in array list
void ArrayList::print()
{
	int tempSize = this->getSize();
	for(int i =0 ; i < tempSize; i++)
	{
		cout<<endl<<"Element in array at index :" <<i << " is: "<< this->getArrayValues(i);
	}
}

// overload = operator for array list
ArrayList& ArrayList::operator=(ArrayList &current)
{
	cout<<endl<<"Inside overload = Array List";
	int arrSize = current.getSize();
	this->arrayValues = new int[arrSize];
	this->setSize(arrSize);
	//override all the values
	for(int i =0 ;i < arrSize ; i++)
	{
		this->setArrayValues(current.arrayValues[i],i);
	}

	return *this;
}

//check whether the array list contains the value or not
bool ArrayList::contains(int checkValue)
{
	int arrSize = this->getSize();
	if(arrSize == 0)
	{
		cout<<endl<<"The list is array list empty";
		return false;
	}
	else
	{
		for(int i = 0 ; i < arrSize; i++)
		{
			if(this->getArrayValues(i) == checkValue)
			{
				cout<<endl<<"The value : "<<checkValue<<" exists in the array list";
				return true;
			}
		}
		cout<<endl<<"The value :"<<checkValue<<" does not exists in the array list";
		return false;
	}
	cout<<endl<<"The value :"<<checkValue<<" does not exists in the array list";
	return false;
}

// create a virtual copy of the array list
ArrayList* ArrayList::virtualCopy()
{
	cout<<endl<<"Virtual Copy - Array List"<<endl;
	ArrayList* objALVC = new ArrayList(*this);
	return objALVC;
}
