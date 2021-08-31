//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*head = nullptr;;
// Homework 4
void push(int x)
{
    Node *stackNode;
    stackNode = new Node;
    if(stackNode == nullptr) cout<<"Stack full"<<endl;
    else
    {
        stackNode->data = x;
        stackNode->next = head;
        head = stackNode;
    }
}

int pop()
{
    Node *deleteNode;
    int x;
    if(head == NULL) cout<<"Stack empty"<<endl;
    else
    {
        deleteNode = head;
        head = head->next;
        x = deleteNode->data;
    }
    return x;
}
void Display()
{
    Node* curr;
    curr = head;
    while(curr != nullptr)
    {
        cout<<curr->data<<' ';
        curr = curr->next;
    }
    cout<<endl;
}
int main()
{
    push(1);
    push(2);
    push(3);
    Display();
    cout<<pop()<<endl;
}
