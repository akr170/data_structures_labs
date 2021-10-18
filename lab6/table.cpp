// This file contains the code for table
#include "table.h"

int count(node *root)
{
    // Recursively computing total number of nodes in BST
    int counter = 1;

    if (root->left)
        counter += count(root->left);

    if (root->right)
        counter += count(root->right);

    return counter;
}

int sum(node *root)
{
    // Recursively computing sum of data stored in BST
    int totalsum = root->data;

    if (root->left)
        totalsum += sum(root->left);

    if (root->right)
        totalsum += sum(root->right);

    return totalsum;
}

int height(node *root)
{
    // Recursively computing height of BST
    int max_height = height(root, 0);
    return max_height;
}

int height(node *root, int curr_height)
{
    // Recursively computing height of BST
    int max_height = curr_height;

    if (root->left)
        max_height = max(max_height, height(root->left, curr_height + 1));

    if (root->right)
        max_height = max(max_height, height(root->right, curr_height + 1));

    return max_height;
}
