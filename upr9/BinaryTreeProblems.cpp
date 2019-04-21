#include <utility> // std::swap
#include <cstddef> // NULL
#include <climits>

struct Node
{
    Node* left;
    Node* right;
    int val;
};

void reverseTree(Node* root)
{
    if (root == NULL) return;

    std::swap(root->left, root->right);
    reverseTree(root->left);
    reverseTree(root->right);
}

bool rec(Node* root, int a, int b)
{
    if (root == NULL) return true;

    if (root->val < a || root->val > b) return false;
    else return rec(root->left, a, root->val) &&
        rec(root->right, root->val, b);
}

bool isBinarySearchTree(Node* root)
{
    return rec(root, INT_MIN, INT_MAX);
}
