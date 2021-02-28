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
    int to,weight;
    int min_cost = 0;
    int x,y,wt;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    while(m--)
    {
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
        adj[y].pb({x,wt});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<bool>vis(n+1,false);
    pq.push({0,1});   // hypothetical  edge from node 1 to itself
    
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        to = p.second;
        weight = p.first;
        if(vis[to]) continue;
        
        min_cost += weight;
        vis[to] = true;
        
        for(auto z:adj[to])
            if(!vis[z.first])
                pq.push({z.second,z.first});
        
    }
    
    cout<<min_cost<<endl;
}
