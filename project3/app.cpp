/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 3
*/

#include <iostream>
using namespace std;
#include "website.h"
#include "table.h"



void add_a_website(Table &aTable);
void modify(Table &aTable);
void remove_websites(Table &aTable);
void retrieve_data(Table &aTable);
void display_data_by_topic(Table &aTable);



int main()
{
	// Main function: Entry point for the code.
	Table aTable;
	Website aWebsite;
	char filename_table[] = "initial_web_data.txt";
	char choice_in; // variable to store user input (bad input is okay as we are storing it as char)
	int choice = 0; // variable to store user input after it is converted to int
	const char menu[] = "Menu Options:\n"
						"[1] Insert a new website by topic\n"
						"[2] Retrieve websites by topic\n"
						"[3] Modify rating/review of a website\n"
						"[4] Remove websites with 1 star rating\n"
						"[5] Display websites by topic\n"
						"[6] Display all websites\n"
						"[7] Monitor performance of hash table\n"
						"[8] Exit the program\n";

	aTable.loadFromFile(filename_table);

	while (choice != 8)
	{
		switch (choice)
		{
		case 1:
			add_a_website(aTable);
			break;
		case 2:
			retrieve_data(aTable);
			break;
		case 3:
			modify(aTable);
			break;
		case 4:
			remove_websites(aTable);
			break;
		case 5:
			display_data_by_topic(aTable);
			break;
		case 6:
			cout << aTable << endl;
			break;
		case 7:
			aTable.monitor_performance();
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



void add_a_website(Table &aTable)
{
	/*
	Helper function to get user input and website data to the table
	INPUT:
		aTable: An instance of the Table class
	OUTPUT:
		None
	*/
	Website aWebsite;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_topic[MAX_CHAR], curr_addr[MAX_CHAR];
	char curr_summary[MAX_CHAR], curr_review[MAX_CHAR];
	unsigned int curr_rating;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "-----------------------------------------" << endl;
	cout << "Enter information about new website     " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Enter website topic keyword (enter string): ";
	cin.getline(curr_topic, MAX_CHAR);
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
	aWebsite.set_address(curr_addr);
	aWebsite.set_summary(curr_summary);
	aWebsite.set_review(curr_review);
	aWebsite.set_rating(curr_rating);

	aTable.add(aWebsite);

	cout << endl;
	cout << "Added new website to the table." << endl;
}



void modify(Table &aTable)
{
	/*
	Helper function to input website topic and url from the user, check whether
	the website exists in the table or not.  If the website does exist in the
	table then, asks user to input the updated review and rating and then calls
	the table member function that helps edit the review and rating for the website
	INPUT:
		aTable: An instance of the Table class
	OUTPUT:
		None
	*/
	Website aWebsite;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_topic[MAX_CHAR], curr_addr[MAX_CHAR];
	char curr_review[MAX_CHAR];
	unsigned int curr_rating;
	bool found_flag = false;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "----------------------------------------------" << endl;
	cout << "Enter information about website to be modified" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter website topic keyword (enter string): ";
	cin.getline(curr_topic, MAX_CHAR);
	cout << "Enter website address (enter string): ";
	cin.getline(curr_addr, MAX_CHAR);

	aWebsite.set_topic(curr_topic);
	aWebsite.set_address(curr_addr);

	found_flag = aTable.does_website_exist(aWebsite);

	if (found_flag)
	{
		cout << "Website exists!" << endl;
		cout << "Enter website review (enter string): ";
		cin.getline(curr_review, MAX_CHAR);
		cout << "Enter website rating (enter int): ";
		cin.getline(temp, MAX_CHAR);
		curr_rating = atoi(temp);
		aWebsite.set_review(curr_review);
		aWebsite.set_rating(curr_rating);
		aTable.set_new_edits(aWebsite);
	}
	else
	{
		cout << "Website does not exist!";
	}
}



void remove_websites(Table &aTable)
{
	/*
	Helper function to remove websites from the table with 1 star rating
	INPUT:
		aTable: An instance of the Table class
	OUTPUT:
		None
	*/
	cout << endl;
	cout << endl;
	cout << "Number of websites removed: " << aTable.remove_websites() << endl;
}



void retrieve_data(Table &aTable)
{
	/*
	Helper function to retrieve website data from the table by topic
	INPUT:
		aTable: An instance of the Table class
	OUTPUT:
		None
	*/
	unsigned int max_entries = aTable.getSize();
	Website all_matches[max_entries];
	unsigned int num_found = 0;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_topic[MAX_CHAR];
	bool found_something;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "----------------------------------------------" << endl;
	cout << "Enter topic keyword to retrieve websites      " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter website topic keyword (enter string): ";
	cin.getline(curr_topic, MAX_CHAR);
	found_something = aTable.retrieve_data(curr_topic, all_matches, num_found);
	if (found_something)
	{
		cout << "retrieval successful!" << endl;
		cout << "Entries retrieved: " << num_found << endl;
	}
	else
	{
		cout << "nothing retrieved!" << endl;
	}
}



void display_data_by_topic(Table &aTable)
{
	/*
	Helper function to retrieve website data from the table and display those on
	screen
	INPUT:
		aTable: An instance of the Table class
	OUTPUT:
		None
	*/
	unsigned int max_entries = aTable.getSize();
	Website all_matches[max_entries];
	unsigned int num_found = 0;
	const int MAX_CHAR = 1024;
	char temp[MAX_CHAR];
	char curr_topic[MAX_CHAR];
	bool found_something;

	cout << endl;
	cout << endl;
	cin.getline(temp, MAX_CHAR);
	cout << "----------------------------------------------" << endl;
	cout << "Enter topic keyword to retrieve websites      " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter website topic keyword (enter string): ";
	cin.getline(curr_topic, MAX_CHAR);
	found_something = aTable.retrieve_data(curr_topic, all_matches, num_found);
	if (found_something)
	{
		cout << "retrieval successful!" << endl;
		for (unsigned int i = 0; i < num_found; ++i)
		{
			cout << endl;
			cout << all_matches[i] << endl;
			cout << endl;
		}
		cout << "Entries retrieved: " << num_found << endl;
	}
	else
	{
		cout << "nothing retrieved!" << endl;
	}
}
