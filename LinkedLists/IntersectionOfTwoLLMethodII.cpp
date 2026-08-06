#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB == nullptr) return nullptr;
        ListNode* curr = headA;
        while(curr!=nullptr)
        {
            ListNode* currB = headB;
            while(currB!=nullptr)
            {
                if(curr == currB) return curr;
                currB = currB->next;
            }
            curr = curr->next;
        }
        return nullptr;
    }
};
int main() {
    ListNode* intersectNode = new ListNode(8);
    intersectNode->next = new ListNode(4);
    intersectNode->next->next = new ListNode(5);
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersectNode; // Hooking up the intersection
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersectNode; // Hooking up the intersection
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    if (intersection != nullptr) {
        cout << "Intersected at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    delete headA->next;
    delete headA;
    delete headB->next->next;
    delete headB->next;
    delete headB;
    delete intersectNode->next->next;
    delete intersectNode->next;
    delete intersectNode;
    return 0;
}