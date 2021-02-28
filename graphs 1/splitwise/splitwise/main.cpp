#include<iostream>
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
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y,amount;
    vector<int>net(n+1);
    while(m--)
    {
        cin>>x>>y>>amount;
        net[x] -= amount;
        net[y] += amount;
    }
    
    multiset<pair<int,int>>ms;
    for(int i=1;i<=n;i++) if(net[i]!=0) ms.insert({net[i],i});
    
    int ct = 0;
    while(!ms.empty())
    {
        int debitor = ms.begin()->second;
        int debit = ms.begin()->first;
        int creditor = prev(ms.end())->second;
        int credit = prev(ms.end())->first;
        ms.erase(prev(ms.end()));
        ms.erase(ms.begin());
        int settled = min(credit,(-1)*debit);
        debit = debit + settled;
        credit = credit - settled;
        cout<<creditor<<" pays "<<settled<<" to "<<debitor<<endl;
        ct++;
        
        if(debit!=0)
            ms.insert({debit,debitor});
        if(credit!=0)
            ms.insert({credit,creditor});
    }
}

