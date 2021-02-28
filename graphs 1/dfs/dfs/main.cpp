#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#define pb push_back
#define N (lli)(3e5)
#define lli  long long int
#define mod (lli)(1e9+7)
#define INF lli_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;
void dfs(int x,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&parent)
{
    vis[x] = true;
    for(auto it = adj[x].begin();it!=adj[x].end();it++)
    {
        if(!vis[*it])
        {
            dfs(*it,adj,vis,parent);
            parent[*it] = x;
        }
    }
}
int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    vector<int>parent(n+1,-1);
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    parent[1] = 0;
    dfs(1,adj,vis,parent);
    for(int x:parent)  cout<<x<<" ";
    
    
}

