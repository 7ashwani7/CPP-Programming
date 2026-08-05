#include <iostream>
using namespace std;

// Node structure
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:

    // Insert
    Node* insert(Node* root, int val){
        if(root == NULL) return new Node(val);
        if(val < root->data) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    // Search
    Node* search(Node* root, int key){
        if(root == NULL || root->data == key) return root;
        if(key < root->data) return search(root->left, key);
        return search(root->right, key);
    }

    // Inorder Traversal
    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Preorder Traversal
    void preorder(Node* root){
        if(root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Postorder Traversal
    void postorder(Node* root){
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Find Minimum
    Node* findMin(Node* root){
        while(root && root->left) root = root->left;
        return root;
    }

    // Find Maximum
    Node* findMax(Node* root){
        while(root && root->right) root = root->right;
        return root;
    }
};

int main() {
    BST tree;
    Node* root = NULL;
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "Inorder: ";
    tree.inorder(root);

    cout << "\nPreorder: ";
    tree.preorder(root);

    cout << "\nPostorder: ";
    tree.postorder(root);

    Node* found = tree.search(root, 40);

    if(found) cout << "\n40 Found";
    else cout << "\n40 Not Found";

    cout << "\nMinimum: " << tree.findMin(root)->data;
    cout << "\nMaximum: " << tree.findMax(root)->data;

    return 0;
}