#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> entry(n), entryIndex(n + 1), entryVis(n + 1, 0);
    vector<int> exit(n);

    for (int i = 0; i < n; i++)
    {
        cin >> entry[i];
        entryIndex[entry[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> exit[i];
    }

    int ans = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (entryVis[i] == 1)
        {
            i++;
            continue;
        }
        if (entry[i] == exit[j])
        {
            i++;
            j++;
        }
        else
        {
            ans++;
            entryVis[entryIndex[exit[j]]] = 1;
            j++;
        }
    }
    cout << ans << endl;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}