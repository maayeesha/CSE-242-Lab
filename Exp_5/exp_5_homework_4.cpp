//Maayeesha Farzana
//Id: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node* prev;
Node* next;
};

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

void randomDisplay(Node* p)
{
    Node* temp = p;
   while(p != nullptr)
   {
        cout<<temp->data<<' ';
        temp = temp->next;
        if(temp == p) break;
   }
   cout<<endl;
}

int main()
{
  Node* head = constructCircular();
  cout<<"Enter a Node: ";
  int x;
  cin>>x;

  while(head != nullptr)
  {
      if(head->data == x)
      {
          randomDisplay(head);
          break;
      }
      head = head->next;
  }

}

