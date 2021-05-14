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

bool bfs(vector<vector<int>>&adj, int src, int sink, int parent)
{

}

int  main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int v, e;
	cin >> v >> e;
	vector<vector<int>>adj(v + 1, vector<int>(v + 1, 0));


	int x, y, w;
	for (int i = 0; i < e; i++)
	{
		cin >> x >> y >> w;
		adj[x][y] = w;
	}






}
