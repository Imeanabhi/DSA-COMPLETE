#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // Step 1: Map each node to its parent and find the target node pointer
    TreeNode* mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int target) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* targetNode = nullptr;

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->val == target) {
                targetNode = current;
            }

            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }

public:
    int timeToBurnTree(TreeNode* root, int target) {
        if (!root) return 0;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* targetNode = mapParents(root, parentMap, target);
        if (!targetNode) return 0; 

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(targetNode);
        visited.insert(targetNode);
        int timeElapsed = 0;

        while (!q.empty()) {
            int size = q.size();
            bool fireSpreaded = false;
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && visited.find(current->left) == visited.end()) {
                    fireSpreaded = true;
                    visited.insert(current->left);
                    q.push(current->left);
                }
                if (current->right && visited.find(current->right) == visited.end()) {
                    fireSpreaded = true;
                    visited.insert(current->right);
                    q.push(current->right);
                }
                if (parentMap.find(current) != parentMap.end() && visited.find(parentMap[current]) == visited.end()) {
                    fireSpreaded = true;
                    visited.insert(parentMap[current]);
                    q.push(parentMap[current]);
                }
            }

            if (fireSpreaded) {
                timeElapsed++;
            }
        }

        return timeElapsed;
    }
};
int main() {
    // 1. Construct a simple tree for testing:
    //        1
    //       / \
    //      2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution solver;
    int targetValue = 2;
    
    // 2. Call the function
    int timeTaken = solver.timeToBurnTree(root, targetValue);
    
    std::cout << "Minimum time to burn the tree: " << timeTaken << " seconds." << std::endl;
    
    return 0;
}