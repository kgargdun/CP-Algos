#include <iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<cmath>
#include<algorithm>
#define pb push_back
#define N (lli)(3e5)
#define lli  long long int
#define mod (lli)(1e9+7)
#define INF lli_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int  main()
{
    lli n,m;
    cin>>n>>m;
    lli x,y,w;
    vector<vector<pair<lli,lli>>>adj(n+1);
    while(m--)
    {
        cin>>x>>y>>w;
        adj[x].pb({y,w});
    }
    
    vector<lli>dist(n+1,LLONG_MAX);
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>>pq;
    
    vector<bool>vis(n+1,false);
    dist[1] = 0;
    pq.push({0,1});
    
    
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        lli far = node.first;
        lli nx = node.second;
        if(dist[nx]!=far) continue;
        
        vis[nx] = true;
        for(auto z : adj[nx])
        {
            if(vis[z.first]) continue;
            if(dist[z.first] > far + z.second)
            {
                dist[z.first] = far + z.second;
                pq.push({dist[z.first],z.first});
            }
        }
    }
    
    for(lli i=1;i<=n;i++)  cout<<dist[i]<<" ";
    cout<<endl;
    
    
}

