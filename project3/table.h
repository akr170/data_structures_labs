/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 3
*/
#ifndef TABLE_H
#define TABLE_H
#include "website.h"
#include <fstream>

class Table
{
public:
	Table();
	Table(const Table &aTable);
	~Table();

	void add(const Website &aWebsite);
	bool does_website_exist(const Website &aWebsite);
	bool set_new_edits(const Website &aWebsite);
	unsigned int remove_websites();
	void monitor_performance();
	bool retrieve_data(char *topic_keyword, Website all_matches[], unsigned int &num_found);
	unsigned int getSize() const;
	/*
	bool remove(const char * key, Website& aWebsite);
	bool retrieve(const char * key, Website& aWebsite) const;
	*/
	const Table &operator=(const Table &aTable);
	friend ostream &operator<<(ostream &out, const Table &aTable);

	void loadFromFile(const char *fileName);
	void saveToFile(const char *fileName) const;

private:
	struct Node
	{
		Node(const Website &aWebsite)
		{
			data = new Website(aWebsite);
			next = nullptr;
		};

		Website *data;
		Node *next;
	};
	Node **aTable;
	const static int INIT_CAP = 10;
	int currCapacity;
	int size;

	int calculateIndex(const char *key) const;
	void destroy();
	void destroyChain(Node *&currHead);
	void copyChain(Node *srcHead, Node *&destHead);
	void displayChain(ostream &out, Node *currHead) const;
	void writeOutChain(ostream &out, Node *currHead) const;
};

#endif
