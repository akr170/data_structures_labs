/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 3
*/
#include "table.h"



Table::Table() : size(0)
{
	// Table constructor
	currCapacity = INIT_CAP;
	aTable = new Node *[currCapacity];
	for (int i = 0; i < currCapacity; i++)
	{
		aTable[i] = nullptr;
	}
}



Table::Table(const Table &aTable) : aTable(nullptr), size(0)
{
	// Table copy constructor
	*this = aTable;
}



Table::~Table()
{
	// Table destructor
	destroy();
}



void Table::destroy()
{
	// Helper function for table destructor
	for (int i = 0; i < currCapacity; i++)
	{
		destroyChain(aTable[i]);
	}
	if (aTable)
		delete[] aTable;
}



void Table::destroyChain(Node *&currHead)
{
	// Helper function to destroy a chain in a table element
	if (currHead)
	{
		destroyChain(currHead->next);
		delete currHead->data;
		delete currHead;
		currHead = nullptr;
	}
}



void Table::add(const Website &aWebsite)
{
	/*
	Adds website to the table
	INPUT:
		aWebsite:  A website object
	OUTPUT:
		None
	*/
	int index = calculateIndex(aWebsite.get_topic());
	Node *newNode = new Node(aWebsite);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}



/*
A naive hashing function that only adds the ASCII value of each char in the
key field and mods the capacity of the table. i.e. "abc" and "cba" will result
in the same index since it doesn't consider position value.
*/
int Table::calculateIndex(const char *key) const
{
	int hashingResult;

	// version 1
	hashingResult = 0;
	for (long unsigned int i = 0; i < strlen(key); i++)
	{
		hashingResult += key[i];
	}

	// version 2
	hashingResult = 0;
	int keyLength = strlen(key);
	for (int i = 0; i < keyLength; i++)
	{
		hashingResult += key[i];
	}

	// version 3
	hashingResult = 0;
	for (; *key != '\0'; key++)
	{
		hashingResult += *key;
	}

	return hashingResult % currCapacity;
}



bool Table::does_website_exist(const Website &aWebsite)
{
	/*
	Searches through a table element chain and finds out if a website exists
	within that chain or not depending upon the website topic and website address
	INPUT:
		aWebsite: A Website object from which only the topic and address is read
	OUTPUT:
		True if the website exists in the table, false otherwise
	*/
	int index = calculateIndex(aWebsite.get_topic());
	int flag1, flag2;
	bool ret_flag = false;

	Node *currhead = this->aTable[index];
	while (currhead)
	{
		flag1 = strcmp(aWebsite.get_topic(), currhead->data->get_topic());
		flag2 = strcmp(aWebsite.get_address(), currhead->data->get_address());
		if ((flag1 == 0) && (flag2 == 0))
		{
			ret_flag = true;
			break;
		}
		currhead = currhead->next;
	}
	return ret_flag;
}



bool Table::set_new_edits(const Website &aWebsite)
{
	/*
	For a website topic and address, edits the website review and rating
	INPUT:
		aWebsite: A website object
	OUTPUT:
		True if the modification was successfull, false otherwise
	*/
	int index = calculateIndex(aWebsite.get_topic());
	int flag1, flag2;
	bool ret_flag = false;

	Node *currhead = this->aTable[index];
	while (currhead)
	{
		flag1 = strcmp(aWebsite.get_topic(), currhead->data->get_topic());
		flag2 = strcmp(aWebsite.get_address(), currhead->data->get_address());
		if ((flag1 == 0) && (flag2 == 0))
		{
			currhead->data->set_review(aWebsite.get_review());
			currhead->data->set_rating(aWebsite.get_rating());
			ret_flag = true;
			break;
		}
		currhead = currhead->next;
	}
	return ret_flag;
}



void Table::monitor_performance()
{
	/*
	Helper function to assess the performance of a table.  Prints out the chain
	length of each element of the table
	*/
	unsigned int length = 0;
	Node *currhead;

	cout << endl;
	cout << endl;
	for (int i = 0; i < this->currCapacity; i++)
	{
		length = 0;
		currhead = this->aTable[i];
		while (currhead)
		{
			++length;
			currhead = currhead->next;
		}
		cout << "Chain length at position " << i << ": " << length << endl;
	}
}



unsigned int Table::remove_websites()
{
	/*
	Removes all websites with rating of 1 star
	INPUT:
		None
	OUTPUT:
		Number of websites removed
	*/
	unsigned int num_removed = 0;
	Node *prevhead, *currhead, *temp = nullptr;

	for (int i = 0; i < this->currCapacity; i++)
	{
		prevhead = nullptr;
		currhead = this->aTable[i];
		while (currhead)
		{
			if (currhead->data->get_rating() <= 1)
			{
				temp = currhead;
				if (!prevhead)
				{
					this->aTable[i] = currhead->next;
					currhead = this->aTable[i];
				}
				else
				{
					prevhead->next = currhead->next;
					currhead = currhead->next;
				}
				delete temp->data;
				delete temp;
				temp = nullptr;
				++num_removed;
				--size;
			}
			else
			{
				prevhead = currhead;
				currhead = currhead->next;
			}
		}
	}
	return num_removed;
}



const Table &Table::operator=(const Table &tableSrc)
{
	/*
	Overloaded operator =
	*/
	if (this == &tableSrc)
		return *this;
	if (this->aTable)
	{
		destroy();
	}
	size = tableSrc.size;
	currCapacity = tableSrc.currCapacity;
	aTable = new Node *[currCapacity];
	for (int i = 0; i < currCapacity; i++)
	{
		aTable[i] = nullptr;
		copyChain(tableSrc.aTable[i], this->aTable[i]);
	}
	return *this;
}



unsigned int Table::getSize() const
{
	/*
	Returns the total number of entries in the table
	*/
	return this->currCapacity;
}

bool Table::retrieve_data(char *topic_keyword, Website all_matches[], unsigned int &num_found)
{
	bool found_something = false;
	int index = calculateIndex(topic_keyword);
	Node *currhead;
	int decision_flag;

	currhead = this->aTable[index];
	while (currhead)
	{
		decision_flag = strcmp(topic_keyword, currhead->data->get_topic());
		if (decision_flag == 0)
		{
			all_matches[num_found] = *(currhead->data);
			++num_found;
			found_something = true;
		}
		currhead = currhead->next;
	}
	return found_something;
}



void Table::copyChain(Node *srcHead, Node *&destHead)
{
	/*
	Copy a chain from one head to another
	INPUT:
		srcHead: source head
		destHead: destination head
	OUTPUT:
		None
	*/
	if (srcHead)
	{
		destHead = new Node(*(srcHead->data));
		copyChain(srcHead->next, destHead->next);
	}
}



ostream &operator<<(ostream &out, const Table &srcTable)
{
	/*
	Overloaded ostream operator
	*/
	out << endl
		<< "Displaying all websites in the table ..." << endl;
	for (int i = 0; i < srcTable.currCapacity; i++)
	{
		if (srcTable.aTable[i])
		{
			out << endl;
			srcTable.displayChain(out, srcTable.aTable[i]);
			out << endl;
		}
	}
	return out;
}



void Table::displayChain(ostream &out, Node *currHead) const
{
	/*
	Helper function to output a chain with overloaded outstream operator
	*/
	if (currHead)
	{
		out << *(currHead->data) << endl;
		displayChain(out, currHead->next);
	}
}



void Table::loadFromFile(const char *fileName)
{
	/*
	Member function to load test cases from a file
	INPUT:
		filename: name of the file that contains the test data set
	OUTPUT:
		None
	*/
	ifstream fh;
	Website currWebsite;
	const int MAX_CHAR = 1024;
	char curr_topic[MAX_CHAR], curr_addr[MAX_CHAR];
	char curr_summary[MAX_CHAR], curr_review[MAX_CHAR];
	unsigned int curr_rating;
	char temp[MAX_CHAR];

	fh.open(fileName);
	if (!fh)
	{
		std::cout << "Fail to open " << fileName << " for reading." << std::endl;
		exit(1);
	}

	fh.getline(curr_topic, MAX_CHAR, '|');
	while (!fh.eof())
	{

		fh.getline(curr_addr, MAX_CHAR, '|');
		fh.getline(curr_summary, MAX_CHAR, '|');
		fh.getline(curr_review, MAX_CHAR, '|');
		fh.getline(temp, MAX_CHAR, '\n');
		curr_rating = atoi(temp);

		currWebsite.set_topic(curr_topic);
		currWebsite.set_address(curr_addr);
		currWebsite.set_summary(curr_summary);
		currWebsite.set_review(curr_review);
		currWebsite.set_rating(curr_rating);
		add(currWebsite);

		fh.getline(curr_topic, MAX_CHAR, '|');
	}
	fh.close();
}



void Table::saveToFile(const char *fileName) const
{
	/*
	Member function to output data into a file
	*/
	ofstream out;

	out.open(fileName);
	if (!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for (int i = 0; i < currCapacity; i++)
	{
		writeOutChain(out, aTable[i]);
	}
	out.close();
}



void Table::writeOutChain(ostream &out, Node *currHead) const
{
	/*
	Helper function to write out data into a file
	*/
	if (currHead)
	{
		out << currHead->data->get_topic() << '|' << currHead->data->get_address() << '|' << currHead->data->get_summary() << '|' << currHead->data->get_review() << '|' << currHead->data->get_rating() << endl;
		writeOutChain(out, currHead->next);
	}
}
