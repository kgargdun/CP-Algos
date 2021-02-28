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

int find_set(int x,vector<int>&parent)
{
    if(parent[x]==x) return x;
    else return parent[x] = find_set(parent[x],parent);
}

void union_set(int x,int y,vector<int>&parent,vector<int>&rank)
{
    int x_ = find_set(x,parent);
    int y_ = find_set(y,parent);
    if(x_==y_) return;
    
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
}
int main()
{
    int n;
    cin>>n;
    vector<int>rank(n+1);
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
    
//    cout<<find_set(4,parent)<<endl;
//    union_set(1,2,parent,rank);
//    cout<<find_set(2,parent)<<endl;
//    cout<<find_set(1,parent)<<endl;
//    union_set(1,6,parent,rank);
//    cout<<find_set(6,parent)<<endl;
//    union_set(7,5,parent,rank);
//    cout<<find_set(5,parent)<<endl;
//    cout<<find_set(1,parent)<<endl;

}
