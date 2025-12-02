#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkDupUtil(Node* root, unordered_set<int>& s) {
    if (root == NULL)
        return false;

    if (s.find(root->data) != s.end())
        return true;

    s.insert(root->data);

    return checkDupUtil(root->left, s) || checkDupUtil(root->right, s);
}

bool hasDuplicates(Node* root) {
    unordered_set<int> s;
    return checkDupUtil(root, s);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(2); // Duplicate 2

    if (hasDuplicates(root))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    cout << "\n";
    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
