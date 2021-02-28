#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<algorithm>
#define pb push_back
#define N (lli)(3e6)
#define lli  long long int
#define m (lli)(1e9+7)
#define INF lli_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

void buildSegmentTree(vector<int>&arr,int s,int e,int index,vector<int>&tree)
{
    if(s==e)
    {
        tree[index] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    buildSegmentTree(arr, s, mid, 2*index, tree);
    buildSegmentTree(arr, mid+1, e, 2*index+1, tree);
    tree[index]  = min(tree[2*index],tree[2*index+1]);
}
int query(vector<int>&tree,int qs,int qe,int ns,int ne,int index)
{
    //no overlap
    if(qe<ns or qs>ne) return INT_MAX;
    
    //complete overlap
    if(ns>=qs and ne<=qe) return tree[index];
    
    //partial overlap
    int mid = (ns + ne)/2;
    int left = query(tree,qs,qe,ns,mid,2*index);
    int right = query(tree,qs,qe,mid+1,ne,2*index+1);
    return min(left,right);
}

void update(vector<int>&tree,int ns, int ne,int toUpdate, int i, int index)
{
    // no overlap
    if(i>ne or i<ns) return;
    
    //leaf
    if(ns==ne)
    {
        tree[index] += toUpdate;
        return;
    }
    
    //overlap
    int mid = (ns + ne)/2;
    update(tree,ns,mid,toUpdate,i,2*index);
    update(tree,mid+1,ne,toUpdate,i,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int lazy[N] = {0};
void updateRangeLazy(vector<int>&tree, int ns, int ne, int qs, int qe, int inc, int index)
{
    // first always resolve the lazy value
    if(lazy[index]!=0)
    {
        tree[index] += lazy[index];
        if(ns!=ne)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // base case - no overlap
    if(ns>qe or ne<qs) return;
    
    //base case - complete overlap
    if(qs<=ns and ne<=qe)
    {
        tree[index]+= inc;
        if(ns!=ne)
        {
            lazy[2*index] +=inc;
            lazy[2*index+1] +=inc;
        }
        return;
    }
    
    //recursive case - partial overlap
    int mid = (ns+ne)/2;
    updateRangeLazy(tree, ns, mid, qs, qe, inc, 2*index);
    updateRangeLazy(tree, mid+1, ne, qs, qe, inc, 2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    
    
}

int queryLazy(vector<int>&tree,int ns,int ne,int qs,int qe,int index)
{
    //resolve lazy
    if(lazy[index]!=0)
    {
        tree[index] +=lazy[index];
        if(ns!=ne)
        {
            lazy[2*index+1] +=lazy[index];
            lazy[2*index] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // base case - no overlap
    if(ne<qs or qe<ns) return INT_MAX;
    
    //base case - complete overlap
    if(qs<=ns and ne<=qe) return tree[index];
    
    //recursive case
    int mid = (ne+ns)/2;
    int left = queryLazy(tree, ns, mid, qs, qe, 2*index);
    int right = queryLazy(tree, mid+1, ne, qs, qe, 2*index+1);
    return min(left,right);
    
    return 0;
}
int main()
{

    int n,q;
    int t,l,r,chg;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>tree(4*n+1,0);
    buildSegmentTree(arr,0,n-1,1,tree);
    for(int x:tree) cout<<x<<" ";
    cout<<endl;
    while(q--)
    {
        cin>>t;
        if(t==0)
        {
            cin>>l>>r;
            cout<<queryLazy(tree,0, n-1, l, r, 1)<<endl;
        }
        else
        {
            cin>>l>>r>>chg;
            updateRangeLazy(tree, 0, n-1, l, r, chg, 1);
        }
    }
    
}
