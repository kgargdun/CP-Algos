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

int n;
int neg(int x)
{
    if(x<=n) return n+x;
    else return x-n;
}

void dfs(int x,vector<int>&order, vector<bool>&vis,vector<vector<int>>&adj)
{
    vis[x] = true;
    for(int node :adj[x])
    {
        if(!vis[node])
            dfs(node,order,vis,adj);
    }
    order.pb(x);
}


void dfs2(int x,vector<bool>&vis,vector<vector<int>>&radj,vector<int>&temp)
{
    vis[x] = true;
    temp.pb(x);
    for(int node :radj[x])
    {
        if(!vis[node])
            dfs2(node,vis,radj,temp);
    }
}

bool can_take(vector<int>&v,vector<int>&taken)
{
    map<int,int>mp;
    for(int i:v)
    {
        if(i>n) i = i - n;
        if(taken[i]!=-1 or mp[i]==1) return false;
        mp[i] = 1;
    }
    return true;
    
}

int main()
{
    int m;
    cin>>m>>n;
    vector<vector<int>>adj(2*n+1);
    vector<vector<int>>radj(2*n+1);
    while(m--)
    {
        char ch1,ch2;
        int x1, x2;
        cin>>ch1>>x1>>ch2>>x2;
        if(ch1=='-') x1 += n;
        if(ch2=='-') x2 += n;
        
        adj[neg(x1)].pb(x2);
        adj[neg(x2)].pb(x1);
        
        radj[x2].pb(neg(x1));
        radj[x1].pb(neg(x2));
    }
    
    vector<int>order;
    vector<bool>vis(2*n+1,false);
    
    for(int i=1;i<=2*n;i++)
    {
        if(!vis[i])
            dfs(i,order,vis,adj);
    }
    
    //    for(int h:order)  cout<<h<<" ";
    reverse(order.begin(),order.end());
    
    vis.assign(2*n+1,false);
    vector<int>taken(n+1,-1);
    vector<vector<int>>topo;
    
    for(int i=0;i<2*n;i++)
    {
        if(!vis[order[i]])
        {
            vector<int>temp;
            dfs2(order[i],vis,radj,temp);
            topo.pb(temp);
        }
    }
    
    
    
//        for(auto v:topo)
//        {
//            for(int h:v)  cout<<h<<" ";
//            cout<<endl;
//        }
    
    reverse(topo.begin(),topo.end());
    for(auto v:topo)
    {
        if(can_take(v,taken))
            for(int i:v)
            {
                if(i>n)
                {
                    i = i-n;
                    taken[i] = 0;
                }
                else taken[i] = 1;
            }
    }
    
    for(int i=1;i<=n;i++)
        if(taken[i]==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    
    for(int i=1;i<=n;i++) taken[i]==1?cout<<'+'<<" ":cout<<'-'<<" ";
    
}



