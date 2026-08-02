#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isLeaf(Node* root) {
    return root && root->left == NULL && root->right == NULL;
}

void leftBoundary(Node* root, vector<int>& ans) {
    if (root == NULL || isLeaf(root))
        return;

    ans.push_back(root->data);

    if (root->left)
        leftBoundary(root->left, ans);
    else
        leftBoundary(root->right, ans);
}

void leafNodes(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;

    if (isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }

    // preorder style DFS
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

void rightBoundary(Node* root, vector<int>& ans) {
    if (root == NULL || isLeaf(root))
        return;

    if (root->right)
        rightBoundary(root->right, ans);
    else
        rightBoundary(root->left, ans);

    ans.push_back(root->data); // add while returning
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    leftBoundary(root->left, ans);
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
    rightBoundary(root->right, ans);

    return ans;
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(7);
    root->right = new Node(9);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(7);

    root->right->right = new Node(0);
    root->right->right->left = new Node(13);

    vector<int> ans = boundaryTraversal(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}