


//#include "AbstractCollection.h";
#include "ArrayList.h"
#include "LList.h"

int fn(int);

int main(int argc,const char *argv[])
{

	AbstractCollection *objACForArr, *objACForLL, *objACForLLCopy;

	cout<<endl<<"Starting the program : ";

	//array of size = 10
	cout<<endl<<"Create array  - objAL of size : 10"<<endl;
	ArrayList objAL(10);
	LList objLL, objLLNewCopy;

	objACForArr = &objAL;
	cout<<endl<<"Array 1- objAL:"<<endl;
	objACForArr->print();
	cout<<endl<<"Array 1- objAL Size :"<<objACForArr->getSize();

	//index starts from 0
	cout<<endl<<"Indexing [2] = 210 operation on Array 1- objAL: "<<endl;
	objAL[2] = 210;
	cout<<endl<<"Print after indexing[2] = 210  array 1- objAL "<<objAL[2];

	cout<<endl<<"Print full array list 1- objAL after indexing[2] = 210: "<<endl;
	objAL.print();

	//Perform operations on Linked List
	objACForLL = &objLL;
	cout<<endl<<"Creating linked list 1 - objLL : "<< endl;
	objACForLL->add(10,0);
	objACForLL->add(10,1);
	objACForLL->add(20,2);
	objACForLL->add(10,3);
	objACForLL->add(15,1);
	objACForLL->add(10,3);
	objACForLL->add(65,5);
	//this is not out of bound - we can add nodes anywhere - this will be added as the linked list size is = 7
	objACForLL->add(10,7);

	cout<<endl<<"Print first linked list objACForLL/objLL : "<< endl;
	objACForLL->print();
	cout<<endl<<"Get the size of first linked list objACForLL/objLL: "<<objACForLL->getSize();


	cout<<endl<<"Indexing[2]  = 210 operation on LinkedList - 1- objLL - index starts from 0 : "<<endl;
	objLL[2] = 210;
	cout<<endl<<"Print after indexing[2] = 210 operation on linked list - 1- objLL   "<<objLL[2];

	cout<<endl<<"Print the complete list after indexing objLL :"<<endl;
	objLL.print();

	cout<<endl<<"Creating second linked list objLLNewCopy/objACForLLCopy: "<< endl;
	//creating a new linked list to check copy operation
	objACForLLCopy = &objLLNewCopy;
	objACForLLCopy->add(100,0);
	objACForLLCopy->add(200,1);
	objACForLLCopy->add(100,2);
	objACForLLCopy->add(150,2);
	objACForLLCopy->add(100,3);
	objACForLLCopy->add(605,5);
	// this should be out of bound- the index that can be inserted is 6.
	objACForLLCopy->add(100,7);

	cout<<endl<<"Print second linked list objLLNewCopy/objACForLLCopy : "<< endl;
	objACForLLCopy->print();

	cout<<endl<<"Get the size of second linked list objLLNewCopy/objACForLLCopy : "<<objACForLLCopy->getSize();

	cout<<endl<<"Creating a deep copy of new linked list- objLLNewCopy into objLL, it should remove all old values in first linked list:"<<endl;
	//create a new deep copy using overload = operator
	objLL = objLLNewCopy;

	cout<<endl<<"First linked list- 1- objLL after copy operation: "<<endl;
	objLL.print();
	cout<<endl<<"The size of first linked- 1 objLL list after copy :"<<objACForLL->getSize();

	cout<<endl<<"Performing remove(100) operation on first linked list objACForLL/objLL after copy :"<<endl;
	objACForLL->remove(100);
	cout<<endl<<"Performing 2nd remove(10) operation on first linked list objACForLL/objLL after copy - element not found :"<<endl;
	objACForLL->remove(10);

	cout<<endl<<"First linked list - 1 objLL/objACForLL after copy and then remove :"<<endl;
	objACForLL->print();
	cout<<endl<<"The size of first linked list - 1 objLL/objACForLL after copy and remove:"<<objACForLL->getSize();

	cout<<endl<<"Second linked list objLLNewCopy/objACForLLCopy- after copy and remove operation - should not get affected by the operations performed on first linked list - 1 objLL: "<<endl;
	objACForLLCopy->print();
	cout<<endl<<"The size of second linked list - objLLNewCopy after copy and remove - - should not get affected: "<<objACForLLCopy->getSize();

	//variables to test the copy constructor
	LList objLLCopy1(objLL);
	cout<<endl<<"Add new element in the copy constructed linked list - objLLCopy1"<<endl;
	objLLCopy1.add(250,1);
	cout<<endl<<"Print the copy constructor list - objLLCopy1: "<<endl;
	objLLCopy1.print();
	cout<<endl<<"Test indexing[0] = 1600 on copy constructed linked list objLLCopy1"<<endl;
	objLLCopy1[0] = 1600;

	cout<<endl<<"Print objLLCopy1 after indexing"<<endl;
	objLLCopy1.print();


	cout<<endl<<"Print the linked list - copy constructed objLLCopy1 after index[-1] = 80 out of bound: "<<endl;
	objLLCopy1.print();

	cout<<endl<<"The original list - objLL - after addition in copied list - should not be affected"<<endl;
	objLL.print();

	//copy constructor for array list
	ArrayList objALCopy1(objAL);
	cout<<endl<<"Print the copy constructor array: "<<endl;
	objALCopy1.print();
	objALCopy1[4] = 400;

	cout<<endl<<"Print original arrays- objAL after invoking copy constructor and indexing done on copy constr :"<<endl;
	objAL.print();

	cout<<endl<<"objLLCopy1 : "<<endl;
	objLLCopy1.print();
	cout<<endl<<"Check the function contains(250) for linked list objLLCopy1 - made by copy constructor";
	objLLCopy1.contains(250);

	cout<<endl<<"objLL : "<<endl;
	objLL.print();
	cout<<endl<<"Check the function contains(250) for linked list 1 - objLL";
	objLL.contains(250);

	cout<<endl<<"objALCopy1 : "<<endl;
	objALCopy1.print();
	cout<<endl<<"Check the function contains(400) for array list objALCopy1- made by copy constructor";
	objALCopy1.contains(400);

	cout<<endl<<"objAL : "<<endl;
	objAL.print();
	cout<<endl<<"Check the function contains(400) for array list 1- objAL";
	objAL.contains(400);

	cout<<endl<<"objLLCopy1 before map(fn(-1)) :"<<endl;
	objLLCopy1.print();
	cout<<endl<<"Check map function on linked list objLLCopy1: "<<endl;
	objLLCopy1.map(fn(-1));

	cout<<endl<<"Print copied linked list objLLCopy1 after map: "<<endl;
	objLLCopy1.print();

	cout<<endl<<"Print original linked list - should not be affected by map performed on copied linked list "<<endl;
	objLL.print();

	cout<<endl<<"objALCopy1 array list before map(fn(-2)) :"<<endl;
	objALCopy1.print();
	cout<<endl<<"Check map function on array list: "<<endl;
	objALCopy1.map(fn(-2));

	cout<<endl<<"Print copied array list objALLCopy1 after map - "<<endl;
	objALCopy1.print();

	cout<<endl<<"Print array list - objAL after map performed on copied list - should not be affected - deep copied"<<endl;
	objAL.print();

	cout<<endl<<"Print the array list : pointed by objACForArr :"<<endl;
	objACForArr->print();

	cout<<endl<<"Perform virtual copy on Array List objACForArr:"<<endl;
	AbstractCollection* objVCAL2 = objACForArr->virtualCopy();
	cout<<endl<<"Print after virtual copy objVCAL2: "<<endl;
	objVCAL2->print();
	cout<<endl<<"Perform remove on arrays objVCAL2: "<<endl;
	objVCAL2->remove(5);

	cout<<endl<<"Print the linked list : pointed by objACForLL :"<<endl;
	objACForLL->print();

	AbstractCollection* objVCLL2 = objACForLL->virtualCopy();
	cout<<endl<<"Print Linked list  objVCLL2 after virtual copy: "<<endl;
	objVCLL2->print();
	cout<<endl<<"Perform add on linked list objVCLL2 : "<<endl;
	objVCLL2->add(-5,0);
	objVCLL2->add(-5,1);
	objVCLL2->add(-5,2);
	objVCLL2->add(-5,4);
	cout<<endl<<"Print linked list- objVCLL2 after add :"<<endl;
	objVCLL2->remove(-5);
	cout<<endl<<"Print linked list- objVCLL2 after remove :"<<endl;
	objVCLL2->print();

	cout<<endl<<"Print linked list- objACForLL after add performed on virtual copy object objVCLL2- original list should not be affected :"<<endl;
	objACForLL->print();

	cout<<endl<<"Test index[5] = 90 - out of bound on linked list objLLCopy1 :"<<endl;

	cout<<endl<<"objLLCopy1 size :"<< objLLCopy1.getSize();

	delete objVCAL2;
	delete objVCLL2;
	cout<<endl<<"Perform out of bound test for indexing - linked list objLLCopy1:"<<endl;

	/*uncomment the below lines to test the index out of bound*/
	//objLLCopy1[5] = 90;
	//objLLCopy1[-1] = 80;

	cout<<endl<<"objALCopy1 size :"<< objALCopy1.getSize();
	cout<<endl<<"Test index out of bound for arrays objALCopy1 :"<<endl;

	/*uncomment the below lines to test the index out of bound*/
	//objALCopy1[-9] = 200;
	//objALCopy1[12] = 1200;

	return 0;
}

int fn(int applyValue)
{
	applyValue++;
	return applyValue;
}
