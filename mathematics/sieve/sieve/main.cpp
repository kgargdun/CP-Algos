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
#define N (lli)(5e6+5)
#define lli  long long int
#define mod (lli)(1e9+7)
#define INF (1e9)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;
//Faster than Usain Bolt

lli sieve[N+1];

int main()
{

    for(lli i=1;i<=N;i++) sieve[i] = i;
    
    for(lli i=2;i*i<=N;i++)
        for(lli j=i*i;j<=N;j+=i)
        {
            if(sieve[j]==j)
                sieve[j] = i;
        }
    
    
    for(int i=1;i<20;i++) cout<<sieve[i]<<" ";
    

    
    
}

