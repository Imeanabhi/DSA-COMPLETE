#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {} // Fixed: changed data(val) to value(val)
};

// Class containing the logic for top view
class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(Node* root) {
        vector<int> ans;
        if(root == nullptr)
        {
            return ans;
        }
        queue<pair<Node*, int>> q;
        map<int, int> st; // Your map variable is named 'st'
        
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                    st[level] = node->value;    
                if(node->left)
                {
                    q.push({node->left, level - 1});
                }
                if(node->right){
                    q.push({node->right, level + 1});
                }
            }
        }
        
        // Fixed: Changed 'map' to 'st'
        for (auto it : st) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

// Driver code
int main() {
    // Create the sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create a Solution object
    Solution solution;

    // Get the top view
    vector<int> result = solution.topView(root);

    // Print the top view traversal
    cout << "Top View Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    return 0;
}