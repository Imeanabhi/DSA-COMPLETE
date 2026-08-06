#include <bits/stdc++.h>
using namespace std;

// Structure to represent a binary tree node
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Pointer to left child
    TreeNode* right;        // Pointer to right child
    // Constructor to initialize node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform zigzag (spiral) level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>level(size);
            for(int i = 0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int index = (leftToRight) ? i : size - i - 1;
                level[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        return result;
    }
};

int main() {
    // Create binary tree:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Create Solution object
    Solution sol;

    // Get zigzag traversal result
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    // Print result in desired format
    cout << "[";
    for (auto &level : ans) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i != level.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
