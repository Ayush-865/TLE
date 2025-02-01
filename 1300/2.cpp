#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pre[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
        pre[i] = (a[i] == a[i + 1] ? pre[i + 1] : i + 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (pre[l] > r)
            cout << -1 << " " << -1 << '\n';
        else
            cout << l + 1 << " " << pre[l] + 1 << '\n';
    }
    cout << endl;
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