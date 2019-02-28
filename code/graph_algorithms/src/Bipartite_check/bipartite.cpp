#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,m,u,v,c,flag=0;

    // taking n ->number of vertex  and m -> number of edges
    cin>>n>>m;

    // adj is 2-D vector to store edges between vertex
    vector<vector<long int > >adj(n,vector<long int>());

    // dis is use to store color of vertex
    vector<long int> dis(n,-1);
    queue<long int>q;

    //for number of edges times
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    u=0;
    dis[u]=0;
    q.push(u);
    while(!q.empty())
    {
        c=q.front();
        q.pop();
        for(auto i=adj[c].begin();i!=adj[c].end();i++)
        {
            // updating color of vertex
            if(dis[*i]==-1 )
            {
                q.push(*i);
                dis[*i]=1-dis[c];
            }
            else if(dis[*i]==dis[c])  // checking for bipartite graph
            {
                flag=1;
            }
        }
    }
    if(flag==0)
        cout<<"Graph is bipartite";
    else
        cout<<"Graph is not bipartite";
}