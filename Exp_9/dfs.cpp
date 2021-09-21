//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(100,false);

void edge(vector<int> li[],int x,int y)
{
    li[x].push_back(y);
    li[y].push_back(x);
}

void DFS(vector<int> li[],int x)
{
    int i;
    vis[x] = true;
    cout<<x<<" ";
    for(i=0; i != li[x].size(); i++)
    {
        cout<<i<<endl;
        if(vis[i] == false)
        {
            DFS(li,i);
        }
    }
}

int main()
{
    int n,e,x,y,i;
    cout<<"Enter number of Nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;
    vector<int> li[n];
    for(i=0; i<e; i++)
    {
        cin>>x>>y;
        edge(li,x,y);
    }
    DFS(li,2);
}
