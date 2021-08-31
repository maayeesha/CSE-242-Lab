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

//Homework 1
void insertion(Node* head,int x)
{
    Node* temp = head;
    Node* new_node = new Node;
    new_node->data = x;
    new_node->prev = head;
    new_node->next = temp->next;
    head->next = new_node;
}

void deleteion(Node* head, int x)
{
    while(head != nullptr)
    {
        if(head->data == x)
        {
            head->prev->next = head->next;

        }
        head = head->next;
    }
}
int main()
{
    Node* head=constructDoubly();
    Display(head);
    //insert an element
    int x;
    cout<<"Insert an element: ";
    cin>>x;
    insertion(head,x);
    Display(head);
    cout<<"Delete an element: ";
    cin>>x;
    deleteion(head,x);
    Display(head);
}
