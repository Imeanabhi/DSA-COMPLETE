#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// ==========================================
// 1. Implement Stack using Arrays
// ==========================================
class ArrayStack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    ArrayStack(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;
        arr[topIndex] = x;
    }

    int pop() {
        if (isEmpty()) return -1;
        return arr[topIndex--];
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

// ==========================================
// 2. Implement Queue using Arrays
// ==========================================
class ArrayQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    ArrayQueue(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    void push(int x) {
        if (count == capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rearIndex] = x;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// ==========================================
// 3. Implement Stack using Queue
// ==========================================
class QueueStack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (isEmpty()) return -1;
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};

// ==========================================
// 4. Implement Queue using Stack
// ==========================================
class StackQueue {
private:
    stack<int> input;
    stack<int> output;

    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (isEmpty()) return -1;
        transfer();
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        transfer();
        return output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

// Node structure shared by Linked List implementations
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ==========================================
// 5. Implement Stack using Linked List
// ==========================================
class LinkedListStack {
private:
    Node* topNode;
    int count;

public:
    LinkedListStack() : topNode(nullptr), count(0) {}

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* temp = topNode;
        int val = temp->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return val;
    }

    int top() {
        if (isEmpty()) return -1;
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }
};

// ==========================================
// 6. Implement Queue using Linked List
// ==========================================
class LinkedListQueue {
private:
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    LinkedListQueue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    ~LinkedListQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* temp = frontNode;
        int val = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    int size() {
        return count;
    }
};

// ==========================================
// Driver Code
// ==========================================
int main() {
    cout << "--- 1. Stack using Array ---" << endl;
    ArrayStack ast;
    ast.push(10);
    ast.push(20);
    cout << "Top: " << ast.top() << endl;   // 20
    cout << "Popped: " << ast.pop() << endl; // 20
    cout << "Top: " << ast.top() << endl;   // 10
    cout << endl;

    cout << "--- 2. Queue using Array ---" << endl;
    ArrayQueue aq;
    aq.push(10);
    aq.push(20);
    cout << "Front: " << aq.peek() << endl;  // 10
    cout << "Popped: " << aq.pop() << endl;  // 10
    cout << "Front: " << aq.peek() << endl;  // 20
    cout << endl;

    cout << "--- 3. Stack using Queue ---" << endl;
    QueueStack qs;
    qs.push(1);
    qs.push(2);
    cout << "Top: " << qs.top() << endl;   // 2
    cout << "Popped: " << qs.pop() << endl; // 2
    cout << "Top: " << qs.top() << endl;   // 1
    cout << endl;

    cout << "--- 4. Queue using Stack ---" << endl;
    StackQueue sq;
    sq.push(100);
    sq.push(200);
    cout << "Front: " << sq.peek() << endl;  // 100
    cout << "Popped: " << sq.pop() << endl;  // 100
    cout << "Front: " << sq.peek() << endl;  // 200
    cout << endl;

    cout << "--- 5. Stack using Linked List ---" << endl;
    LinkedListStack listStack;
    listStack.push(5);
    listStack.push(15);
    cout << "Top: " << listStack.top() << endl;   // 15
    cout << "Popped: " << listStack.pop() << endl; // 15
    cout << "Top: " << listStack.top() << endl;   // 5
    cout << endl;

    cout << "--- 6. Queue using Linked List ---" << endl;
    LinkedListQueue listQueue;
    listQueue.push(50);
    listQueue.push(60);
    cout << "Front: " << listQueue.peek() << endl;  // 50
    cout << "Popped: " << listQueue.pop() << endl;  // 50
    cout << "Front: " << listQueue.peek() << endl;  // 60
    cout << endl;

    return 0;
}