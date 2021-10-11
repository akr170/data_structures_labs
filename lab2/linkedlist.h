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

	friend std::ostream &operator<<(std::ostream &out, const LinkedList &list);

private:
	void destroy();
	struct Node
	{
		Node(const char ch)
		{
			data = ch;
			prev = next = nullptr;
		}
		~Node()
		{
			prev = next = nullptr;
		}
		char data;
		Node *prev, *next;
	};
	Node *head, *tail;
	int size;
};

#endif // _LINKED_LIST_
