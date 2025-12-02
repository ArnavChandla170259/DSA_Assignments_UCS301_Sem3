#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool hasLoop(Node* head) {
    unordered_set<Node*> s;

    while (head != NULL) {

        // If this node is already in set, there is a loop
        if (s.find(head) != s.end())
            return true;

        s.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Create loop: 4 -> 2
    head->next->next->next->next = head->next;

    if (hasLoop(head))
        cout << "true";
    else
        cout << "false";

    cout << "\n";
    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
