/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
*/
// Header file for Queue class
#ifndef QUEUE_H
#define QUEUE_H

#include "customer.h"
#include <fstream>

class Queue
{
public:
	Queue();
	Queue(const Queue &aQueue);
	~Queue();

	void enqueue(const Customer &a_customer);
	bool dequeue(Customer &a_customer);
	bool peek(Customer &a_customer);
	void display();
	const unsigned int get_size();
	/*
	bool peek(Student& aStudent) const;
	int getSize() const;
	bool isEmpty() const;
	*/
	const Queue &operator=(const Queue &aQueue);
	friend ostream &operator<<(ostream &out, const Queue &aQueue);

	void loadFromFile(const char *fileName);
	void saveToFile(const char *fileName) const;

private:
	struct Node
	{
		Node(const Customer &aCustomer)
		{
			data = new Customer(aCustomer);
			next = nullptr;
		}
		~Node()
		{
			delete data;
			data = nullptr;
			next = nullptr;
		}
		Customer *data;
		Node *next;
	};
	Node *head, *tail;
	unsigned int size;
	void destroy(Node *&curr);
};

#endif
