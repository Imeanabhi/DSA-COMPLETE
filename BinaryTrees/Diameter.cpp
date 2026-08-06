
#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the
    // diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    // Function to calculate the height of
    // the tree and update the diameter
    int height(Node* node, int& diameter) {
        if(node == nullptr)return 0;
        int lh = height(node->left,diameter);
        int rh = height(node->right,diameter);
        diameter = max(diameter,lh+rh);
        return 1 + max(lh,rh);
    }
};


// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
                                