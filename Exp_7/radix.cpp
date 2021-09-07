//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

void countSort(int a[], int n, int p,int m)
   {
    int c[m+1],i,ans[n];
    for(i=0; i<=m; i++) c[i] = 0;

   for(i=0; i<n; i++)
   {
       c[(a[i]/p) % 10]++;
   }

   for(i=1; i<=m; i++)
   {
       c[i] += c[i-1];
   }

   for(i=n-1; i>=0; i--)
   {
       ans[c[(a[i]/p) % 10]-1] = a[i];
       c[(a[i]/p) % 10]--;
   }

   for(i=0; i<n; i++)
   {
       a[i] = ans[i];
   }
}

int main()
{
    int n,i,m=INT_MIN;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(m < a[i]) m = a[i];
    }

    for(int p=1; m/p > 0; p *= 10)
    {
        countSort(a,n,p,m);
    }

    for(i=0; i<n; i++)
     {
         cout<<a[i]<<' ';
     }

    cout<<endl;
}




