#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<int> prefix(n);
    prefix[0] = b[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + b[i];
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (prefix[n - 1] - prefix[i - 1] <= a[i])
            for (int j = i; j < n; j++)
                ans[j] = min(ans[j], a[i]);
        else
        {
            int
        }
    }
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