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

vector<lli>parent;
vector<vector<lli>>adj;
map<pair<lli, lli>, lli>capacity;
lli n, m;

lli bfs(lli source, lli destination)
{
	queue<pair<lli, lli>>q;
	q.push({source, INF});
	for (lli i = 1; i <= n; i++) parent[i] = -1;
	parent[source] = 0;

	while (!q.empty())
	{
		lli node = q.front().first;
		lli flow = q.front().second;
		q.pop();
		for (lli child : adj[node])
		{
			if (parent[child] != -1 or capacity[ {node, child}] == 0) continue;
			parent[child] = node;
			lli new_flow = min(flow, capacity[ {node, child}]);
			if (child == destination) return new_flow;
			q.push({child, new_flow});
		}
	}
	return 0;
}

int  main()
{
	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	lli u, v, c, new_flow, src, dest;
	lli flow;

	adj.resize(n + 1);
	for (lli i = 0; i < m; i++)
	{
		cin >> u >> v >> c;
		capacity[ {u, v}] += c;
		adj[u].pb(v);
		adj[v].pb(u);
	}


	parent.resize(n + 1);
	flow = 0;
	src =  1;
	dest = n;

	while (1)
	{
		new_flow = bfs(src, dest);
		if (new_flow == 0) break;

		flow  += new_flow;
		lli cur = dest;
		while (cur != src)
		{
			lli prev = parent[cur];
			capacity[ {prev, cur}] -= new_flow;
			capacity[ {cur, prev}] += new_flow;
			cur = prev;
		}
	}

	cout << flow << endl;

}