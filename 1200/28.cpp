#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int y = x % m;
        mp[y]++;
    }
    int total = 0;
    for (auto i : mp)
    {
        if (i.first == 0 && i.second > 0)
            total++;
        else if (mp.count(m - i.first) == 0)
            total += i.second;
        else if (m - i.first == i.first)
            total++;
        else if (m - i.first > i.first)
        {
            int a = i.second;
            int b = mp[m - i.first];
            if (abs(a - b) <= 1)
                total++;
            else if (a > b)
            {
                a -= (b + 1);
                total++;
                total += a;
            }
            else
            {
                b -= (a + 1);
                total++;
                total += b;
            }
        }
    }
    cout << total << "\n";
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