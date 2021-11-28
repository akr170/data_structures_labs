/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 4
*/

#include <iostream>
using namespace std;
#include "website.h"
#include "bst.h"

void add_a_website(BinarySearchTree &aBinarySearchTree);
void remove_websites_by_topic(BinarySearchTree &aBinarySearchTree);
void remove_websites_by_keyword(BinarySearchTree &aBinarySearchTree);
void retrieve_data(BinarySearchTree &aBinarySearchTree);
void display_all_data(BinarySearchTree &aBinarySearchTree);

int main()
{
	// Main function: Entry point for the code.
	BinarySearchTree aBinarySearchTree;
	Website aWebsite;
	char filename_table[] = "initial_web_data.txt";
	char choice_in; // variable to store user input (bad input is okay as we are storing it as char)
	int choice = 0; // variable to store user input after it is converted to int
	const char menu[] = "Menu Options:\n"
						"[1] Insert a new website by keyword\n"
						"[2] Retrieve websites by keyword\n"
						"[3] Remove all matches to a topic name\n"
						"[4] Remove a particular website based on keyword\n"
						"[5] Display all websites\n"
						"[6] Monitor the height of the Binary Search Tree\n"
						"[7] Exit the program\n";

	aBinarySearchTree.loadFromFile(filename_table);

	while (choice != 7)
	{
		switch (choice)
		{
		case 1:
			add_a_website(aBinarySearchTree);
			break;
		case 2:
			retrieve_data(aBinarySearchTree);
			break;
		case 3:
			remove_websites_by_topic(aBinarySearchTree);
			break;
		case 4:
			remove_websites_by_keyword(aBinarySearchTree);
			break;
		case 5:
			cout << aBinarySearchTree << endl;
			break;
		case 6:
			cout << endl;
			cout << endl;
			aBinarySearchTree.monitor_performance();
			break;
		}
		cout << endl;
		cout << endl;
		cout << menu << endl;
		cout << "Enter a choice from the above menu: ";
		cin >> choice_in;
		choice = (int)choice_in - 48;
	}
	return 0;
}

void add_a_website(BinarySearchTree &aBinarySearchTree)
{
	/*
	Helper function to get user input and website data to the table
	INPUT:
		aBinarySearchTree: An instance of the BinarySearchTree class
	OUTPUT:
		None
	*/
	Website aWebsite;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_topic[MAX_CHAR], curr_keyword[MAX_CHAR], curr_addr[MAX_CHAR];
	char curr_summary[MAX_CHAR], curr_review[MAX_CHAR];
	unsigned int curr_rating;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "-----------------------------------------" << endl;
	cout << "Enter information about new website     " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Enter website topic (enter string): ";
	cin.getline(curr_topic, MAX_CHAR);
	cout << "Enter website keyword (enter string): ";
	cin.getline(curr_keyword, MAX_CHAR);
	cout << "Enter website address (enter string): ";
	cin.getline(curr_addr, MAX_CHAR);
	cout << "Enter website summary (enter string): ";
	cin.getline(curr_summary, MAX_CHAR);
	cout << "Enter website review (enter string): ";
	cin.getline(curr_review, MAX_CHAR);
	cout << "Enter website rating (enter int): ";
	cin.getline(temp, MAX_CHAR);
	curr_rating = atoi(temp);

	aWebsite.set_topic(curr_topic);
	aWebsite.set_keyword(curr_keyword);
	aWebsite.set_address(curr_addr);
	aWebsite.set_summary(curr_summary);
	aWebsite.set_review(curr_review);
	aWebsite.set_rating(curr_rating);

	aBinarySearchTree.insert(aWebsite);

	cout << endl;
	cout << "Added new website to the table." << endl;
}

void remove_websites_by_topic(BinarySearchTree &aBinarySearchTree)
{
	/*
	Helper function to remove websites from the table with 1 star rating
	INPUT:
		aBinarySearchTree: An instance of the BinarySearchTree class
	OUTPUT:
		None
	*/
	unsigned int max_entries = aBinarySearchTree.getSize();
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_key[MAX_CHAR];
	bool removed_something;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "----------------------------------------------" << endl;
	cout << "Enter topic to remove websites by topic       " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter website topic (enter string): ";
	cin.getline(curr_key, MAX_CHAR);
	removed_something = aBinarySearchTree.remove_by_topic(curr_key);
	if (removed_something)
	{
		cout << "Removal successful!" << endl;
		cout << "Number of entries present earlier in the BST: " << max_entries << endl;
		cout << "New number of entries in the BST: " << aBinarySearchTree.getSize() << endl;
		cout << "Number of entries removed: " << (max_entries - aBinarySearchTree.getSize()) << endl;
	}
	else
	{
		cout << "Removed nothing!" << endl;
	}
}

void remove_websites_by_keyword(BinarySearchTree &aBinarySearchTree)
{
	/*
	Helper function to remove websites from the table with 1 star rating
	INPUT:
		aBinarySearchTree: An instance of the BinarySearchTree class
	OUTPUT:
		None
	*/
	unsigned int max_entries = aBinarySearchTree.getSize();
	Website aWebsite;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_key[MAX_CHAR];
	bool removed_something;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "----------------------------------------------" << endl;
	cout << "Enter keyword to remove websites by keyword   " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter website keyword (enter string): ";
	cin.getline(curr_key, MAX_CHAR);
	removed_something = aBinarySearchTree.remove_by_keyword(curr_key, aWebsite);
	if (removed_something)
	{
		cout << "Removal successful!" << endl;
		cout << "Number of entries present earlier in the BST: " << max_entries << endl;
		cout << "New number of entries in the BST: " << aBinarySearchTree.getSize() << endl;
		cout << "Number of entries removed: " << (max_entries - aBinarySearchTree.getSize()) << endl;
	}
	else
	{
		cout << "Removed nothing!" << endl;
	}
}

void retrieve_data(BinarySearchTree &aBinarySearchTree)
{
	/*
	Helper function to retrieve website data from the table by topic
	INPUT:
		aBinarySearchTree: An instance of the BinarySearchTree class
	OUTPUT:
		None
	*/
	Website aWebsite;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_key[MAX_CHAR];
	bool found_something;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "----------------------------------------------" << endl;
	cout << "Enter website keyword to retrieve websites      " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter website keyword (enter string): ";
	cin.getline(curr_key, MAX_CHAR);
	found_something = aBinarySearchTree.retrieve(curr_key, aWebsite);
	if (found_something)
	{
		cout << "retrieval successful!" << endl;
	}
	else
	{
		cout << "nothing retrieved!" << endl;
	}
}
