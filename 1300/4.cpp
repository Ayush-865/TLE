#include <bits/stdc++.h>
using namespace std;

#define int long long

void getPrimeFactors(int n, map<int, int> &mp)
{
    while (n % 2 == 0)
    {
        mp[2]++;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 2)
        mp[n]++;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int &i : a)
    {
        cin >> i;
        getPrimeFactors(i, mp);
    }
    for (auto i : mp)
    {
        if (i.second % n)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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