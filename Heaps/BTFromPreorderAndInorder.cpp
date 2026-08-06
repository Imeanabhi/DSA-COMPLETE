#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* build(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>inMap)
    {
        if(prestart>preend || instart>inend){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - instart;
        root->left = build(preorder,prestart+1,prestart+numsLeft,inorder,instart,inRoot-1,inMap);
        root->right = build(preorder,prestart+numsLeft+1,preend,inorder,inRoot+1,inend,inMap);
        return root;
    }
    // Function to build the binary tree from preorder and inorder
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;
        int n = inorder.size();
        for(int i = 0;i<n;i++)
        {
            inMap[inorder[i]] = i;
        }
        return build(preorder,0,n-1,inorder,0,n-1,inMap);
    }
};

// Inorder traversal to print tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
