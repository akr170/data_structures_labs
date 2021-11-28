/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 4
This module contains the code for the member functions of the class Binary_Seach_Tree
*/
#include "bst.h"



BinarySearchTree::BinarySearchTree() : root(nullptr), size(0)
{
	//constructor
}



BinarySearchTree::BinarySearchTree(const BinarySearchTree &aBinarySearchTree) : root(nullptr), size(0)
{
	// copy constructor
	*this = aBinarySearchTree;
}



BinarySearchTree::~BinarySearchTree()
{
	// destructor
	destroy(root);
}



void BinarySearchTree::destroy(Node *&currRoot)
{
	// destructor helper function
	if (currRoot)
	{
		destroy(currRoot->left);
		destroy(currRoot->right);
		delete currRoot->data;
		delete currRoot;
		currRoot = nullptr;
	}
}



void BinarySearchTree::insert(const Website &aWebsite)
{
	/*
	Adds data to the binary search tree based on user provided keyword
	INPUT:
		aWebsite: a website object
	OUTPUT:
		none
	*/
	insert(this->root, aWebsite);
	size++;
}



void BinarySearchTree::insert(Node *&currRoot, const Website &aWebsite)
{
	/*
	Private helper function to add data to a particular node in the BST
	INPUT:
		currRoot: memory address to a BST node
		aWebsite: a website object
	OUTPUT:
		None
	*/
	if (!currRoot)
	{
		currRoot = new Node(aWebsite);
	}
	else if (aWebsite < *(currRoot->data))
	{
		insert(currRoot->left, aWebsite);
	}
	else
	{
		insert(currRoot->right, aWebsite);
	}
}



const BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &tableSrc)
{
	/*
	Overloaded operator =
	*/
	if (this == &tableSrc)
		return *this;
	if (this->root)
	{
		destroy(this->root);
	}
	size = tableSrc.size;
	copy(tableSrc.root, this->root);
	return *this;
}



void BinarySearchTree::copy(Node *srcRoot, Node *&destRoot)
{
	/*
	Helper function to copy from a root BST node to a destination BST node
	INPUT:
		srcRoot: address to the source node
		destRoot: address to the destination node
	OUTPUT:
		None
	*/
	if (srcRoot)
	{
		destRoot = new Node(*(srcRoot->data));
		copy(srcRoot->left, destRoot->left);
		copy(srcRoot->right, destRoot->right);
	}
	else
	{
		destRoot = nullptr;
	}
}



ostream &operator<<(ostream &out, const BinarySearchTree &srcTable)
{
	/*
	Overloaded operator <<
	*/
	out << endl
		<< "Displaying the tree ..." << endl;
	srcTable.display(out, srcTable.root);
	return out;
}



void BinarySearchTree::display(ostream &out, Node *currRoot) const
{
	/*
	Member function to display the contents of the BST
	INPUT:
		out: variable to output information in the BST
		currRoot: pointer to a node in the BST
	OUTPUT:
		None
	*/
	// out << endl
	// 	<< "Pre-order showing the tree ..." << endl;
	// displayPreorder(out, currRoot);
	out << endl;
	out << "In-order showing the tree ..." << endl;
	displayInorder(out, currRoot);
	out << endl;
	// out << "Post-order showing the tree ..." << endl;
	// displayPostorder(out, currRoot);
}



void BinarySearchTree::displayPreorder(ostream &out, Node *currRoot) const
{
	/*
	Helper function to display the contents of the BST in pre-order
	*/
	if (currRoot)
	{
		out << *(currRoot->data) << endl;
		displayPreorder(out, currRoot->left);
		displayPreorder(out, currRoot->right);
	}
}



void BinarySearchTree::displayInorder(ostream &out, Node *currRoot) const
{
	/*
	Helper function to display the contents of the BST in order
	*/
	if (currRoot)
	{
		displayInorder(out, currRoot->left);
		out << *(currRoot->data) << endl;
		displayInorder(out, currRoot->right);
	}
}



void BinarySearchTree::displayPostorder(ostream &out, Node *currRoot) const
{
	/*
	Helper function to display the contents of the BST in post-order
	*/
	if (currRoot)
	{
		displayPostorder(out, currRoot->left);
		displayPostorder(out, currRoot->right);
		out << *(currRoot->data) << endl;
	}
}



void BinarySearchTree::loadFromFile(const char *fileName)
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
	char curr_topic[MAX_CHAR], curr_keyword[MAX_CHAR], curr_addr[MAX_CHAR];
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
		fh.getline(curr_keyword, MAX_CHAR, '|');
		fh.getline(curr_addr, MAX_CHAR, '|');
		fh.getline(curr_summary, MAX_CHAR, '|');
		fh.getline(curr_review, MAX_CHAR, '|');
		fh.getline(temp, MAX_CHAR, '\n');
		curr_rating = atoi(temp);

		currWebsite.set_topic(curr_topic);
		currWebsite.set_keyword(curr_keyword);
		currWebsite.set_address(curr_addr);
		currWebsite.set_summary(curr_summary);
		currWebsite.set_review(curr_review);
		currWebsite.set_rating(curr_rating);
		insert(currWebsite);

		fh.getline(curr_topic, MAX_CHAR, '|');
	}
	fh.close();
}



void BinarySearchTree::saveToFile(const char *fileName) const
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

	saveToFile(out, this->root);
	out.close();
}



void BinarySearchTree::saveToFile(ostream &out, Node *currRoot) const
{
	/*
	Helper function to write out data into a file
	*/
	if (currRoot)
	{
		out << currRoot->data->get_topic() << '|' << currRoot->data->get_keyword() << '|' << currRoot->data->get_address() << '|' << currRoot->data->get_summary() << '|' << currRoot->data->get_review() << '|' << currRoot->data->get_rating() << endl;
		saveToFile(out, currRoot->left);
		saveToFile(out, currRoot->right);
	}
}

bool BinarySearchTree::remove_by_topic(const char *key)
{
	/*
	Removes all website with topic that matches user provided topic
	INPUT:
		key: user provided topic
	OUTPUT:
		true if any removal happens, false otherwise
	*/
	return remove_by_topic(this->root, key);
}



bool BinarySearchTree::remove_by_topic(Node *&currRoot, const char *key)
{
	/*
	Helper function to remove websites by topic
	*/
	if (!currRoot)
	{
		return false;
	}
	else
	{
		bool ret = false;
		int temp = strcmp(key, currRoot->data->get_topic());
		if (temp == 0)
		{
			ret = ret || remove_by_topic(currRoot->right, key);
			// aWebsite = *(currRoot->data);
			deleteNode(currRoot);
			size--;
			ret = ret || true;
		}
		else if (temp < 0)
		{
			ret = ret || remove_by_topic(currRoot->left, key);
		}
		else
		{
			ret = ret || remove_by_topic(currRoot->right, key);
		}
		return ret;
	}
}




bool BinarySearchTree::remove_by_keyword(const char *key, Website &aWebsite)
{
	/*
	Takes in a user provided keyword and then removes a website with a keyword
	that matches user provided keyword.  The data for the website that gets removed
	is returned to the client program through a variabled passed by reference 
	INPUT:
		key: user provided keyword
		aWebsite: a variable that is passed by reference to return deleted user data
	OUTPUT:
		true if a data is deleted, false otherwise
	*/
	return remove_by_keyword(this->root, key, aWebsite);
}



bool BinarySearchTree::remove_by_keyword(Node *&currRoot, const char *key, Website &aWebsite)
{
	/*
	Helper function to remove a data by keyword
	*/
	if (!currRoot)
	{
		return false;
	}
	int temp = strcmp(key, currRoot->data->get_keyword());
	if (temp == 0)
	{
		aWebsite = *(currRoot->data);
		deleteNode(currRoot);
		size--;
		return true;
	}
	else if (temp < 0)
	{
		return remove_by_keyword(currRoot->left, key, aWebsite);
	}
	else
	{
		return remove_by_keyword(currRoot->right, key, aWebsite);
	}
}



void BinarySearchTree::deleteNode(Node *&target)
{
	/*
	Helper function to delete a node
	*/
	// target node is a leaf
	if (!target->left && !target->right)
	{
		delete target->data;
		delete target;
		target = nullptr;
	}
	// target node only has left child
	else if (!target->right)
	{
		Node *temp = target;
		target = target->left;
		delete temp->data;
		delete temp;
	}
	// target node only has right child
	else if (!target->left)
	{
		Node *temp = target;
		target = target->right;
		delete temp->data;
		delete temp;
	}
	// target node has two children
	else
	{
		// find the inorder successor of target node
		Node *prev = nullptr;
		Node *curr = target->right; // start with the right child
		if (!curr->left)			// the right child is the inorder successor
		{
			target->right = curr->right;
		}
		else
		{
			while (curr->left)
			{
				prev = curr;
				curr = curr->left; // then go all the way to the left
			}
			prev->left = curr->right;
		}
		delete target->data;
		target->data = curr->data;
		delete curr;
		return;
	}
}



unsigned int BinarySearchTree::getSize() const
{
	/*
	Returns number of data nodes stored in the binary search tree
	*/
	return size;
}



bool BinarySearchTree::retrieve(const char *key, Website &aWebsite)
{
	/*
	Member function to find data by user provided keyword and then return information
	to the client program using a variable passed by reference.
	INPUT:
		key: user provided keyword
		aWebsite: variable passed by reference to return retrieved data
	OUTPUT:
		true if retrieval successful, false otherwise
	*/
	return retrieve(this->root, key, aWebsite);
}



bool BinarySearchTree::retrieve(Node *&currRoot, const char *key, Website &aWebsite)
{
	/*
	Helper function to retrieve stored data by keyword
	*/
	if (!currRoot)
	{
		return false;
	}
	int temp = strcmp(key, currRoot->data->get_keyword());
	if (temp == 0)
	{
		aWebsite = *(currRoot->data);
		return true;
	}
	else if (temp < 0)
	{
		return retrieve(currRoot->left, key, aWebsite);
	}
	else
	{
		return retrieve(currRoot->right, key, aWebsite);
	}
}



void BinarySearchTree::monitor_performance()
{
	/*
	Member function to help with the monitoring of the binary search tree performance
	*/
	cout << "Total Number of items in the tree: " << size << endl;
	cout << "       Current height of the tree: " << height(this->root) << endl;
	cout << "Ideal height of a BST of " << size << " nodes: " << ceil(log2(double(size))) << endl;
}



unsigned int BinarySearchTree::height(Node *&root)
{
	/*
	helper function the calculated the height of the binary search tree
	*/
	// Recursively computing height of BST
	unsigned int max_height = 0;
	if (root)
	{
		max_height = height(root, 1);
	}
	return max_height;
}



unsigned int BinarySearchTree::height(Node *&root, unsigned int curr_height)
{
	/*
	helper function the calculated the height of the binary search tree
	*/
	// Recursively computing height of BST
	unsigned int max_height = curr_height;

	if (root->left)
		max_height = max(max_height, height(root->left, curr_height + 1));

	if (root->right)
		max_height = max(max_height, height(root->right, curr_height + 1));

	return max_height;
}
