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
#define N (lli)(1e4)
#define lli  long long int
#define mod (lli)(998244353)
#define INF (1e9)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;
//Faster than Usain Bolt
lli factorial[N+1];
lli invFactorial[N+1];

lli inverse(lli x)
{
    lli pow = mod - 2;
    lli res = 1;
    while(pow!=0)
    {
        if(pow%2==0)
        {
            x = (x * x)%mod;
            pow = pow/2;
        }
        else
        {
            res = (res * x)%mod;
            pow--;
        }
    }
    return res;
}

lli nCr(lli n, lli r)
{
    if(r>n) return 0;
    lli toReturn = ((factorial[n]*invFactorial[n-r])%mod*invFactorial[r])%mod;
    return toReturn;
}
int main()
{
    factorial[0]= 1;
    for(lli i=1;i<=N;i++)
        factorial[i] = (factorial[i-1]*i)%mod;
    
    invFactorial[N] = inverse(factorial[N]);
    for(lli i= N-1;i>=0;i--)
        invFactorial[i] = (invFactorial[i+1] * (i+1))%mod;
    

    
}

