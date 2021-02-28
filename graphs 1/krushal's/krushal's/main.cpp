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
int find_set(int x,vector<int>&parent)
{
    if(parent[x]==x) return x;
    else return parent[x] = find_set(parent[x],parent);
}

bool union_set(int x,int y,vector<int>&parent,vector<int>&rank)
{
    int x_ = find_set(x,parent);
    int y_ = find_set(y,parent);
    if(x_==y_) return false;
    
    if(rank[x_]>rank[y_])
    {
        parent[y_] = x_;
    }
    else if (rank[y_]>rank[x_])
    {
        parent[x_] = y_;
    }
    else
    {
        parent[y_] = x_;
        rank[x_] ++;
    }
    return true;
}
struct edge
{
    int u,v,wt;
    edge(int u,int v,int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};
bool comparator(edge &e1,edge &e2)
{
    return e1.wt<e2.wt;
}
int main()
{
    int n,m;
    int x,y,wt;
    int min_cost = 0;
    cin>>n>>m;
    vector<int>parent(n+1);
    vector<int>rank(n+1);
    vector<edge>edges;
    while(m--)
    {
        cin>>x>>y>>wt;
        edges.pb(edge(x,y,wt));
    }
    sort(edges.begin(),edges.end(),comparator);
    
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
  
    for(int i = 0;i<edges.size();i++)
    {
        x = edges[i].u;
        y = edges[i].v;
        if(union_set(x,y,parent,rank)) min_cost += edges[i].wt;
    }
    
    cout<<min_cost<<endl;
    
    
    
}
