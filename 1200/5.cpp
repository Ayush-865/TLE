#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(k + 1);
    for (int i = 1; i <= k; i++)
        arr[i].push_back(0);

    for (int i = 1; i <= n; i++)
    {
        int color;
        cin >> color;
        arr[color].push_back(i);
    }

    for (int i = 1; i <= k; i++)
        arr[i].push_back(n + 1);

    int ans = n + 1;
    for (int i = 1; i <= k; i++)
    {
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int j = 1; j < arr[i].size(); j++)
        {
            int diff = arr[i][j] - arr[i][j - 1] - 1;
            if (diff > max1)
            {
                max2 = max1;
                max1 = diff;
            }
            else if (diff > max2)
                max2 = diff;
        }
        ans = min(ans, max(max2, max1 / 2));
    }
    cout << ans << endl;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;
    while (t--)
        solve();
}