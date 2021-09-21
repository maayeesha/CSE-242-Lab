//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(100,false);

void edge(vector<int> li[],int x,int y){
    li[x].push_back(y);
    li[y].push_back(x);
}


bool BFScycle(vector<int> li[],int n)
{
    int i;
    vector<int> p(n,-1);
    queue<int> q;
    for(i=0; i<n; i++)
    {
        if(vis[i]==false)
        {
            vis[i] = true;
            q.push(i);

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                for(int j=0; j != li[i].size(); j++)
                {
                    if(vis[j] == false)
                    {
                        vis[j] = true;
                        q.push(j);
                        p[j] = u;
                    }
                    else if(p[u] != j) return true;
                }
            }
        }
    }
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
    if(BFScycle(li,n)) cout<<"Cycle found"<<endl;
    else cout<<"No cycle found"<<endl;
}
