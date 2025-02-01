#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353

void solve()
{
    string s;
    cin >> s;
    int operations = 0;
    int combinations = 1;
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            operations += count;
            count++;
            if (count > 1)
                combinations = (combinations * (count * (count - 1)) % MOD) % MOD;
            count = 0;
        }
    }
    operations += count;
    count++;
    if (count > 1)
        combinations = (combinations * (count * (count - 1)) % MOD) % MOD;
    cout << operations << " " << combinations << endl;
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