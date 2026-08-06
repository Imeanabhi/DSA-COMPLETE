#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int val;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isLeaf(Node* node)
    {
        return !node->left && !node->right;
    }
    void addLeftBoundary(Node* root,vector<int>&result)
    {
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                result.push_back(curr->val);
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    void addLeaves(Node* node,vector<int>&result)
    {
        if(isLeaf(node))
        {
            result.push_back(node->val);
            return;
        }
        if(node->left)
        {
            addLeaves(node->left,result);
        }
        if(node->right)
        {
            addLeaves(node->right,result);
        }
    }

    void addRightBoundary(Node* node,vector<int>&result)
    {
        Node* curr = node->right;
        vector<int>temp;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                temp.push_back(curr->val);
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        for(int i = 0;i<temp.size();i++)
        {
            result.push_back(temp[temp.size()-i-1]);
        }
    }
    vector<int> printBoundary(Node* root) {
        vector<int>result;
        if(!root)return result;
        if (!isLeaf(root)) {
            result.push_back(root->val);
        }
        addLeftBoundary(root,result);
        addLeaves(root,result);
        addRightBoundary(root,result);
        return result;
    }
};

// Helper function to
// print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating the binary tree from the image
Node* root = new Node(1);

// Left subtree
root->left = new Node(2);
root->left->left = new Node(3);
root->left->left->right = new Node(4);
root->left->left->right->left = new Node(5);
root->left->left->right->right = new Node(6);
root->left->left->right->right->left = new Node(12);

// Right subtree
root->right = new Node(7);
root->right->right = new Node(8);
root->right->right->left = new Node(9);
root->right->right->left->left = new Node(10);
root->right->right->left->right = new Node(11);
    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}