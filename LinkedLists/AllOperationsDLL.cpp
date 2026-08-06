#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*back;
    public:
Node(int data1)
{
    data=data1;
}
public:
Node(int data1,Node* next1, Node* back1)
{
    data=data1;
    next=next1;
    back=back1;
}
};
/*
void printLL(Node* head)
{

    while(head!=NULL)
    {
        cout<<head->data<<"--> ";
    head=head->next;
}
cout<<"null"<<endl;
}
*/

void printLL(Node* head)
{
    Node* curr=head;
    for(;curr!=NULL;curr=curr->next)
    {
        cout<<curr->data<<"-->";
    }
    cout<<"null"<<endl;
}


Node* convertarr2DLL(vector<int> arr)
{
    Node*head=new Node(arr[0]);
    Node*prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node*temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
return head;
}
//Insert Head
Node* InsertAtHead(Node* head,int val)
{
    Node*Newnode=new Node(val);
    if(head==NULL)
    {
        return Newnode;
    }
Newnode->next=head;
head->back=Newnode;
Newnode->back=nullptr;
head=Newnode;
return head;
}


//Delete head
Node* Deletehead(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        
        return NULL;
    }
    Node*prev=head;
    head=head->next;
    prev->next=nullptr;
    head->back=nullptr;
    delete prev;
    return head;
}
Node* InsertAtTail(Node * head,int val)
{
    Node* Newnode=new Node(val);
    if(head==NULL)
    {
        return Newnode;
    }
Node*tail=head;
while(tail->next!=NULL)
{
    tail=tail->next;
}
tail->next=Newnode;
Newnode->back=tail;
Newnode->next=nullptr;
return head;
}
Node * DeleteTail(Node* head)
{
    if (head == nullptr || head->next == nullptr){
        return NULL;
    }
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
Node*Newtail=tail->back;
Newtail->next=nullptr;
tail->back=nullptr;
delete tail;
return head;
}
int main()
{
    vector<int>arr={1,2,4,5};
    Node*head=convertarr2DLL(arr);
    printLL(head);
    head=Deletehead(head);
cout<<"after deleting the head new list is :"<<endl;
    printLL(head);
head=DeleteTail(head);
    cout<<"after deleting the tail new list is :"<<endl;
printLL(head);
head=InsertAtHead(head,1);
    cout<<"after inserting the head new list is :"<<endl;
printLL(head);
head=InsertAtTail(head,5);
    cout<<"after inserting the tail new list is :"<<endl;
printLL(head);
    return 0;
}