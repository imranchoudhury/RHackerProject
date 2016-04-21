

#include "LList.h"

LList::LList() {
	//the default constructor invoked will set the head and tail of the current linked list object to null and size of linked list = 0
	this->LList::ptrHead = NULL;
	this->LList::ptrTail = NULL;
	this->setSize(0);

	cout<<endl<<"Default Constructor for LList";
}

LList::~LList() {
	// TODO Auto-generated destructor stub
	cout<<endl<<"Default Destructor for LList";
	LList::LLNode *tempCurrent, *temp;
		tempCurrent = this->LList::ptrHead;
		temp = this->LList::ptrHead;
		while(tempCurrent != NULL){
			tempCurrent = tempCurrent->ptrNext;
			delete temp;
			temp = tempCurrent;
		}
}
//define copy constructor for linked list - perform deep copy
LList::LList(LList& objLLCopy)
{
	cout<<endl<<"Copy constructor for LList invoked";
	//since default constructor is not invoked - thus we make this explicitly null
	this->LList::ptrHead = NULL;
	this->LList::ptrTail = NULL;
	this->setSize(0);
	//the overloaded = operator is called.
	*this = objLLCopy;
}

//map the value as returned by the function to each value present in the list
LList* LList::map(int mapValue)
{
	cout<<endl<<"LList map function";
	LList::LLNode* tempNode = this->LList::ptrHead;
	if(tempNode != NULL)
	{
		while(tempNode != NULL)
		{
			//replace the existing value in the list with the mapValue
			tempNode->value = mapValue;

			//move to the next pointer.
			tempNode = tempNode->ptrNext;
		}
	}
	else
	{
		cout<<endl<<"Cannot perform map function - the linked list is empty"<<endl;
	}
	return this;
}

//add new node in the list - at the specified index by the user - starting from 0
LList* LList::add(int value, int index)
{
	int i = 1;
	//get the size of the current list
	int j = this->getSize();
	//point a temporary node to the head of the list
	LList::LLNode* tempNode = this->LList::ptrHead;

	//check whether the index provided by the user is appropriate - should not be out of bound or negative
	if(index >= 0 && index <= j)
	{
		//add one - this will be set as the new size of the linked list
		j++;
		LList::LLNode *temp = new LList::LLNode;
		LList::LLNode *tempNext = new LList::LLNode;
		LList::LLNode *tempHead = new LList::LLNode;
		temp->value = value;

		//if there are no nodes added in the linked list
		if(this->LList::ptrHead == NULL)
		{
			//this is the only node , so ptrNext will be set to null
			temp->ptrNext = NULL;
			//the head will now point to this node
			this->LList::ptrHead = temp;
			//since there's only one node - the tail also points to this node
			this->LList::ptrTail = temp;
			//the number of nodes at this time added is just one
			this->setSize(j);
			return this;
		}

		//only one node is present in the linked list and the nodes needs to appended at the end
		if(this->LList::ptrHead == this->LList::ptrTail)
		{
			temp->ptrNext = NULL;
			//link the head node with next node
			this->LList::ptrHead->ptrNext = temp;
			//move the pointer of tail to this new node
			this->LList::ptrTail = temp;
			//set the new size of linked list
			this->setSize(j);
			return this;
		}
		//special case - add at first position there can be any number of nodes in the list
		if(index == 0)
		{
			//point the new node to the header of the list
			temp->ptrNext = this->LList::ptrHead;
			//change the point of head node to the new node
			this->LList::ptrHead = temp;
			this->setSize(j);
			return this;
		}
		//special case since head needs to be pointed accordingly - add the node after head node.
		if(index == 1)
		{
			//point the new node to the node actually pointed by the header node of the linked list
			temp->ptrNext = this->LList::ptrHead->ptrNext;
			//point the header node to the new node
			this->LList::ptrHead->ptrNext = temp;
			this->setSize(j);
			return this;
		}
		//for all other cases
		else
		{
			//for all other cases of adding nodes - iterate through the list to find the index position.
			tempHead = this->LList::ptrHead;
			tempNext = this->LList::ptrHead->ptrNext;

			//add the node in between of the list.
			while(i < index)
			{
				tempHead = tempHead->ptrNext;
				tempNext = tempNext->ptrNext;

				if(tempNext == NULL)
					break;
				i++;
			}

			//add the node at the end of the list
			if(tempNext == NULL)
			{
				temp->ptrNext = NULL;
				this->LList::ptrTail->ptrNext = temp;
				this->LList::ptrTail = temp;
				this->setSize(j);
				return this;
			}
			//insert the node in between the list at a specific index which is not the end of the list.
			else
			{
				temp->ptrNext = tempNext;
				tempHead->ptrNext = temp;
				this->setSize(j);
				return this;
			}

		}
		return this;
	}
	else
	{
		cout<<"Index out of bound. Cannot insert the node in the linked list at index: "<<index;
	}
	return this;
}

//this method is use to remove all the values which are equal to removeValue and is present in the linked list.
LList* LList::remove(int removeValue)
{
	int checker = -1;
	LList::LLNode* temp1;
	LList::LLNode* tempPrev;
	LList::LLNode* tempDelete;
	//point a temporary node to the header of the linked list
	temp1 = LList::ptrHead;
	int tempSize;

	//check whether the list is empty
	while(temp1 != NULL)
	{
		//check if the value to be removed matches with any value in linked list
		if(temp1->value == removeValue)
		{
			//checker - used at the end of the checking - whether any element was removed or not
			checker = 0;
			//if we are removing the head node
			if(temp1 == LList::ptrHead)
			{
				//change the pointing of the head of the list to the next node in the linked list
				LList::ptrHead = LList::ptrHead->ptrNext;

				//also if this is the only element in the list
				if(LList::ptrTail == temp1)
				{
					//change the pointing of tail pointer in the linked list
					LList::ptrTail = temp1->ptrNext;
					//since this is the only node, so it will just simply delete the node and break from the loop,
					//since there are no more nodes that can be deleted
					tempSize = this->getSize();
					tempSize--;
					//adjust the size of the linked list
					this->setSize(tempSize);
					//delete the node
					delete temp1;
					//since there are no more nodes - break
					break;
				}

				//assign a temporary pointer to the next node in the linked list
				tempDelete = temp1->ptrNext;
				tempSize = this->getSize();
				tempSize--;
				//adjust the size of the linked list.
				this->setSize(tempSize);
				//delete the node - for which matching value was found.
				delete temp1;
				//reassign the tempnode to point to the next node- further more deletion possible.
				temp1= tempDelete;
			}
			else
			{
				//special condition check for tail node deletion
				if(temp1->ptrNext == NULL)
				{
					tempPrev->ptrNext = NULL;
					//adjust the pointer of the linked list tail - point to the previous node.
					LList::ptrTail = tempPrev;
					tempSize = this->getSize();
					tempSize--;
					//adjust the size of the linked list
					this->setSize(tempSize);
					delete temp1;
					//we have reached the end of the list - hence no more deletion possible - no more nodes available to navigate
					break;
				}

				//delete any node present in anywhere in the linked list.
				tempPrev->ptrNext = temp1->ptrNext;
				tempDelete = temp1->ptrNext;
				tempSize = this->getSize();
				tempSize--;
				//adjust the size of the linked list.
				this->setSize(tempSize);
				delete temp1;
				temp1 = tempDelete;
			}
		}
		else
		{
			//navigate through the list - no match found.
			tempPrev = temp1;
			temp1 = temp1->ptrNext;
		}

	}
	if(checker == -1)
	{
		cout<<endl<<"The element was not found in the linked list for removal"<<endl;
	}
	return this;
}

//this method is used to return the element present at the index passed in the LinkedList
int& LList::operator[] (int index)
{
	LList::LLNode* tmp = new LList::LLNode;
	tmp->value=-1;
	tmp->ptrNext = NULL;
	this->LList::ptrNode = tmp;
	int tempIndex = 0;

	//if index is out of bound for linked list - throw exception
	if(index < 0 || index > this->getSize())
	{
		cout<<endl<<"The index: "<<index<<" is out of bound";
		throw "Index out of bound for linked list";
	}
	else
	{
		//iterate through the list to the index and return the integer at the index in the linked list
		this->LList::ptrNode = this->LList::ptrHead;
		while(this->LList::ptrNode != NULL)
		{
			if(tempIndex == index)
			{
				//cout<<endl<<"The value of linked list at index "<<index<<" is : "<<this->ptrNode->value;
				return LList::ptrNode->value;
			}
			else
			{
				//increment the index if current index is not the same as index to be returned
				tempIndex++;
				this->LList::ptrNode = this->LList::ptrNode->ptrNext;
			}
		}
	}
	this->LList::ptrNode = tmp;
	//cout<<endl<<"Index out of bound";
	return LList::ptrNode->value;
}

//print the linked list nodes
void LList::print()
{
	LList::LLNode* tempNode = this->LList::ptrHead;
	int i = 0;
	while(tempNode != NULL)
	{
		cout<<"Node at "<<i <<" is :"<< tempNode->value<<endl;
		tempNode = tempNode->ptrNext;
		i++;
	}
	if(i == 0)
	{
		cout<<endl<<"The linked list is empty "<<endl;
	}

}

//operator overloading for = operator
LList& LList::operator=(LList &current)
{
	cout<<endl<<"Inside = overloaded function of linked list :"<<endl;
	LList::LLNode* tempDelNode = this->LList::ptrHead;
	LList::LLNode* tempNode ;

	int index = 0;
	if(this->ptrHead == current.ptrHead)
	{
		cout<<"Cannot perform = operation for receiver and assigner as same - no list changed";
		return *this;
	}
	//delete the previous list completely;
	while(tempDelNode != NULL)
	{
		tempNode = tempDelNode->ptrNext;
		delete tempDelNode;
		tempDelNode = tempNode;
	}

	//reset all the pointers for the receiver
	this->LList::ptrHead = NULL;
	this->LList::ptrTail = NULL;
	this->setSize(0);

	// get the pointer to the list that needs to be copied into the receiver
	tempNode = current.ptrHead;
	while(tempNode != NULL)
	{
		//add the values from the current list to the receiver
		this->LList::add(tempNode->value,index);
		index++;
		tempNode = tempNode->ptrNext;
	}

	return *this;
}

//function to check if the value exists
bool LList::contains(int checkValue)
{
	//check first if the list is empty
	if(this->LList::ptrHead != NULL)
	{
		//if the list is not empty - traverse the list to check if the value exists
		LList::LLNode* tempNode = this->LList::ptrHead;

		while(tempNode != NULL)
		{
			//if we find the value then , return from here itself - return true;
			if(tempNode->value == checkValue)
			{
				cout<<endl<<"The linked list contains :"<<checkValue<<endl;
				return true;
			}
			else
			{
				//move to the next element
				tempNode = tempNode->ptrNext;
			}
		}
	}
	else
	{
		cout<<endl<<"The linked list is empty"<<endl;
		return false;
	}
	//if the value is not found - then return false;
	cout<<endl<<"The linked list does not contains :"<<checkValue;
	return false;
}


LList* LList::virtualCopy()
{
	cout<<endl<<"Virtual Copy - Linked List"<<endl;
	LList* objLLVC = new LList(*this);
	return objLLVC;
}
