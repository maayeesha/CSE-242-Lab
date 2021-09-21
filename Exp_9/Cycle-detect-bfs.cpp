//Maayeesha Farzana
//ID: 1804069
// Detect cycle using BFS

#include<bits/stdc++.h>
using namespace std;

void edge(vector<int> li[],int x,int y){
    li[x].push_back(y);
    li[y].push_back(x);
}


bool BFScycle(vector<int> li[],int i,int n,vector<bool>& vis)
{
    vector<int> p(n,-1);
    queue<int> q;

            vis[i] = true;
            q.push(i);

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                for (auto it: li[u])
                {
                    if(vis[it] == false)
                    {
                        vis[it] = true;
                        q.push(it);
                        p[it] = u;
                    }
                    else if(p[u] != it) return true;
                }
            }
            return false;
        }

bool isCycle(vector<int> li[],int n)
{
    vector<bool> vis(n,false);
    for (int i=0; i<n; i++)
        if (vis[i] == false && BFScycle(li, i,
                                         n,vis))
            return true;
    return false;
}

int main()
{
    int n,e,x,y,i;

    cout<<"Enter number of Nodes: ";
    cin>>n;
    cout<<"Enter number of Edges: ";
    cin>>e;
    vector<int> li[n];

    for(i=0; i<e; i++)
    {
        cin>>x>>y;
        edge(li,x,y);
    }
    if(isCycle(li,n)) cout<<"Cycle found"<<endl;
    else cout<<"No cycle found"<<endl;
}
