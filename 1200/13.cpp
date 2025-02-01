#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> groups;
    vector<int> infected(m);
    for (int i = 0; i < m; i++)
        cin >> infected[i];
    sort(infected.begin(), infected.end());

    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
            groups.push_back((n - infected[i]) + (infected[0] - 1));
        else
            groups.push_back(infected[i + 1] - infected[i] - 1);
    }
    sort(groups.rbegin(), groups.rend());

    int days = 0;
    int saved = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        int remaining_people = groups[i] - days * 2;
        if (remaining_people - 1 > 0)
            saved += remaining_people - 1;
        else if (remaining_people == 1)
            saved += remaining_people;
        else
            break;
        days += 2;
    }
    cout << n - saved << endl;
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