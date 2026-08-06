#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// --- Tree Node Definition ---
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// ==========================================
// 1. PREORDER TRAVERSAL (Root -> Left -> Right)
// ==========================================
void preorderRecursiveHelper(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    result.push_back(root->val);
    preorderRecursiveHelper(root->left, result);
    preorderRecursiveHelper(root->right, result);
}

std::vector<int> preorderRecursive(TreeNode* root) {
    std::vector<int> result;
    preorderRecursiveHelper(root, result);
    return result;
}

std::vector<int> preorderIterative(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) return result;

    std::stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        result.push_back(curr->val);
        if(curr->right)st.push(curr->right);
        if(curr->left)st.push(curr->left);
    }
    return result;
}

// ==========================================
// 2. INORDER TRAVERSAL (Left -> Root -> Right)
// ==========================================
void inorderRecursiveHelper(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    inorderRecursiveHelper(root->left, result);
    result.push_back(root->val);
    inorderRecursiveHelper(root->right, result);
}

std::vector<int> inorderRecursive(TreeNode* root) {
    std::vector<int> result;
    inorderRecursiveHelper(root, result);
    return result;
}

std::vector<int> inorderIterative(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> st;
    TreeNode* curr = root;
while (curr != nullptr) {
    st.push(curr);
    curr = curr->left;
}

while (!st.empty()) {
    curr = st.top();
    st.pop();
    
    result.push_back(curr->val);
    
    // Step right and immediately push its left line
    curr = curr->right;
    while (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
    }
}
return result;
}

// ==========================================
// 3. POSTORDER TRAVERSAL (Left -> Right -> Root)
// ==========================================
void postorderRecursiveHelper(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    postorderRecursiveHelper(root->left, result);
    postorderRecursiveHelper(root->right, result);
    result.push_back(root->val);
}

std::vector<int> postorderRecursive(TreeNode* root) {
    std::vector<int> result;
    postorderRecursiveHelper(root, result);
    return result;
}

std::vector<int> postorderIterative(TreeNode* root) {
   vector<int>ans;
   stack<TreeNode*>st1;
   stack<TreeNode*>st2;
    if(root == NULL){
        return ans;
    }
   st1.push(root);
   while(!st1.empty()){
    root = st1.top();
    st1.pop();
    st2.push(root);
    if(root->left!=nullptr)st1.push(root->left);
    if(root->right!=nullptr)st2.push(root->right);
   }
   while(!st2.empty())
   {
    ans.push_back(st2.top()->val);
    st2.pop();
   }
   return ans;
}

// --- Main execution ---
int main() {
    /* Constructing the following sample binary tree:
                    1
                   / \
                  2   3
                 / \
                4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "--- PREORDER TRAVERSAL ---\n";
    printVector("Recursive Preorder", preorderRecursive(root));
    printVector("Iterative Preorder", preorderIterative(root));
    std::cout << "\n";

    std::cout << "--- INORDER TRAVERSAL ---\n";
    printVector("Recursive Inorder ", inorderRecursive(root));
    printVector("Iterative Inorder ", inorderIterative(root));
    std::cout << "\n";

    std::cout << "--- POSTORDER TRAVERSAL ---\n";
    printVector("Recursive Postorder", postorderRecursive(root));
    printVector("Iterative Postorder", postorderIterative(root));
    std::cout << "\n";

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}