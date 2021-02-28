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
bool dfs(int x,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&cur_path)
{
    vis[x] = true;
    cur_path[x] = true;
    bool toReturn = false;
    for(auto it = adj[x].begin();it!=adj[x].end();it++)
    {
        if(!vis[*it])
           toReturn = toReturn or dfs(*it,adj,vis,cur_path);
        else
            if(cur_path[*it]) return true;
        
    }
    cur_path[x] = false;
    return toReturn;
}
int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    vector<bool>cur_path(n+1,false);
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
    }
    bool b = false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) b = dfs(i,adj,vis,cur_path);
        if(b) break;
    }
    
    cout<<b<<endl;
}
