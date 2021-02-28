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

struct sparse_table
{
    vector<vector<int>>mat;
    vector<int>p2;
    int n,m;
    void init(int n,int m)
    {
        this->n = n;
        this->m  = m;
        mat.assign(n,vector<int>(m,-1));
        p2.assign(n+1,0);
        for(int i=2;i<=n;i++) p2[i] = p2[i/2] + 1;
    }
    void build(vector<int>&v)
    {
        for(int i=0;i<n;i++)
            mat[i][0] = v[i];
         
        for(int j=1;j<m;j++)
            for(int i=0;i<n;i++)
            {
                if(i+(1<<j)-1<n) mat[i][j] = max(mat[i][j-1],mat[i +(1<<(j-1))][j-1]);
            }
    }
    
    int query(int l, int r)
    {
        int pw = p2[r-l+1];
        return max(mat[l][pw],mat[r-(1<<pw)+1][pw]);
        
        
    }
};
int main()
{
    int n,m;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    m = ceil(log2((double)n)) + 1;
    
    
    sparse_table t1;
    t1.init(n,m);
    t1.build(arr);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<t1.mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<t1.query(5,5)<<endl;
    
    
}
