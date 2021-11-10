#include "dlist.h"

//put the implmenetation of the required functions here

int sumEven(node * head)
{
    /*
    Recursively computes the sum of the nodes that contain even data
    INPUT:
        head: pointer to the head of the linked list
    OUTPUT:
        sum of the even numbers in the linked list
    */
    int sum = 0;
    if (head)
    {
        if (head->data % 2 == 0)
        {
            sum += head->data;
        }
        if (head->next)
        {      
            sum += sumEven(head->next);
        }
    }
    return sum;
}

int tagEven(node *& head)
{
    /*
    Recursively tags the nodes that contain even data
    INPUT:
        head: pointer to the head of the linked list
    OUTPUT:
        total number of nodes tagged
    */
    int num_tagged = 0;
    if (head)
    {
        if (head->data%2==0)
        {
            node* newnode = new node();
            newnode->data = -1;
            newnode->previous = head;
            newnode->next = head->next;
            if (head->next)
            {
                head->next->previous = newnode;
            }
            head->next = newnode;
            ++num_tagged;
        }
        if (head->next)
        {
            num_tagged += tagEven(head->next);
        }
    }
    return num_tagged;
}
