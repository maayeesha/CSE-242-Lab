//Maayeesha Farzana
//Id: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node* prev;
Node* next;
};

Node* constructDoubly()
{
    Node* head=nullptr,*prev_node;
    while(1)
    {
        int input;
        cin>>input;
        if(input == -1) break;
        Node* curr = new Node;
        curr->data = input;
        curr->prev = prev_node;
        curr->next = nullptr;

        if(head == nullptr) head = curr;
        else
        {
            prev_node->next = curr;
        }
        prev_node = curr;
    }
    return head;
}

void Display(Node* head)
{
   while(head != nullptr)
   {
        cout<<head->data<<' ';
        head = head->next;
   }
   cout<<endl;
}

//Homework 2
Node* reversedList(Node* head)
{
    Node* temp;
    while(head != nullptr)
    {
        temp = head->prev;
        head->prev = head->next;
        head->next = temp;
        head = head->prev;
    }
    if(temp != nullptr) head = temp->prev;
    return head;
}
int main()
{
    Node* head=constructDoubly();
    Display(head);
    head = reversedList(head);
    Display(head);
}
