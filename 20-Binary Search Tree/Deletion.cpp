#include <iostream>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert Node
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find Minimum Node
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete Node
Node* deleteNode(Node* root, int key) {

    // Tree is empty
    if (root == NULL)
        return NULL;

    // Search for the node
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Node Found
    else {

        // Case 1: Node has 0 children (Leaf Node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Node has only Right Child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Node has only Left Child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has 2 children
        else {
            // Find Inorder Successor
            Node* temp = findMin(root->right);

            // Replace current node's value
            root->data = temp->data;

            // Delete the Inorder Successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Create BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Before Deletion: ";
    inorder(root);

    int key;
    cout << "\nEnter node to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "After Deletion: ";
    inorder(root);

    return 0;
}