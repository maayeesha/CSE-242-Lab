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

//Homework 1
bool sorted(Node* head)
{
    int x = INT_MIN;
    while(head != nullptr)
    {
        if(head->data < x) return false;
        x = head->data;
        head= head->next;
    }
    return true;
}


int main()
{
    Node* head = Construct();
    bool ans = sorted(head);
    if(ans==true) cout<<"Sorted"<<endl;
    else cout<<"Not Sorted"<<endl;

}
