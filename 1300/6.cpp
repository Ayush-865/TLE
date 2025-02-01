#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, vector<int>, greater<int>> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        mp[a[i] - b[i]].push_back(i);

    cout << mp.begin()->second.size() << endl;
    for (auto i : mp.begin()->second)
        cout << i + 1 << " ";
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