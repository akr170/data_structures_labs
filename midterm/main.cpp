#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << endl;
    cout << endl;
    cout << "Recursive sum of even numbers in the list: " << sumEven(head) << endl;
    cout << endl;
    cout << endl;
    cout << "Num of elements tagged in list: " << tagEven(head) << endl;

    display(head);
    destroy(head);    
    return 0;
}
