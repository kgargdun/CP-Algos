#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<algorithm>
#define pb push_back
#define N (lli)(3e5)
#define lli  long long int
#define mod (lli)(1e9+7)
#define INF lli_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vector<int>p2(100);
void dfs(vector<vector<int>>&adj,vector<int>&parent,vector<int>&level,int x)
{
    for(auto it=adj[x].begin();it!=adj[x].end();it++)
    {
        if(*it!=parent[x])
        {
            parent[*it] = x;
            level[*it] = level[x]+1;
            dfs(adj,parent,level,*it);
        }
    }
}
int lca_superfast(int u,int v,int m,vector<int>&level,vector<int>&parent,vector<vector<int>>&sparse)
{
    int toReturn = 0;
    if(u==v) return u;
    if(level[u]<level[v]) swap(u,v);
    int diff = level[u] - level[v];
    while(diff!=0)
    {
        int pw = p2[diff];
        diff = diff - (1<<pw);
        u = sparse[u][pw];
    }
    if(u==v) return u;
    while(parent[u]!=parent[v])
    {
        for(int i=m-1;i>=0;i--)
        {
            int u1 = sparse[u][i];
            int v1 = sparse[v][i];
            if(u1!=v1)
            {
                u = sparse[u][i];
                v = sparse[v][i];
            }
        }
    }
    toReturn = parent[v];
    return toReturn;
    
}
int main()
{
    p2[1] = 0;
    for(int i=2;i<100;i++) p2[i] = p2[i/2] + 1;
    int n,x,y;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int>parent(n+1,0);
    vector<int>level(n+1,0);
    parent[1] = 0;
    level[1] = 0;
    dfs(adj,parent,level,1);
    
    //    for(auto x:parent) cout<<x<<" ";
    //    cout<<endl;
    
    int m = ceil(log2(double(n))) + 1;
    vector<vector<int>>sparse(n+1,vector<int>(m,0));
    
    for(int i=0;i<=n;i++) sparse[i][0] = parent[i];
    for(int j=1;j<m;j++)
        for(int i=0;i<=n;i++)
            sparse[i][j] = sparse[sparse[i][j-1]][j-1];
    
    //    for(int i=1;i<=n;i++)
    //    {
    //        for(int j=0;j<m;j++) cout<<sparse[i][j]<<" ";
    //        cout<<endl;
    //    }
    int u,v,tes;
    cin>>tes;
    while(tes--)
    {
        cin>>u>>v;
        cout<<lca_superfast(u,v,m,level,parent,sparse)<<endl;
    }
    
    
    
    
}

//
//24
//1 2
//1 3
//2 4
//3 5
//3 6
//4 7
//4 8
//5 9
//5 11
//6 10
//7 12
//8 13
//11 14
//11 15
//10 16
//13 17
//13 18
//14 20
//14 22
//15 23
//18 19
//20 21
//23 24
