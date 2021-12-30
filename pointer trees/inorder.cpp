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
#define N (lli)(2e5+5)
#define INF (2e9)
#define M (lli)(1e6)
#define lli long long int
#define mod (lli)(998244353)
#define INFF LLONG_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
using namespace std;


struct node
{
	int val;
	node *left;
	node *right;

	node()
	{
		val  = 0;
		left = right  = NULL;
	}

	node (int x)
	{
		val  = x;
		left = right = NULL;
	}
};

int main()
{

	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = new node();
	root->val = 3;
	root->left = new node(1);
	root->right = new node(5);

	vector<int>arr;
	stack<node*>st;

	node *cur;
	cur = root;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		cur = st.top();
		st.pop();
		arr.pb(cur->val);
		cur = cur->right;
	}

	for (int h : arr) cout << h << " ";




}


