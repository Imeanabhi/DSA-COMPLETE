#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Definition for Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    vector<pair<int, int>> findPairsWithSum(Node* head, int target) {
        vector<pair<int, int>> result;
        if (head == nullptr || head->next == nullptr) return result;

        // Step 1: Initialize the left pointer at the head (smallest element)
        Node* left = head;

        // Step 2: Move the right pointer to the end of the list (largest element)
        Node* right = head;
        while (right->next != nullptr) {
            right = right->next;
        }

        // Step 3: Use Two-Pointer approach to find matching pairs
        // The loop terminates when pointers meet (left == right) or cross (right->next == left)
        while (left != right && right->next != left) {
            int current_sum = left->data + right->data;

            if (current_sum == target) {
                result.push_back({left->data, right->data});
                left = left->next;   // Advance left pointer to a larger value
                right = right->prev; // Retract right pointer to a smaller value
            } 
            else if (current_sum < target) {
                left = left->next;   // Sum is too small, move to a larger value
            } 
            else {
                right = right->prev; // Sum is too large, move to a smaller value
            }
        }

        return result;
    }
};

// --- DRIVER UTILITY FUNCTIONS ---

// Helper function to create a DLL from a vector
Node* createDLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* curr = head;
    
    for (size_t i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

// Helper function to print a DLL forward
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " <=> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

// Helper function to safely deallocate DLL memory
void freeList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

// Main Execution Driver
int main() {
    // Creating a sorted doubly linked list: 1 <=> 2 <=> 4 <=> 5 <=> 6 <=> 8 <=> 9
    vector<int> values = {1, 2, 4, 5, 6, 8, 9};
    Node* head = createDLL(values);

    cout << "Initial Doubly Linked List:" << endl;
    printList(head);
    cout << "-----------------------------------------------" << endl;

    int targetSum = 7;
    cout << "Searching for pairs that sum up to: " << targetSum << endl;

    Solution sol;
    vector<pair<int, int>> pairs = sol.findPairsWithSum(head, targetSum);

    // Print out the results
    if (pairs.empty()) {
        cout << "No pairs found with the given sum." << endl;
    } else {
        cout << "Pairs found:" << endl;
        for (const auto& p : pairs) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }

    // Clean up memory
    freeList(head);

    return 0;
}