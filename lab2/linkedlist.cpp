#include "linkedlist.h"

//implementations for the member functions of LinkedList class

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList()
{
    destroy();
}

void LinkedList::destroy()
{
    /*
    Member function to destroy the linked list
    */
    Node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    size = 0;
}

void LinkedList::add(char ch)
{
    /*
    Member function to add a data to the linked list
    */
    Node *newnode = new Node(ch);
    if (!head)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    size++;
}

bool LinkedList::find(char ch)
{
    /*
    Member function to determine if a data exists
    */
    bool found = false;
    Node *curr = head;
    while (curr && !found)
    {
        if (ch == curr->data)
        {
            found = true;
        }
        else
        {
            curr = curr->next;
        }
    }
    return found;
}

bool LinkedList::del(char ch)
{
    /*
    Member function to delete a data point
    */
    bool deleted = false;
    Node *curr = head;
    while (curr && !deleted)
    {
        if (ch == curr->data)
        {
            if (curr->prev)
            {
                curr->prev->next = curr->next;
            }
            else
            {
                head = curr->next;
                if (curr->next)
                {
                    curr->next->prev = nullptr;
                }
            }
            if (curr->next)
            {
                curr->next->prev = curr->prev;
            }
            else
            {
                tail = curr->prev;
                if (curr->prev)
                {
                    curr->prev->next = nullptr;
                }
            }
            delete curr;
            deleted = true;
            --size;
        }
        else
        {
            curr = curr->next;
        }
    }
    return deleted;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &aLinkedList)
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
