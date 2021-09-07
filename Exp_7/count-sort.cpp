//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,i,m=INT_MIN;
   cout<<"Number of elements: ";
   cin>>n;
   int a[n],ans[n];

   cout<<"Enter elements: ";
   for(i=0; i<n; i++)
   {
       cin>>a[i];
       if(m < a[i]) m = a[i];
   }

   int c[m+1];
   for(i=0; i<=m; i++) c[i] = 0;

   for(i=0; i<n; i++)
   {
       c[a[i]]++;
   }

   for(i=1; i<=m; i++)
   {
       c[i] += c[i-1];
   }

   for(i=n-1; i>=0; i--)
   {
       ans[c[a[i]]-1] = a[i];
       c[a[i]]--;
   }

   for(i=0; i<n; i++)
   {
       a[i] = ans[i];
   }

   for(i=0; i<n; i++) cout<<a[i]<<' ';
   cout<<endl;
}



