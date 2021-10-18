// Write your functions in this file.
#include "clist.h"

int count(node *head)
{
    // Iterative method to count the number of nodes.
    node *curr = head->next;
    int counter = 1;

    while (curr != head)
    {
        ++counter;
        curr = curr->next;
    }
    return counter;
}

int countR(node *head)
{
    // Recursive method to count number of nodes.
    int counter = countR(head, head->next);
    return counter;
}

int countR(node *head, node *curr)
{
    // Recursive method to count number of nodes.
    int counter = 0;

    if (curr == head)
    {
        counter = 1;
    }
    else
    {
        counter += 1 + countR(head, curr->next);
    }
    return counter;
}

int sum(node *head)
{
    // Iterative method to compute sum of values stored in the nodes
    node *curr = head->next;
    int sum = head->data;

    while (curr != head)
    {
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

int sumR(node *head)
{
    // Recursive method to compute sum of values stored in the nodes
    int sum = sumR(head, head->next);
    return sum;
}

int sumR(node *head, node *curr)
{
    // Recursive method to compute sum of values stored in the nodes
    int sum = 0;

    if (curr == head)
    {
        sum = head->data;
    }
    else
    {
        sum += curr->data + sumR(head, curr->next);
    }
    return sum;
}
