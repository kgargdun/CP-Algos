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

int query(vector<int>&decomposition, vector<int>&arr, int l , int r, int rn)
{
    int ans = 0;

    // left part
    while (l % rn != 0 and l <= r)
    {
        ans = ans + arr[l];
        l++;
    }

    // middle part
    while (l + rn <= r)
    {
        ans = ans + decomposition[l / rn];
        l = l + rn;
    }

    // right part
    while (l <= r)
    {
        ans = ans + arr[l];
        l++;
    }

    return ans;
}

void update(vector<int>&decomposition, vector<int>&arr, int toUpd, int updVal, int rn)
{
    int block_id = toUpd / rn;
    decomposition[block_id] += (updVal - arr[toUpd]);
    arr[toUpd] = updVal;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int>arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    int rn = sqrt(n) + 1;
    vector<int>decomposition(rn, 0);

    int k = -1;
    for (int i = 0; i < n; i++)
    {
        if (i % rn == 0) k++;
        decomposition[k] += arr[i];
    }


    for (int x : decomposition) cout << x << " ";
    cout << endl;

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 2) cout << query(decomposition, arr, l - 1, r - 1, rn);
        else update(decomposition, arr, l - 1, r, rn);
    }

}


