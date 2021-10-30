/*
      Name: 	Ashish Kumar
Student ID: 	G04065243
    Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
*/
// This module contains the code for the member functions of the class Queue
#include "queue.h"


Queue::Queue() : head(nullptr), tail(nullptr), size(0) {}



Queue::Queue(const Queue &aQueue) : head(nullptr), tail(nullptr), size(0)
{
    //Copy constructor
    *this = aQueue;
}



Queue::~Queue()
{
    /*
    Member function to destroy the linked list queue
    INPUT:
        None
    OUTPUT:
        None
    */
    destroy(head);
}



void Queue::destroy(Node *&curr)
{
    /*
    Recursive destroy function to destroy the queue data.
    INPUT:
        curr: pointer to the current node in the queue linked list
    OUTPUT:
        None
    */
    if (curr)
    {
        if (curr->next != head)
        {
            destroy(curr->next);
        }
        delete curr;
        curr = nullptr;
        --size;
        if (size == 0)
        {
            head = nullptr;
            tail = nullptr;
        }
    }
}



void Queue::enqueue(const Customer &a_customer)
{
    /*
    Member function to add a data to the linked list
    INPUT:
        a_customer: A Customer class instance that contains the customer group data from queue
    OUTPUT:
        None
    */
    Node *newnode = new Node(a_customer);
    if (!head)
    {
        head = newnode;
        tail = newnode;
        tail->next = head;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    ++size;
}



bool Queue::dequeue(Customer &a_customer)
{
    /*
    Member function to remove the first node from the queue and send data through
    empty a_customer instance
    INPUT:
        a_customer: An empty Customer class instance that will be used to send
                    back the queue data
    OUTPUT:
		true if successful, false otherwise
    */
    bool deque_flag = false;

    if (size == 0)
    {
        cout << "The queue is empty. Nothing to dequeue." << endl;
    }
    else
    {
        Node *curr = head;
        a_customer = *(head->data);
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete curr;
        curr = nullptr;
        --size;
        deque_flag = true;
    }
    return deque_flag;
}



bool Queue::peek(Customer &a_customer)
{
    /*
    Member function to take a peek at first node from the queue and send data
    back through empty a_customer instance
    INPUT:
        a_customer: An empty Customer class instance that will be used to send
                    back the queue data
    OUTPUT:
		true if successful, false otherwise
    */
    bool ret = false;
    if (head)
    {
        a_customer = *(head->data);
        ret = true;
    }
    else
    {
        cout << "The queue is empty. Nothing to peek." << endl;
    }
    return ret;
}



void Queue::display()
{
    //Display the entire queue
    Node *curr = head;
    int counter = 1;
    cout << endl;
    bool flag = curr ? true : false;

    while (flag || (curr && (curr != head)))
    {
        flag = false;
        cout << "[" << counter << "] " << *(curr->data) << endl;
        curr = curr->next;
        counter++;
    }
    cout << endl;
    if (size == 0)
        cout << "No customers in queue.  Queue is empty!" << endl;
    cout << "Total number of customers in queue: " << size << endl;
}



const unsigned int Queue::get_size()
{
    // return the size of the queue
    return size;
}



const Queue &Queue::operator=(const Queue &aQueue)
{
    // Overloaded = operator
    if (this == &aQueue)
        return *this;
    destroy(head);
    size = aQueue.size;
    if (!aQueue.head)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        return *this;
    }

    Node *newNode = new Node(*(aQueue.head->data));
    head = newNode;

    Node *nextSrc = aQueue.head->next;
    Node *nextDes = head;
    while (nextSrc)
    {
        newNode = new Node(*(nextSrc->data));
        nextDes->next = newNode;
        if (!nextSrc->next)
            tail = nextSrc;
        nextSrc = nextSrc->next;
        nextDes = nextDes->next;
    }
    return *this;
}



ostream &operator<<(ostream &out, const Queue &aQueue)
{
    /*
    Overloaded operator to output the linked list
    */
    Queue::Node *curr;

    out << endl
        << "Displaying the list ... " << endl;
    for (curr = aQueue.head; curr; curr = curr->next)
    {
        out << *(curr->data) << endl;
    }
    out << endl;
    out << "# of customers in queue: " << aQueue.size << endl;

    return out;
}



void Queue::loadFromFile(const char *fileName)
{
    /*
    Member function to load test cases from a file
    INPUT:
        filename: name of the file that contains the test data set
    OUTPUT:
        None
    */
    ifstream fh;
    Customer currCustomer;
    const int MAX_CHAR = 256;
    char curr_grp_name[MAX_CHAR];
    unsigned int curr_grp_size = 0;
    char curr_sp_req[MAX_CHAR], curr_contact_name[MAX_CHAR], curr_contact_email[MAX_CHAR];
    bool curr_promo_mat;
    char temp[MAX_CHAR];

    fh.open(fileName);
    if (!fh)
    {
        std::cout << "Fail to open " << fileName << " for reading." << std::endl;
        exit(1);
    }

    fh.getline(curr_grp_name, MAX_CHAR, '|');
    while (!fh.eof())
    {
        fh.getline(temp, MAX_CHAR, '|');
        curr_grp_size = atoi(temp);
        fh.getline(curr_sp_req, MAX_CHAR, '|');
        fh.getline(temp, MAX_CHAR, '|');
        curr_promo_mat = bool(atoi(temp));
        fh.getline(curr_contact_name, MAX_CHAR, '|');
        fh.getline(curr_contact_email, MAX_CHAR, '\n');

        currCustomer.set_group_name(curr_grp_name);
        currCustomer.set_group_size(curr_grp_size);
        currCustomer.set_special_rq(curr_sp_req);
        currCustomer.set_promo_mat(curr_promo_mat);
        currCustomer.set_contact_name(curr_contact_name);
        currCustomer.set_contact_email(curr_contact_email);
        enqueue(currCustomer);

        fh.getline(curr_grp_name, MAX_CHAR, '|');
    }
    fh.close();
}



void Queue::saveToFile(const char *fileName) const
{
    /*
    Member function to save customer list out to a file
    INPUT:
        filename: name of the file that contains the test data set
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

    for (Node *curr = head; curr; curr = curr->next)
    {
        out << curr->data->get_group_name() << '|' << curr->data->get_group_size() << '|' << curr->data->get_special_rq() << '|' << int(curr->data->get_promo_mat()) << '|' << curr->data->get_contact_name() << '|' << curr->data->get_contact_email() << endl;
    }
    out.close();
}
