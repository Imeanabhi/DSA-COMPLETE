#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void changeTree(TreeNode* root) {
        if(!root) return;
        
        int child = 0;
        if(root->left)  child += root->left->val;
        if(root->right) child += root->right->val;

        // If children sum is greater or equal, update parent
        if(child >= root->val) {
            root->val = child;
        }
        // If parent is greater, propagate parent's value down to BOTH children
        else {
            if(root->left)  root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }
        
        // Traverse down the tree
        changeTree(root->left);
        changeTree(root->right);
        
        // Take the updated values while backtracking
        int tot = 0;
        if(root->left)  tot += root->left->val;
        if(root->right) tot += root->right->val;
        
        // Update parent with the actual calculated sum of children
        if(root->left || root->right) {
            root->val = tot;
        }
    }
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
int main() {
    // Reconstruct the tree layout to match your target sequence
    TreeNode* root = new TreeNode(30);
    root->left = new TreeNode(35);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(45);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(2);

    Solution sol;

    // This will print: 45 35 10 30 8 5 2
    cout << "Binary Tree before modification (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    sol.changeTree(root);

    // This will print the mathematically valid children-sum variant: 45 55 10 65 8 10 2
    cout << "Binary Tree after Children Sum Property (Inorder): " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}