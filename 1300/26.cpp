#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin >> s;
    vector<pair<char, int>> arr;

    if (s.size() < 3)
    {
        cout << 0 << endl;
        return;
    }

    int count = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else if (s[i - 1] == 'v' && count == 1)
            continue;
        else
        {
            if (s[i - 1] == 'o')
                arr.push_back({'o', count});
            else
                arr.push_back({'v', count - 1});
            count = 1;
        }
    }
    if (s[s.size() - 1] == 'v' && count > 1)
        arr.push_back({'v', count - 1});

    vector<int> prefixV(arr.size()), suffixV(arr.size());
    prefixV[0] = arr[0].first == 'v' ? arr[0].second : 0;
    for (int i = 1; i < arr.size(); i++)
        prefixV[i] = prefixV[i - 1] + (arr[i].first == 'v' ? arr[i].second : 0);

    suffixV[arr.size() - 1] = arr[arr.size() - 1].first == 'v' ? arr[arr.size() - 1].second : 0;
    for (int i = arr.size() - 2; i >= 0; i--)
        suffixV[i] = suffixV[i + 1] + (arr[i].first == 'v' ? arr[i].second : 0);

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i].first == 'o')
            ans += prefixV[i] * suffixV[i] * arr[i].second;

    cout << ans << endl;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}