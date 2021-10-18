#include "linkedlist.h"

// implementations for the member functions of LinkedList class

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList()
{
    destroy(head);
}

void LinkedList::destroy(Node *curr)
{
    /*
    Member function to destroy the linked list
    */
    if (curr)
    {
        head = curr->next;
        delete curr;
        --size;
        destroy(head);
    }
}

void LinkedList::add(char ch)
{
    /*
    Member function to add a data to the linked list
    */
    Node *newnode = new Node(ch);
    add(newnode, head);
}

void LinkedList::add(Node *&newnode, Node *&curr)
{
    if (!curr)
    {
        curr = newnode;
        ++size;
    }
    else
    {
        add(newnode, curr->next);
    }
}

bool LinkedList::find(char ch)
{
    /*
    Member function to determine if a data exists
    */
    bool found = find(ch, head);
    return found;
}

bool LinkedList::find(char ch, const Node *curr)
{
    bool found = false;
    if (curr)
    {
        if (curr->data == ch)
        {
            found = true;
        }
        else
        {
            found = find(ch, curr->next);
        }
    }
    return found;
}

bool LinkedList::del(char ch)
{
    /*
    Member function to delete a data point
    */
    bool deleted = del(ch, nullptr, head);
    return deleted;
}

bool LinkedList::del(char ch, Node *curr_prev, Node *curr)
{
    /*
    Recursively traverses the linked list to search for the data and then
    deletes the first node where data is found.
    INPUT:
        ch: the data that needs to be deleted
        curr_prev: the pointer to the previous node.  This is null if the
                   current node is head
        curr: the pointer to the current node
    RETURNS:
        true if deletion is successful, false otherwise.
    */
    bool deleted = false;
    if (curr)
    {
        if (curr->data == ch)
        {
            if (curr_prev)
            {
                curr_prev->next = curr->next;
            }
            else
            {
                head = curr->next;
            }
            delete curr;
            deleted = true;
        }
        else
        {
            deleted = del(ch, curr, curr->next);
        }
    }
    return deleted;
}

std::ostream &operator<<(std::ostream &out, LinkedList &aLinkedList)
{
    /*
    Friend function to overload the << operator
    */
    LinkedList::Node *curr;
    out << "Displaying the linked list:  ";
    for (curr = aLinkedList.head; curr; curr = curr->next)
    {
        out << curr->data << " ";
    }
    out << std::endl;
    return out;
}
