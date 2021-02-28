#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
#define debug cout<<endl;
#define ll long long int
#define pb push_back

// Alternate way to find in_deg and out_deg
//void dfs(int x,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&in_deg,vector<int>&out_deg)
//{
//
//    vis[x]=true;
//    for(auto it=adj[x].begin();it!=adj[x].end();it++)
//    {
//        out_deg[x]++;
//        in_deg[*it]++;
//        if(!vis[*it])
//            dfs(*it,adj,vis,in_deg,out_deg);
//    }
//
//}

int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    
    vector<vector<int>>adj(n+1);
    vector<int>in_deg(n+1,0);
    vector<int>out_deg(n+1,0);
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        in_deg[y]++;
        out_deg[x]++;
    }
    vector<bool>vis(n+1,false);

    
//    for(int i=1;i<=n;i++)
//    {
//        if(!vis[i])
//            dfs(i,adj,vis,in_deg,out_deg);
//    }
    
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>order;
    vis.assign(n+1,false);
    int top;
    for(int j=1;j<=n;j++)
    {
        if(in_deg[j]==0)
              pq.push(j);
    }

    while(!pq.empty())
    {
        top=pq.top();
        vis[top]=true;
        order.pb(top);
        pq.pop();
        for(auto it = adj[top].begin();it!=adj[top].end();it++)
        {
            in_deg[*it]--;
            if(in_deg[*it]==0)
                pq.push(*it);
        }
        
    }
    for(int x:order)  cout<<x<<" ";
    cout<<endl;
 
}
