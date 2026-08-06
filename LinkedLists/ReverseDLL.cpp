#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;  
    Node* next;    
    Node* back; 
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head) {
        while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to reverse the doubly linked list in-place
Node* reverseDLL(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* curr = head;
    while(curr!=nullptr)
    {
        Node* nextNode = curr->next;
        curr->next = curr->back;
        curr->back = nextNode;

        head = curr;
        curr = nextNode;
    }
    return head;
}
int main() {
    vector<int> arr = {10, 20, 30, 40};
    Node* head = convertArr2DLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}
