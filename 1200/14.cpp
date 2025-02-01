#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n); // Read the grid as strings for simplicity
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int total = 0; // Total number of flips needed

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            // Get the four symmetric cells
            char a = grid[i][j];
            char b = grid[j][n - i - 1];
            char c = grid[n - i - 1][n - j - 1];
            char d = grid[n - j - 1][i];

            // Count 0s and 1s in the group
            int count1 = (a == '1') + (b == '1') + (c == '1') + (d == '1');
            int count0 = 4 - count1;

            // Add the minimum flips needed
            total += min(count1, count0);
        }
    }

    cout << total << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
