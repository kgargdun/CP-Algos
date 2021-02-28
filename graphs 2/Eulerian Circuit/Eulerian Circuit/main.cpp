#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<set>
#include<stack>
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

map<pair<int,int>,int>mp;
void dfs(int x,vector<vector<int>>&adj,vector<int>&ans,vector<bool>&vis)
{
    vis[x] = true;
    while(!adj[x].empty())
    {
        int child = adj[x].back();
        adj[x].pop_back();                                       // deletion of edges
        if(mp[{x,child}]==1) continue;
        mp[{child,x}] = 1;
        dfs(child,adj,ans,vis);
    }
    ans.pb(x);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>inDeg(n+1,0);
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        inDeg[x]++;
        inDeg[y]++;
    }
    
    for(int i=1;i<=n;i++)
        if(inDeg[i]%2!=0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    
    vector<int>ans;
    vector<bool>vis(n+1,false);
    
    int j;
    for(j=1;j<=n;j++)
    {
        if(inDeg[j]==0) continue;
        else
        {
            dfs(j, adj,ans,vis);
            break;
        }
    }
    
    
    while(j<=n)
    {
        if(inDeg[j]==0)
        {
            j++;
            continue;
        }
        if(!vis[j])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        j++;
    }
    
    for(int x:ans)  cout<<x<<" ";
    
    
    
    
}




//10 16
//9 10
//8 6
//8 5
//1 7
//2 8
//3 8
//3 1
//6 3
//10 3
//8 9
//3 5
//10 2
//5 9
//7 8
//9 3
//5 10

