#include <iostream>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<set>
#include<string.h>
#include<stack>
#include<algorithm>
#include<unordered_map>
#define pb push_back
#define N (lli)(2e5)
#define INF (2e9)
#define M (lli)(1e6)
#define lli long long int
#define mod (lli)(1e9+7)
#define INFF LLONG_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;

int ranks[N];
int parent[N];

int find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

bool join(int x, int y)
{
	int x_ = find(x);
	int y_ = find(y);


	if (x_ == y_) return false;

	if (ranks[x_] > ranks[y_])
	{
		parent[y_] = x_;

	}
	else if (ranks[y_] > ranks[x_])
	{
		parent[x_] = y_;
	}
	else
	{
		parent[y_] = x_;
		ranks[x_]++;

	}

	return true;

}

int main()
{

	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o3.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		ranks[i] = 1;

	}




}

