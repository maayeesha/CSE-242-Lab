//Maayeesha Farzana
//Id: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node* prev;
Node* next;
};

//Task 1
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

//Task 2
void searchElement(Node* head,int x)
{
    while(head != nullptr)
    {
        if(head->data == x)
        {
            cout<<"Found"<<endl;
            return ;
        }
        head = head->next;
    }
    cout<<"Not found"<<endl;
}

//Task 3
void sortedInsert(Node* head, int x)
{
    while(head != nullptr && head->data <= x)
    {
        head = head->next;
    }
    if(head == nullptr) return;

    Node* new_node = new Node;
    new_node->data = x;
    new_node->prev = head->prev;
    new_node->next = head;
}
int main()
{
    Node* head = constructDoubly();
    Display(head);
    cout<<"Search element: ";
    int x;
    cin>>x;
    searchElement(head,x);
    //Insert in sorted list
     cout<<"Insert element: ";
    cin>>x;
    sortedInsert(head,x);
    Display(head);
}
