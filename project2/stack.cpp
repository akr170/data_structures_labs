/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
This module contains the code for the member functions of the class Stack
*/

#include "stack.h"



Stack::Stack() : top(0)
{
	/*
	Constructor member function
	*/
	currCapacity = INIT_CAP;
	aStack = new CustomerInfo *[currCapacity];
	for (unsigned int i = 0; i < currCapacity; i++)
	{
		aStack[i] = nullptr;
	}
}



Stack::Stack(const Stack &aStack) : aStack(nullptr), top(0)
{
	/*
	Copy constructor
	*/
	*this = aStack;
}



Stack::~Stack()
{
	/*
	Destructor
	*/
	destroy();
}



void Stack::destroy()
{
	/*
	Helper member function to destroy the stack.
	*/
	for (unsigned int i = 0; i < top; i++)
	{
		if (aStack[i])
			delete aStack[i];
	}
	if (aStack)
		delete[] aStack;
}



void Stack::push(const CustomerInfo &aCustomerInfo)
{
	/*
	Member function to push a instance of the CustomerInfo ADT that stores the
	customer name and email information on the the stack
	INPUT:
		aCustomerInfo: a instance of the CustomerInfo ADT that contains the
					   customer name and email information for one customer
	OUTPUT:
		None
	*/
	if (currCapacity == top)
	{
		expand();
	}
	aStack[top] = new CustomerInfo(aCustomerInfo);
	top++;
}



void Stack::expand()
{
	/*
	Member function to grow the size of the stack if the current stack is filling up.
	INPUT:
		None
	OUTPUT:
		None
	*/
	currCapacity *= GROWTH_FACTOR;
	CustomerInfo **tempStack = new CustomerInfo *[currCapacity];
	for (unsigned int i = 0; i < top; i++)
	{
		tempStack[i] = aStack[i]; // only copy the pointers
	}
	delete[] aStack;
	aStack = tempStack;
}



bool Stack::pop(CustomerInfo &aCustomerInfo)
{
	/*
	Member function to pop an instance of the CustomerInfo ADT that stores the
	customer name and email information on the the stack
	INPUT:
		aCustomerInfo: an empty instance of the CustomerInfo ADT through which the
					   customer name and email information for the last customer in
					   stack is returned
	OUTPUT:
		true if successful, false otherwise
	*/
	if (top == 0)
	{
		cout << "No customer info in stack.  Stack is empty.";
		return false;
	}
	aCustomerInfo = *(aStack[top - 1]);
	delete aStack[top - 1];
	top--;
	return true;
}



bool Stack::peek(CustomerInfo &aCustomerInfo) const
{
	/*
	Member function to peek an instance of the CustomerInfo ADT that stores the
	customer name and email information on the the stack
	INPUT:
		aCustomerInfo: an empty instance of the CustomerInfo ADT through which the
					   customer name and email information for the last customer in
					   stack is returned
	OUTPUT:
		true if successful, false otherwise
	*/
	if (top == 0)
	{
		cout << "No customer info in stack.  Stack is empty.";
		return false;
	}
	aCustomerInfo = *(aStack[top - 1]);
	return true;
}



void Stack::display()
{
	/*
	Member function to display the entire stack
	INPUT:
		None
	OUTPUT:
		None
	*/
	if (top == 0)
	{
		cout << "No customer info in stack.  Stack is empty.";
	}
	else
	{
		for (unsigned int i = top; i > 0; i--)
		{
			cout << "[" << i << "] " << aStack[i - 1]->get_contact_name() << " - " << aStack[i - 1]->get_contact_email() << endl;
		}
	}
}



const unsigned int Stack::get_top()
{
	/*
	Gets the number of data point still contained in the stack.
	*/
	return top;
}



const Stack &Stack::operator=(const Stack &stackSrc)
{
	/*
	Overloaded operator = for the Stack class
	INPUT:
		stackSrc: the source stack from where the data needs to be copied into
				  the current stack
	OUTPUT:
		The copied stack.
	*/
	if (this == &stackSrc)
		return *this;
	destroy();
	top = stackSrc.top;
	currCapacity = stackSrc.currCapacity;
	aStack = new CustomerInfo *[currCapacity];
	for (unsigned int i = 0; i < top; i++)
	{
		aStack[i] = new CustomerInfo(*(stackSrc.aStack[i])); // copy the student
	}
	return *this;
}



ostream &operator<<(ostream &out, const Stack &srcStack)
{
	/*
	Overloaded operator << to display the stack data
	*/
	out << endl
		<< "Displaying the stack ..." << endl;
	for (unsigned int i = 0; i < srcStack.top; i++)
	{
		out << *(srcStack.aStack[i]) << endl;
	}
	return out;
}



void Stack::loadFromFile(const char *fileName)
{
	/*
	Member function to help load test data from an external file
	INPUT:
		fileName: path to the external .txt file that contains test data set
	OUTPUT:
		None
	*/
	ifstream fh;
	CustomerInfo currCustomerInfo;
	const int MAX_CHAR = 256;
	char curr_contact_name[MAX_CHAR], curr_contact_email[MAX_CHAR];

	fh.open(fileName);
	if (!fh)
	{
		std::cout << "Fail to open " << fileName << " for reading." << std::endl;
		exit(1);
	}

	fh.getline(curr_contact_name, MAX_CHAR, '|');
	while (!fh.eof())
	{
		fh.getline(curr_contact_email, MAX_CHAR, '\n');

		currCustomerInfo.set_contact_name(curr_contact_name);
		currCustomerInfo.set_contact_email(curr_contact_email);
		push(currCustomerInfo);

		fh.getline(curr_contact_name, MAX_CHAR, '|');
	}
	fh.close();
}



void Stack::saveToFile(const char *fileName) const
{
	/*
	Member function to save test data into an external file
	INPUT:
		fileName: path to the external .txt file that contains test data set
	OUTPUT:
		None
	*/
	ofstream out;

	out.open(fileName);
	if (!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for (unsigned int i = 0; i < top; i++)
	{
		out << aStack[i]->get_contact_name() << '|' << aStack[i]->get_contact_email() << endl;
	}
	out.close();
}
