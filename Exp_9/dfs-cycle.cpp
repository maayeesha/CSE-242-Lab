//Maayeesha Farzana
//ID: 1804069
// Detect cycle using DFS

#include<bits/stdc++.h>
using namespace std;

int n;
void edge(vector<int> li[],int x,int y)
{
    li[x].push_back(y);
    li[y].push_back(x);
}

bool DFScycle(int i,bool vis[], int p, vector<int> li[])
{
    vis[i] = true;
    vector<int>::iterator it;
    for (it = li[i].begin(); it !=li[i].end(); it++)
    {

        if (!vis[*it])
        {
           if (DFScycle(*it, vis, i,li))
              return true;
        }

        else if (*it != p)
           return true;
    }
    return false;
}

bool isCycle(vector<int> li[])
{
    int i;
    bool *vis = new bool[n];
    for (i = 0; i<n; i++)
        vis[i] = false;

    for (i=0; i<n; i++)
    {
        if (vis[i] == false)
          if (DFScycle(i, vis, -1, li))
             return true;
    }
    return false;
}

int main()
{
    int e,x,y,i;
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
    if(isCycle(li)) cout<<"Cycle found"<<endl;
    else cout<<"No Cycle found"<<endl;
}

