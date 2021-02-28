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
void dfs(int x,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st)
{
    vis[x] = true;
    for(auto it = adj[x].begin();it!=adj[x].end();it++)
    {
        if(!vis[*it])
            dfs(*it,adj,vis,st);
    }
    st.push(x);
}

int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    stack<int>st;
    while(m--)
    {
        cin>>x>>y;
        adj[x].pb(y);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i,adj,vis,st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    
}

