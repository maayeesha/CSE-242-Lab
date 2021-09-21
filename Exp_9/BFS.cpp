//Maayeesha Farzana
//ID: 1804069
// BFS
#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(100,false);

void edge(vector<int> li[],int x,int y)
{
    li[x].push_back(y);
    li[y].push_back(x);
}

void BFS(vector<int> li[],int n)
{
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            vis[i] = true;
            q.push(i);

            while(!(q.empty()))
            {
                i = q.front();
                cout<<i<<' ';
                q.pop();

                for(int j=0; j != li[i].size(); j++)
                {
                    if(vis[li[i][j]] == false)
                    {
                        vis[li[i][j]] = true;
                        q.push(li[i][j]);
                    }
                }
            }
        }
    }
}

int main()
{
    int n,i,x,y,e;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;
    vector<int> li[n];

    for(i=0; i<e; i++)
    {
        cin>>x>>y;
        edge(li,x,y);
    }
    BFS(li,n);
}
