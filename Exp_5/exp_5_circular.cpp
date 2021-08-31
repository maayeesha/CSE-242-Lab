//Maayeesha Farzana
//Id: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node* prev;
Node* next;
};

//Task 4
Node* constructCircular()
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
        curr->next = head;

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
    Node* temp = head;
   while(head != nullptr)
   {
        cout<<temp->data<<' ';
        temp = temp->next;
        if(temp == head) break;
   }
   cout<<endl;
}

//Task 5
void circular(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        if(temp == head)
        {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main()
{
    Node* head = constructCircular();
    Display(head);
    cout<<"Is the list circular? ";
    circular(head);
}

