#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#define pb push_back
#define N (lli)(3e5)
#define lli long long int 
#define mod (lli)(1e9 + 7)
#define INF lli_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define pb push_back
using namespace std;

int main()
{
    lli tes;
    cin >> tes;
    while (tes--)
    {
        lli n, p, k;
        lli cost = 0;
        cin >> n >> p;
        k = n - 1;

        vector<bool> self(n + 1, true);

        vector<lli> arr(n + 1);
        vector<pair<lli, lli> > forSort;
        for (lli i = 1; i <= n; i++)
        {
            cin >> arr[i];
            forSort.pb(make_pair(arr[i], i));
        }

        sort(forSort.begin(), forSort.end());

        for (lli i = 0; i < n; i++)
        {
            lli ix = forSort[i].second;

            if (!self[ix] or arr[ix] > p)
                continue;
            lli l, r;
            l = ix - 1;
            r = ix + 1;



            while (l > 0)
            {
                if (arr[l] % arr[ix] != 0)
                    break;
                else
                {
                    if (self[l])
                    {
                        self[l] = false;
                        cost += arr[ix];
                        k--;
                        l--;
                    }
                    else
                    {
                        cost += arr[ix];
                        k--;
                        break;
                    }
                }
            }


            while (r <= n)
            {
                if (arr[r] % arr[ix] != 0)
                    break;
                else
                {
                    if (self[r])
                    {
                        self[r] = false;
                        cost += arr[ix];
                        k--;
                        r++;
                    }
                    else
                    {
                        cost += arr[ix];
                        k--;
                        break;
                    }
                }
            }

        }

        // cout<<k<<endl;

        cost += p*k;
        cout<<cost<<endl;


    }
}
