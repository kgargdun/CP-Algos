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
bool dfs(int x,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&color)
{
    vis[x] = true;
    bool toReturn = true;
    for(auto it = adj[x].begin();it!=adj[x].end();it++)
    {
        if(!vis[*it])
        {
            color[*it] = color[x]^1;
           toReturn = toReturn and dfs(*it,adj,vis,color);
        }
        else if(color[*it]==color[x]) return false;
        
    }
    return toReturn;
}
int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    vector<int>color(n+1,-1);
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    color[1] = 0;
    cout<<dfs(1,adj,vis,color)<<endl;
}
