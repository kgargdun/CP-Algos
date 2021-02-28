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

set<int>articulationPoint;
vector<pair<int,int>>bridges;

void dfs(int x,int parent,int cur,vector<vector<int>>&gr,vector<int>&lower,vector<int>&discovered)
{
    discovered[x] = lower[x] = ++cur;
    int children = 0;

    for(int child : gr[x])
    {
        if(discovered[child]==0)
        {
            children++;
            dfs(child,x,cur,gr,lower,discovered);
            lower[x] = min(lower[x],lower[child]);
            
            if(parent!=0 and lower[child]>=discovered[cur])
                articulationPoint.insert(x);
            
            if(lower[child]>discovered[x])
                bridges.pb({x,child});
        }
        else if(child!=parent)
        {
            lower[x] = min(lower[x],discovered[child]);
        }
    }
    
    // for root
    if(parent==0 and children>=2)
        articulationPoint.insert(x);
    
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>gr(n+1);
    vector<int>discovered(n+1,0);
    vector<int>lower(n+1);
    
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1, 0, 0, gr, lower, discovered);
    
    for(auto it=articulationPoint.begin();it!=articulationPoint.end();it++)
        cout<<*it<<" ";
    
    cout<<endl;
    
    for(auto v:bridges)
        cout<<v.first<<" "<<v.second<<endl;
    
    
}


