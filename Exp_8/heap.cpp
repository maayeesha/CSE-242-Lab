//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

void heapInsert(int a[],int i)
{
    int t;
    t= a[i];
    while(i>1 && t>a[i/2])
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = t;
}

void heapDelete(int a[],int n)
{
    int p,q,t,x,y;
    x = a[1];
    y = a[n];
    a[1] = a[n];
    p=1; q=p*2;
    while(q<n-1)
    {
        if(a[q+1] > a[q])
            q++;
        if(a[p]<a[q])
        {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
            p=q;
            q *=2;
        }
        else break;
    }
}

int main()
{
    int n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(i=1; i<=n; i++) cin>>a[i];
    for(i=2; i<=n; i++)
    {
        heapInsert(a,i);
    }
    for(i=1; i<=n; i++)
    cout<<a[i]<<' ';

    cout<<"\nAfter deletion"<<endl;
    heapDelete(a,n);
    a[n] = 0; // last node == empty node
    for(i=1; i<=n-1; i++)
        cout<<a[i]<<' ';
}
