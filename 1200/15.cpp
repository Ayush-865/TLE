#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n + 1);
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    prefix[1] = nums[1];
    for (int i = 2; i <= n; i++)
        prefix[i] = prefix[i - 1] + nums[i];

    int ans = INT_MAX;
    int i = 1, j = n;
    while (i <= j)
    {
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            if (prefix[j] - prefix[i - 1] == x)
            {
                ans = min(ans, (n - j) + (i - 1));
                break;
            }
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
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