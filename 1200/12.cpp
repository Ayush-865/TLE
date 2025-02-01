#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> expense(n);
    vector<int> money(n);
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
        cin >> expense[i];
    for (int i = 0; i < n; i++)
        cin >> money[i];
    for (int i = 0; i < n; i++)
        diff[i] = money[i] - expense[i];

    sort(diff.begin(), diff.end());
    int i = 0, j = n - 1;
    int days = 0;
    while (i < j)
    {
        if (diff[i] + diff[j] >= 0)
        {
            days++;
            i++;
            j--;
        }
        else
            i++;
    }
    cout << days << endl;
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