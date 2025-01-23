#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> steps(n + 1);
    vector<int> prefix_steps(n + 1, 0);
    vector<int> maxi(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> steps[i];
        prefix_steps[i] = prefix_steps[i - 1] + steps[i];
        maxi[i] = max(maxi[i - 1], steps[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int index = upper_bound(maxi.begin(), maxi.end(), x) - maxi.begin();

        if (index > n)
            cout << prefix_steps[n] << " ";
        else
            cout << prefix_steps[index - 1] << " ";
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