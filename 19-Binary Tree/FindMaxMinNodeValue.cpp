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
int maxNodeValue(Node* root) {
    if (root == NULL) return INT_MIN;

    int leftMax = maxNodeValue(root->left);
    int rightMax = maxNodeValue(root->right);

    return max(root->data, max(leftMax, rightMax));
}
int minNodeValue(Node* root) {
    if (root == NULL) return INT_MAX;

    int leftMin = minNodeValue(root->left);
    int rightMin = minNodeValue(root->right);

    return min(root->data, min(leftMin, rightMin));
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Maximum node value: " << maxNodeValue(root) << endl;
    cout << "Minimum node value: " << minNodeValue(root) << endl;

    return 0;
}