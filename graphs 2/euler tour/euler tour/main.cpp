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
#define mod (lli)(998244353)
#define INF (1e9)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;
// In the name of thee
vector<int>gr[N];
int tin[N],tout[N],timer;

void euler1(int cur,int par)
{
    cout<<cur<<" ";
    tin[cur] = timer++;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            euler1(x,cur);
            cout<<cur<<" ";
            
        }
    }
    tout[cur] = timer++;
    
}

void euler2(int cur,int par)
{
    cout<<cur<<" ";
    tin[cur] = timer++;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            euler2(x,cur);
        }
    }
    cout<<cur<<" ";
    tout[cur]=timer++;
    
}


void euler3(int cur,int par)
{
    cout<<cur<<" ";
    tin[cur] = ++timer;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            euler3(x,cur);
        }
    }
    tout[cur] = timer;
}

bool is_anc(int x,int y)
{
    if(tin[x]<=tin[y] and tout[x]>=tout[y]) return true;
    return false;
}
int main()
{
    
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    timer = 0;
    euler3(1,0);
    
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<tin[i]<<" "<<tout[i]<<endl;
    
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cout<<is_anc(x,y)<<endl;
    }
    
    
}



