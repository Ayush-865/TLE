#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; i++)
    {
        int val1 = arr[i] % x;
        int val2 = arr[i] % y;
        int req1 = (x - val1) % x;
        int req2 = val2;
        count += mp[{req1, req2}];
        mp[{val1, val2}]++;
    }

    cout << count << endl;
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