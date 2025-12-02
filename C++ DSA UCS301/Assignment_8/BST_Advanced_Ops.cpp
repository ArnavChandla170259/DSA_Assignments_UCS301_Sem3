#include <iostream>
#include <algorithm>
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

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* node) {
    if (node == NULL)
        return 0;

    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth) return (lDepth + 1);
        else return (rDepth + 1);
    }
}

int minDepth(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = NULL;

    insert(root, 99);
    insert(root, 46);
    insert(root, 75);
    insert(root, 25);
    insert(root, 9);
    insert(root, 29);
    insert(root, 59);

    cout << "Inorder before delete: ";
    inOrder(root);
    cout << "\n";

    root = deleteNode(root, 9);
    cout << "Inorder after delete 9: ";
    inOrder(root);
    cout << "\n";

    cout << "Max Depth: " << maxDepth(root) << "\n";
    cout << "Min Depth: " << minDepth(root) << "\n";

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
