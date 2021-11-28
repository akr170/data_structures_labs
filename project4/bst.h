/*
	  Name: 	Ashish Kumar
Student ID: 	G04065243
	Course: 	CS260 - Data Structures - CRN 42168
Assignment: 	Project 4
*/
// Header file for Binary Search Tree class
#ifndef BST_H
#define BST_H
#include "website.h"
#include <fstream>
#include <cmath>

class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &aBinarySearchTree);
	~BinarySearchTree();

	void insert(const Website &aStudent);
	bool remove_by_topic(const char *key);
	bool remove_by_keyword(const char *key, Website &aStudent);
	bool retrieve(const char *key, Website &aWebsite);
	void monitor_performance();
	unsigned int getSize() const;

	const BinarySearchTree &operator=(const BinarySearchTree &aBinarySearchTree);
	friend ostream &operator<<(ostream &out, const BinarySearchTree &aBinarySearchTree);

	void loadFromFile(const char *fileName);
	void saveToFile(const char *fileName) const;

private:
	struct Node
	{
		Node(const Website &aStudent)
		{
			data = new Website(aStudent);
			left = right = nullptr;
		};

		Website *data;
		Node *left;
		Node *right;
	};

	Node *root;
	unsigned int size;

	void insert(Node *&currRoot, const Website &aStudent);
	bool remove(Node *&currRoot, const char *key, Website &aStudent);
	void deleteNode(Node *&target);
	void destroy(Node *&currRoot);
	void copy(Node *srcRoot, Node *&destRoot);
	void display(ostream &out, Node *currRoot) const;
	void displayPreorder(ostream &out, Node *currRoot) const;
	void displayInorder(ostream &out, Node *currRoot) const;
	void displayPostorder(ostream &out, Node *currRoot) const;
	void saveToFile(ostream &out, Node *currRoot) const;
	bool remove_by_topic(Node *&currRoot, const char *key);
	bool remove_by_keyword(Node *&currRoot, const char *key, Website &aWebsite);
	bool retrieve(Node *&currRoot, const char *key, Website &aWebsite);
	unsigned int height(Node *&root);
	unsigned int height(Node *&root, unsigned int curr_height);
};

#endif
