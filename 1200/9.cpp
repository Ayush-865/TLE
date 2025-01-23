#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    map<int, int> dolls;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        dolls[a]++;
    }
    int prev_doll_size = -1;
    int prev_doll_freq = 0;
    int total_doll_set = 0;
    for (auto it = dolls.begin(); it != dolls.end(); ++it)
    {
        if (prev_doll_size + 1 == it->first)
        {
            if (prev_doll_freq < it->second)
                total_doll_set += it->second - prev_doll_freq;
        }
        else
        {
            total_doll_set += it->second;
        }
        prev_doll_size = it->first;
        prev_doll_freq = it->second;
    }
    cout << total_doll_set << endl;
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