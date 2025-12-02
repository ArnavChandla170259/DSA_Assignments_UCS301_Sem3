/*
* Approach:
* This program uses Floyd's Cycle-Finding Algorithm, also known as the
* "tortoise and hare" algorithm.
* 1. Two pointers, 'slow' and 'fast', are initialized to the 'head'.
* 2. The list is traversed in a 'while' loop.
* 3. In each iteration:
* - 'slow' moves one step forward (slow = slow->next).
* - 'fast' moves two steps forward (fast = fast->next->next).
* 4. If the list is linear (not circular), 'fast' or 'fast->next' will
* eventually become NULL, and the loop will terminate, returning 'false'.
* 5. If the list is circular, the 'fast' pointer will eventually "lap"
* the 'slow' pointer. The condition (slow == fast) will become true,
* at which point the function returns 'true'.
*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

bool isCirc(Node *head)
{
    if
    {
        (head == NULL)
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while
    {
        (fast != NULL && fast->next != NULL)
        slow = slow->next;
        fast = fast->next->next;

        if
        {
            (slow == fast)
            return true;
        }
    }

    return false;
}

int main()
{
    Node *n1 = new Node{2, NULL};
    Node *n2 = new Node{4, NULL};
    Node *n3 = new Node{6, NULL};
    Node *n4 = new Node{7, NULL};
    Node *n5 = new Node{5, NULL};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;

    cout << "Input List 1 (2->4->6->7->5->(back to 6))" << endl;
    cout << "Output: " << (isCirc(n1) ? "True" : "False") << endl;

    Node *n6 = new Node{1, NULL};
    Node *n7 = new Node{2, NULL};
    Node *n8 = new Node{3, NULL};
    n6->next = n7;
    n7->next = n8;

    cout << "\nInput List 2 (1->2->3->NULL)" << endl;
    cout << "Output: " << (isCirc(n6) ? "True" : "False") << endl;

    return 0;
}
/* Name - Arnav Chandla
 * Roll No. - 1024170259 */
