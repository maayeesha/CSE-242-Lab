//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*fr=nullptr,*bk=nullptr;

void enqueue(int x)
{
    Node *q;
    q = new Node;
    if(q==nullptr)
        cout<<"Queue full"<<endl;
    else
    {
        q->data = x;
        q->next = nullptr;
        if(fr == nullptr)
        {
            fr = bk = q;
        }
        else{
            bk->next = q;
            bk = q;
        }
    }
}

int dequeue()
{
    Node* dq;
    int x;
    if(fr==nullptr)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        x = fr->data;
        dq = fr;
        fr = fr->next;
        delete dq;
    }
    return x;
}

void Display()
{
  Node *q=fr;
  while(q != nullptr)
  {
    cout<<q->data<<' ';
    q=q->next;
  }
  cout<<endl;
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    Display();
    cout<<dequeue();
    return 0;
}

