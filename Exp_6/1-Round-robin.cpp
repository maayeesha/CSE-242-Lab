//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,c,i;

    cout<<"Enter number of process: ";
    cin>>n;
    cout<<"Enter execution time for each process: ";
    cin>>t;
    cout<<"Iteration time: ";
    cin>>c;

    int remTime[n];
    queue<int> ready;

    for(i=0; i<n; i++) remTime[i] = t;
    for(i=0; i<n; i++)
    {
        ready.push(i+1);
    }
    for(i=1; i<=n; i++)
        cout<<i<<' ';
    cout<<endl;
    for(i=0; i<n; i++)
        cout<<remTime[i]<<' ';
    cout<<endl;
    while(true)
    {
        int x = remTime[ready.front()-1] - c;

        if(x > 0)
        {
            int y = ready.front();
            remTime[y-1] -= c;
            ready.pop();
            ready.push(y);
        }
        else
        {
            int y = ready.front();
            remTime[y-1] = 0;
            ready.pop();
        }

        for(i=0; i<n; i++)
            cout<<remTime[i]<<' ';
        cout<<endl;

        if(remTime[n-1] == 0) break;

    }
    return 0;
}




