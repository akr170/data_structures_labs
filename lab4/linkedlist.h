#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(int value);

	int sum();	// sum of ints in list, calculated iteratively
	int sumR(); // sum of ints in list, calculated recursively

	friend std::ostream &operator<<(std::ostream &out, LinkedList &list);

private:
	struct Node
	{
		Node(int value) : value(value), next(nullptr) {}
		Node(int value, Node *next) : value(value), next(next) {}
		~Node() { next = nullptr; }

		int value;
		Node *next;
	};

	int _sumR(Node *node); // sum of ints in list, calculated recursively

	void destroy(Node *curr);
	void add(Node *&newnode, Node *&curr);
	Node *head;
};

#endif // _LINKED_LIST_
