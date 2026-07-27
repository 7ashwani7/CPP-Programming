#include <iostream>
using namespace std;

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
// Height in terms of edges
int height(Node* root) {
    if (root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}
// Number of levels
int levels(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(levels(root->left), levels(root->right));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    //root->right->right = new Node(7);

    cout << "Height of Binary Tree (Edges): "<< height(root) << endl;
    cout << "Number of Levels: "<< levels(root) << endl;

    return 0;
}