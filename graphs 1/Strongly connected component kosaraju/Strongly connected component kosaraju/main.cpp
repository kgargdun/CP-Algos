#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
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

void dfs(int x,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&order)
{
    vis[x] = true;
    for(auto it=adj[x].begin();it!=adj[x].end();it++)
    {
        if(!vis[*it])
            dfs(*it,adj,vis,order);
    }
    order.pb(x);
}

void dfs2(int x,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&temp)
{
    vis[x] = true;
    temp.pb(x);
    for(auto it=adj[x].begin();it!=adj[x].end();it++)
    {
        if(!vis[*it])
            dfs2(*it,adj,vis,temp);
    }
}

int main()
{
    int n,m;
    int x,y,top;
    int ct = 0;
    vector<vector<int>>ans;
    vector<int>temp;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>radj(n+1);
    vector<bool>vis(n+1,false);
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        radj[y].pb(x);
    }
    vector<int>order;
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i,adj,vis,order);
    
    for(auto x:order)  cout<<x<<" ";
    cout<<endl;
    
    vis.assign(n+1,false);
    while(!order.empty())
    {
        top = order.back();
        if(!vis[top])
        {
            ct++;
            temp.clear();
            dfs2(top,radj,vis,temp);
            ans.pb(temp);
        }
        order.pop_back();
    }
    
    cout<<ct<<endl;
    for(auto v:ans)
    {
        for(int x:v) cout<<x<<" ";
        cout<<endl;
    }

}

