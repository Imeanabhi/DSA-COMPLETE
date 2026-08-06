#include <bits/stdc++.h>
using namespace std;

// Tree Node Definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Function to find max path sum in the tree
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    // Helper function for recursive DFS
    int dfs(TreeNode* node, int &maxSum) {
        if(node == nullptr) return 0;
        int leftsum = max(0,dfs(node->left,maxSum));
        int rightsum = max(0,dfs(node->right,maxSum));
        maxSum = max(maxSum,leftsum + rightsum + node->val);
        return max(leftsum,rightsum) + node->val;
    }
};

// Driver Code
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root) << endl;

    return 0;
}
