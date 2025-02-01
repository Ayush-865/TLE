#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int odds = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
            odds++;
    }
    if (y % 2)
    {
        if (x % 2)
            cout << (odds % 2 ? "Bob" : "Alice") << endl;
        else
            cout << (odds % 2 ? "Alice" : "Bob") << endl;
    }
    else
    {
        if (x % 2)
            cout << (odds % 2 ? "Alice" : "Bob") << endl;
        else
            cout << (odds % 2 ? "Bob" : "Alice") << endl;
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