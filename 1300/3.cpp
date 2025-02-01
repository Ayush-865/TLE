#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2)
            a[i] = -a[i];
        else
            a[i] = a[i];
    }

    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        mp[prefix[i]]++;
        if (mp[prefix[i]] > 1)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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