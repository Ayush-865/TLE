#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    
    vector<pair<int, int>> prefix_max(n);
    prefix_max[0] = {a[0], 0};
    for (int i = 1; i < n; i++)
    {
        if (a[i] > prefix_max[i - 1].first)
            prefix_max[i] = {a[i], i};
        else
            prefix_max[i] = prefix_max[i - 1];
    }
    vector<int> dp(n);
    dp[0] = a[0];
    for (int i = 0; i < n-k+1; i++){
        dp[i]=dp[i-1]+prefix_max[i+k-1].first;
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