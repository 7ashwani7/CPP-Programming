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

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Morris Inorder Traversal
void morrisInorder(Node* root) {

    Node* curr = root;

    while (curr != NULL) {

        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {

            Node* pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

// Morris Preorder Traversal
void morrisPreorder(Node* root) {

    Node* curr = root;

    while (curr != NULL) {

        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {

            Node* pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL) {
                cout << curr->data << " ";
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

// Reverse Right Pointers
void reverse(Node* start, Node* end) {

    if (start == end)
        return;

    Node *x = start, *y = start->right, *z;

    while (true) {
        z = y->right;
        y->right = x;
        x = y;
        y = z;

        if (x == end)
            break;
    }
}

// Print Reverse Path
void printReverse(Node* start, Node* end) {

    reverse(start, end);

    Node* p = end;

    while (true) {

        cout << p->data << " ";

        if (p == start)
            break;

        p = p->right;
    }

    reverse(end, start);
}

// Morris Postorder Traversal
void morrisPostorder(Node* root) {

    Node dummy(0);
    dummy.left = root;

    Node* curr = &dummy;

    while (curr != NULL) {

        if (curr->left == NULL) {
            curr = curr->right;
        }
        else {

            Node* pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                printReverse(curr->left, pred);
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main() {

    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Morris Inorder : ";
    morrisInorder(root);

    cout << "\nMorris Preorder: ";
    morrisPreorder(root);

    cout << "\nMorris Postorder: ";
    morrisPostorder(root);

    return 0;
}