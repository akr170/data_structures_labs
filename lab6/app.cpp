#include <iostream>
#include "table.h"

using namespace std;

#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
	node *head{nullptr};

	/* Builds a circular linked list with a random number of nodes
	 *containing randomly-chosen numbers.
	 */
	build(head);

	display(head);

	// PUT YOUR CODE HERE to call the functions assigned,
	// and print out the results. For example,
	//
	//    cout << "iterative sum: " << sum(head) << endl;
	//
	// The code for your functions should be in clist.cpp.

	cout << endl
		 << endl;
	cout << "recursive count: " << count(head) << endl;
	cout << "recursive sum: " << sum(head) << endl;
	cout << "recursive height: " << height(head) << endl;

	// When called the 2nd time, this also prints the total
	// of the numbers in the nodes.
	display(head);

	// int nNodesFreed{0};
	// node *n{head};
	// node *temp;

	// while (n != head || !nNodesFreed)
	// {
	// 	temp = n->left;
	// 	delete n;
	// 	temp = n->right;
	// 	delete n;
	// 	n = temp;
	// 	nNodesFreed++;
	// }
	// cout << "# nodes freed: " << nNodesFreed << endl;

	destroy(head);

	return 0;
}
