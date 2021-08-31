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

//Task 2
void findLength(Node* head)
{
    int l = 0;
    while(head != nullptr)
    {
        l++;
        head = head->next;
    }
    cout<<"Length = "<<l<<endl;
}

//Task 3
void findElement(Node* head,int element)
{
    while(head != nullptr)
    {
        if(head->data == element)
        {
            cout<<"Found"<<endl;
            return;
        }
        head= head->next;
    }
    cout<<"Not Found"<<endl;
}

//Task 4
void insertElement(Node* curr_node, int P, int X)
{
    if(P==1)
    {
        Node* new_node = new Node;
        new_node->data = X;
        new_node->next = curr_node->next;
        curr_node->next = new_node;
    }
    else insertElement(curr_node->next,P-1,X);

}

//Task 5

void deleteNode(Node* head,int X)
{
   Node* temp_node = head;
   Node* prev_node=nullptr;

   if(temp_node != nullptr && temp_node->data == X)
   {
       head = temp_node->next;
       delete temp_node;
       return;
   }
   else
   {
   while(temp_node != nullptr && temp_node->data != X)
   {
       prev_node = temp_node;
       temp_node = temp_node->next;
   }
   if(temp_node == nullptr) return;
   prev_node->next = temp_node->next;
   delete temp_node;
   }
}

//Task 6
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


int main()
{
  Node* head = Construct();
  Display(head);
  findLength(head);
  //find element
  int element;
  cout<<"Which element to find?"<<endl;
  cin>>element;
  findElement(head,element);

  //Insert position and element
  int P,X;
  cout<<"Enter position and element"<<endl;
  cin>>P>>X;
  insertElement(head,P,X);
  //After insertion
  Display(head);
  //delete X
  cout<<"Insert element to be deleted"<<' ' ;
  cin>>X;
  deleteNode(head,X);
  Display(head);

  //reverse a list
  head = reverseList(head);
  Display(head);
}
