#include <iostream>
#include <climits>
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

Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == INT_MIN) return NULL;

    Node* root = new Node(arr[i]);

    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}
void display(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";

    display(root->left);
    display(root->right);
}

int main() {
    int arr[] = {1,2,3,4,INT_MIN,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = buildTree(arr, n, 0);
    display(root);

    return 0;
}