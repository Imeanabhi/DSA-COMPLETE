#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor to initialize node value
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    // Function to reverse a linked list iteratively
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr)
        {
            ListNode* NextNode = curr->next;
            curr->next = prev;
            prev = curr;
            NextNode = curr;
        }
        return prev;
    }
};
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution sol;
    ListNode* newHead = sol.reverseList(head);
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
