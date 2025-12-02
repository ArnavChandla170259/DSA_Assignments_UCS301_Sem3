#include <iostream>
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

Node* insert(Node* node, int val) {
    if (node == NULL)
        return new Node(val);

    if (val < node->data)
        node->left = insert(node->left, val);

    else if (val > node->data)
        node->right = insert(node->right, val);

    return node;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return searchRecursive(root->right, key);

    return searchRecursive(root->left, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != NULL && root->data != key) {

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (root == NULL) return;

    if (root->data == key) {

        if (root->left != NULL) {
            Node* tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            pre = tmp;
        }

        if (root->right != NULL) {
            Node* tmp = root->right;
            while (tmp->left) tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    if (root->data > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 99);
    insert(root, 46);
    insert(root, 75);
    insert(root, 25);
    insert(root, 9);
    insert(root, 29);
    insert(root, 59);

    // Search
    if (searchRecursive(root, 25)) cout << "25 Found (Rec)\n";
    if (searchIterative(root, 25)) cout << "25 Found (Iter)\n";

    // Min Max
    cout << "Max: " << findMax(root)->data << "\n";
    cout << "Min: " << findMin(root)->data << "\n";

    // Predecessor Successor
    Node* pre = NULL;
    Node* suc = NULL;

    findPreSuc(root, pre, suc, 75);
    if (pre) cout << "Predecessor of 75: " << pre->data << "\n";
    if (suc) cout << "Successor of 75: " << suc->data << "\n";

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
