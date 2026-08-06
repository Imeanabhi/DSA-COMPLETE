#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Morris Preorder Traversal (Root -> Left -> Right)
    vector<int> morrisPreorder(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>preorder;
        while(curr!=nullptr)
        {
            if(curr->left == nullptr)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)
                {
                    prev = prev->right
                }
                if(prev->right == nullptr)
                {
                    preorder.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
};

// Helper function to print vectors
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Constructing the target binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;

    // Execute and display Morris Preorder Traversal
    cout << "Morris Preorder Result: ";
    vector<int> preorder = sol.morrisPreorder(root);
    printVector(preorder); // Output will be: 1 2 4 5 3

    // Clean up memory (optional but best practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}