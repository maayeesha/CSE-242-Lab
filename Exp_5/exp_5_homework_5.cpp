//Maayeesha Farzana
//Id: 1804069

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node* prev;
Node* next;
}*fr=nullptr,*bk=nullptr;

void enqueue(int x)
{
    Node*q;
    q = new Node;
    q->data = x;
    if(fr==nullptr) fr = bk = q;
    else{
        bk->next = q;
        q->prev = bk;
        q->next = fr;
        bk = q;
    }
}

void Display()
{
    Node* q = fr;
   while(q != nullptr)
   {
        cout<<q->data<<' ';
        q = q->next;
        if(q == fr) break;
   }
   cout<<endl;
}

int dequeue()
{
    Node* dq;
    int x;
    if(fr==nullptr) cout<<"Queue is empty"<<endl;
    else{
        x = fr->data;
        dq = fr;
        fr = fr->next;
        bk->next = fr;
        fr->prev = bk;
        delete dq;
    }
    return x;
}
int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    cout<<"After enquing values: ";
    Display();
    cout<<"Deleted value: "<<dequeue()<<endl;
    cout<<"After dequing value: ";
    Display();
}
