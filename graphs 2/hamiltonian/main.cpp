#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<unordered_map>
#define pb push_back
#define N (lli)(1e6+5)
#define M (lli)(1e6)
#define lli long long int
#define mod (lli)(998244353)
#define INF LLONG_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;
// number of hamiltonian paths from 1 to N
int  main()
{
	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	int  md = 1e9 + 7;
	cin >> n >> m;
	vector<vector<int>>adj(n + 1);
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[v].pb(u);
	}

	vector<vector<int>>dp(1 << n, vector<int>(n + 1, 0));

	dp[1][1] = 1;

	for (int mask = 0; mask < (1 << n); mask++)
	{
		if ((mask & 1) == 0) continue;
		if (mask != ((1 << n) - 1) and (mask & (1 << (n - 1))) > 0) continue;

		for (int i = 1; i <= n; i++)
		{
			if ((mask & (1 << (i - 1))) == 0) continue;

			for (int j : adj[i])
			{
				if ((mask & (1 << (j - 1))) == 0) continue;
				dp[mask][i] = (dp[mask][i] + dp[mask ^ (1 << (i - 1))][j]) % md;
			}
		}
	}


	cout << dp[(1 << n) - 1][n] << endl;

}


