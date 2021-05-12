#include <iostream>
#include<map>
#include<unordered_map>
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
unordered_map<int, int>mp;


int rn;
int distinct;

struct query
{
    int l, r, q;
    query()
    {
        l = r = q = -1;
    }
    query(int l, int r, int q)
    {
        this->l = l;
        this->r = r;
        this->q = q;
    }
};

bool comparator(const query &q1, const query &q2)
{
    if (q1.l / rn == q2.l / rn)
    {
        return q1.r < q2.r;
    }
    else return q1.l / rn < q2.l / rn;
}

void Add(int x)
{
    if (mp[x] == 0) distinct++;
    mp[x]++;
}

void Remove(int x)
{
    mp[x]--;
    if (mp[x] == 0) distinct--;
}

void  adjust(int &prevl, int &prevr, query &que, vector<int>&arr)
{
    while (prevl < que.l)
    {
        Remove(arr[prevl]);
        prevl++;
    }

    while (prevl > que.l)
    {
        prevl--;
        Add(arr[prevl]);
    }

    while (prevr < que.r)
    {
        prevr++;
        Add(arr[prevr]);
    }

    while (prevr > que.r)
    {
        Remove(arr[prevr]);
        prevr--;
    }
}

int main()
{
    fast_io;
    int n, q;
    cin >> n >> q;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<query>queries;
    vector<int>ans(q);

    rn = sqrt(n) + 1;

    int l, r;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        queries.pb(query(l - 1, r - 1, i));
    }

    sort(queries.begin(), queries.end(), comparator);


    int prevl, prevr;
    distinct = 0;

    prevl = queries[0].l;
    prevr = queries[0].r;

    for (int i = prevl; i <= prevr; i++)
        Add(arr[i]);

    ans[queries[0].q] = distinct;

    for (int i = 1; i < q; i++)
    {
        adjust(prevl, prevr, queries[i], arr);
        ans[queries[i].q] = distinct;
    }

    for (int x : ans) cout << x << endl;
    cout << endl;

}





