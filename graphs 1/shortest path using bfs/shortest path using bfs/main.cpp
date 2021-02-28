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
int main()
{
    int n,m;
    int x,y,src;
    cin>>n>>m>>src;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    vector<int>dist(n+1,-1);
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    vis[src] = true;
    while(!q.empty())
    {
        int top = q.front();
        for(auto it=adj[top].begin();it!=adj[top].end();it++)
            if(!vis[*it])
            {
                q.push(*it);
                dist[*it] = dist[top] + 1;
                vis[*it] = true;
            }
        q.pop();
    }
    
    for(int x:dist) cout<<x<<" ";
    
}
