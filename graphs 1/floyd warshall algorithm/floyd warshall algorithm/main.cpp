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
#define mod (lli)(100)
#define INF LLONG_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>gr(n+1,vector<int>(n+1,INT_MAX));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>gr[i][j];
        }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(gr[i][k]!=INT_MAX and gr[k][j]!=INT_MAX)
                    if(gr[i][j] > gr[i][k] + gr[k][j])
                        gr[i][j] = gr[i][k] + gr[k][j];
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<gr[i][j]<<" ";
        cout<<endl;
    }
}




