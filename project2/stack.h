/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
This module contains the code for the member functions of the class Stack
*/
#ifndef STACK_H
#define STACK_H
#include "customerinfo.h"
#include <fstream>

class Stack
{
public:
	Stack();
	Stack(const Stack &aStack);
	~Stack();

	void push(const CustomerInfo &aCustomerInfo);
	bool pop(CustomerInfo &aCustomerInfo);
	bool peek(CustomerInfo &aCustomerInfo) const;
	void display();
	const unsigned int get_top();
	// unsigned int getSize() const;

	const Stack &operator=(const Stack &aStack);
	friend ostream &operator<<(ostream &out, const Stack &aStack);

	void loadFromFile(const char *fileName);
	void saveToFile(const char *fileName) const;

private:
	CustomerInfo **aStack;
	const static unsigned int INIT_CAP = 3;
	const static unsigned int GROWTH_FACTOR = 2;
	unsigned int currCapacity;
	unsigned int top;

	void destroy();
	void expand();
};

#endif
