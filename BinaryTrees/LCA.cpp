#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // Result
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            return root;
        }
    }
};

int main() {
    // Construct a simple binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution solution;
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->data << endl;

    return 0;
}