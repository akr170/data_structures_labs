#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream &operator<<(std::ostream &out, LinkedList &list);

private:
	struct Node
	{
		Node(const char ch)
		{
			data = ch;
			next = nullptr;
		}
		~Node()
		{
			next = nullptr;
		}
		char data;
		Node *next;
	};
	Node *head;
	int size;
	void destroy(Node *curr);
	void add(Node *&newnode, Node *&curr);
	bool find(char ch, const Node *curr);
	bool del(char ch, Node *curr_prev, Node *curr);
};

#endif // _LINKED_LIST_
