//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* Construct()
{
    Node* head = nullptr;
    Node* prev_node;
    while(1)
    {
        int input;
        cin>>input;
        if(input == -1) break;
        Node* curr_node = new Node;
        curr_node->data = input;
        curr_node->next = nullptr;

        if(head == nullptr) head = curr_node;
        else prev_node->next = curr_node;
        prev_node=curr_node;
    }
    return head;
}
//Homework 2
void sortedInsert(Node* head,int x)
{
    Node* temp = new Node;
    Node* curr_node;
    temp->data = x;
    temp->next = nullptr;

    while(head !=nullptr && head->data < x)
    {
        curr_node = head;
        head = head->next;
    }
    temp->next = curr_node->next;
    curr_node->next = temp;
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

int main()
{
    Node* head = Construct();
    Display(head);
    //insert x;
    int x;
    cout<<"Insert in an sorted array: "<<' ';
    cin>>x;
    sortedInsert(head,x);
    Display(head);
}
