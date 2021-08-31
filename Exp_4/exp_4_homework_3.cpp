//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//Task 1
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

void Display(Node* head)
{

    while(head != nullptr)
    {
        cout<<head->data<<' ';
        head = head->next;
    }
    cout<<endl;
}
//Homework 3

int findLength(Node* head)
{
    int l = 0;
    while(head != nullptr)
    {
        l++;
        head = head->next;
    }
    return l;
}
Node* reverseList(Node* head)
{
    Node* curr_node = head;
    Node* prev_node = nullptr,*next_node = nullptr;
    while(curr_node != nullptr)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node;
}

void palindrome(Node* head)
{
    Node* list1=head;
    Node* list2;
    Node* p=head;;
    int l = findLength(head);
    l = l/2;
    int x = l;

    while(l--)
    {
        p = p->next;
    }

    list2 = p->next;
    list2 = reverseList(list2);
    while(list2 != nullptr)
    {
        if(list1->data != list2->data)
        {
            cout<<"Not Palindrome!"<<endl;
            return;
        }
        list1= list1->next;
        list2= list2->next;
    }
  cout<<"Palindrome!"<<endl;
}

int main()
{
    Node* head = Construct();
    palindrome(head);
}
