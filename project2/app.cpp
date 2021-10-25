/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 2
*/

#include <iostream>
using namespace std;
#include "customer.h"
#include "customerinfo.h"
#include "queue.h"
#include "stack.h"



void create_a_new_stack_save();
void enqueue_customer(Queue &aQueue);
void dequeue_customer(Queue &aQueue, Stack &aStack);
void peek_customer(Queue &aQueue);
void display_queue(Queue &aQueue);
void pop_from_stack(Stack &aStack);
void peek_from_stack(Stack &aStack);
void display_stack(Stack &aStack);
void pop_rest_of_the_data_from_stack(Stack &aStack);



int main()
{
	// Main function: Entry point for the code.
	Queue aQueue;
	Stack aStack;
	Customer aCustomer;
	char filename_queue[] = "customer_queue.txt";
	char filename_stack[] = "customer_stack.txt";
	char choice_in; // variable to store user input (bad input is okay as we are storing it as char)
	int choice = 0; // variable to store user input after it is converted to int
	const char menu[] = "Menu Options:\n"
						"[1] Enqueue new customer\n"
						"[2] Dequeue next customer\n"
						"[3] Peek next customer\n"
						"[4] Display the entire queue\n"
						"[5] Pop a customer info from stack\n"
						"[6] Peek a customer info from stack\n"
						"[7] Display stack\n"
						"[8] Exit the program\n";

	create_a_new_stack_save();
	aQueue.loadFromFile(filename_queue);
	aStack.loadFromFile(filename_stack);

	while (choice != 8)
	{
		switch (choice)
		{
		case 1:
			enqueue_customer(aQueue);
			break;
		case 2:
			dequeue_customer(aQueue, aStack);
			break;
		case 3:
			peek_customer(aQueue);
			break;
		case 4:
			display_queue(aQueue);
			break;
		case 5:
			pop_from_stack(aStack);
			break;
		case 6:
			peek_from_stack(aStack);
			break;
		case 7:
			display_stack(aStack);
			break;
		}
		cout << endl;
		cout << endl;
		cout << menu << endl;
		cout << "Enter a choice from the above menu: ";
		cin >> choice_in;
		choice = (int)choice_in - 48;
	}
	pop_rest_of_the_data_from_stack(aStack);
	return 0;
}



void enqueue_customer(Queue &aQueue)
{
	/*
	Helper function to get user input and enqueue a customer group to the queue
	INPUT:
		aQueue: An instance of the Queue class
	OUTPUT:
		None
	*/
	Customer aCustomer;
	const int MAX_CHAR = 256;
	char temp[MAX_CHAR];
	char curr_group_name[MAX_CHAR];
	unsigned int curr_group_size = 0;
	char curr_sp_req[MAX_CHAR];
	bool curr_promo;
	char curr_contact_name[MAX_CHAR];
	char curr_contact_email[MAX_CHAR];

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "-----------------------------------------" << endl;
	cout << "Enter information about new customer     " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Enter group name (enter string): ";
	cin.getline(curr_group_name, MAX_CHAR);
	cout << "Enter group size (enter int): ";
	cin.getline(temp, MAX_CHAR);
	curr_group_size = atoi(temp);
	cout << "Enter special requests (enter string): ";
	cin.getline(curr_sp_req, MAX_CHAR);
	cout << "Does customer want promo materials? (Enter char y/n): ";
	cin.getline(temp, MAX_CHAR);
	curr_promo = (strcmp(temp, "y") == 0) ? true : false;
	aCustomer.set_group_name(curr_group_name);
	aCustomer.set_group_size(curr_group_size);
	aCustomer.set_special_rq(curr_sp_req);
	aCustomer.set_promo_mat(curr_promo);
	if (curr_promo)
	{
		cout << "Enter customer name (enter string): ";
		cin.getline(curr_contact_name, MAX_CHAR);
		cout << "Enter customer email (enter string): ";
		cin.getline(curr_contact_email, MAX_CHAR);
		aCustomer.set_contact_name(curr_contact_name);
		aCustomer.set_contact_email(curr_contact_email);
	}
	else
	{
		aCustomer.set_contact_name("");
		aCustomer.set_contact_email("");
	}
	aQueue.enqueue(aCustomer);

	cout << endl;
	cout << "Added new customer to the queue." << endl;
	cout << "New customer position in queue: " << aQueue.get_size() << endl;
}



void dequeue_customer(Queue &aQueue, Stack &aStack)
{
	/*
	Helper function to retrieve the first customer group information from the queue
	and then shift the head of the Queue to the next data point
	INPUT:
		aQueue: An instance of the Queue class
	OUTPUT:
		None
	*/
	bool dequeue_flag = false;
	Customer aCustomer;
	CustomerInfo aCustomerInfo;

	cout << endl;
	cout << endl;
	dequeue_flag = aQueue.dequeue(aCustomer);
	if (dequeue_flag)
	{
		cout << "-----------------------------------------" << endl;
		cout << "Next customer in queue has been dequeued " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "           Customer dequeued: " << aCustomer << endl;
		cout << "# of customer still in queue: " << aQueue.get_size() << endl;
		if (aCustomer.get_promo_mat())
		{
			aCustomerInfo.set_contact_name(aCustomer.get_contact_name());
			aCustomerInfo.set_contact_email(aCustomer.get_contact_email());
			aStack.push(aCustomerInfo);
		}
	}
}



void peek_customer(Queue &aQueue)
{
	/*
	Helper function to retrieve and display the first customer group information
	from the queue
	INPUT:
		aQueue: An instance of the Queue class
	OUTPUT:
		None
	*/
	bool peek_flag = false;
	Customer aCustomer;

	cout << endl;
	cout << endl;
	peek_flag = aQueue.peek(aCustomer);
	if (peek_flag)
	{
		cout << "-----------------------------------------" << endl;
		cout << "Information about next customer in queue " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "        Group Name: " << aCustomer.get_group_name() << endl;
		cout << "        Group Size: " << aCustomer.get_group_size() << endl;
		cout << "  Special Requests: " << aCustomer.get_special_rq() << endl;
		cout << "   Promo material?: " << (aCustomer.get_promo_mat() ? "yes" : "no") << endl;
		cout << "     Customer name: " << aCustomer.get_contact_name() << endl;
		cout << "    Customer email: " << aCustomer.get_contact_email() << endl;
	}
}



void display_queue(Queue &aQueue)
{
	/*
	Helper function to display the entire queue
	INPUT:
		aQueue: An instance of the Queue class
	OUTPUT:
		None
	*/
	cout << endl;
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Displaying current queue" << endl;
	cout << "-----------------------------------------" << endl;
	aQueue.display();
	cout << endl;
}



void pop_from_stack(Stack &aStack)
{
	/*
	Helper function to retrieve the last inputted data from the stack and then
	decrement the stack pointer.
	INPUT:
		aStack: An instance of the Stack class
	OUTPUT:
		None
	*/
	CustomerInfo aCustomerInfo;
	bool pop_flag = false;
	char output_filename[] = "save_customer_stack_data.txt";

	cout << endl;
	cout << endl;
	pop_flag = aStack.pop(aCustomerInfo);
	if (pop_flag)
	{
		cout << "----------------------------------------------" << endl;
		cout << "Last customer info from stack has been popped " << endl;
		cout << "----------------------------------------------" << endl;
		cout << "                    Customer name: " << aCustomerInfo.get_contact_name() << endl;
		cout << "                   Customer email: " << aCustomerInfo.get_contact_email() << endl;
		cout << "# of customer info still in stack: " << aStack.get_top() << endl;
		cout << endl;
		cout << "The above customer info has been saved to the file:  " << output_filename << endl;

		ofstream out;
		out.open(output_filename, std::ios::out | std::ios::app);
		if (!out)
		{
			cerr << "Fail to open " << output_filename << " for writing!" << endl;
			exit(1);
		}

		out << aCustomerInfo.get_contact_name() << "|" << aCustomerInfo.get_contact_email() << endl;

		out.close();
	}
}



void peek_from_stack(Stack &aStack)
{
	/*
	Helper function to retrieve and display the last inputted data from the stack.
	INPUT:
		aStack: An instance of the Stack class
	OUTPUT:
		None
	*/
	CustomerInfo aCustomerInfo;
	bool peek_flag = false;

	cout << endl;
	cout << endl;
	peek_flag = aStack.peek(aCustomerInfo);
	if (peek_flag)
	{
		cout << "----------------------------------------------" << endl;
		cout << "Peeking last customer info from stack         " << endl;
		cout << "----------------------------------------------" << endl;
		cout << " Customer name: " << aCustomerInfo.get_contact_name() << endl;
		cout << "Customer email: " << aCustomerInfo.get_contact_email() << endl;
	}
}



void display_stack(Stack &aStack)
{
	/*
	Helper function to display the entire stack.
	INPUT:
		aStack: An instance of the Stack class
	OUTPUT:
		None
	*/
	cout << endl;
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Displaying current stack                 " << endl;
	cout << "-----------------------------------------" << endl;
	aStack.display();
	cout << endl;
}



void create_a_new_stack_save()
{
	/*
	Helper function to create a new file to save the customer information from the stack.
	INPUT:
		None
	OUTPUT:
		None
	*/
	char output_filename[] = "save_customer_stack_data.txt";
	ofstream out;
	out.open(output_filename, std::ios::trunc);
	if (!out)
	{
		cerr << "Fail to open " << output_filename << " for writing!" << endl;
		exit(1);
	}
	out.close();
}



void pop_rest_of_the_data_from_stack(Stack &aStack)
{
	/*
	Helper function to save rest of the data present on the stack into a file on the disk
	This is done so that no customer informaiton data is lost on program exit.
	INPUT:
		aStack: An instance of the Stack class
	OUTPUT:
		None
	*/
	CustomerInfo aCustomerInfo;
	bool pop_flag = aStack.pop(aCustomerInfo);
	char output_filename[] = "save_customer_stack_data.txt";

	while (pop_flag)
	{
		ofstream out;
		out.open(output_filename, std::ios::out | std::ios::app);
		if (!out)
		{
			cerr << "Fail to open " << output_filename << " for writing!" << endl;
			exit(1);
		}

		out << aCustomerInfo.get_contact_name() << "|" << aCustomerInfo.get_contact_email() << endl;

		out.close();

		pop_flag = aStack.pop(aCustomerInfo);
	}
}
