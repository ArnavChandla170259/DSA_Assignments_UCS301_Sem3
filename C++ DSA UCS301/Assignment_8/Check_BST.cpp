#include <iostream>
#include <climits>
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

bool isBST(Node* node, int min, int max) {
    if (node == NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

    return isBST(node->left, min, node->data - 1) &&
           isBST(node->right, node->data + 1, max);
}

int main() {
    Node* root = new Node(9);

    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "Is BST";
    else
        cout << "Not a BST";

    cout << "\n";

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
