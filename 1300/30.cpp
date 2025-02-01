#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> prefix(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + nums[i];
    float ans = 0;

    if (n == k)
    {
        ans = (accumulate(nums.begin(), nums.end(), 0));
        cout << ans / k << endl;
        return;
    }
    else if (n <= 2 * k - 1)
    {
        
    }

    cout
        << ans << endl;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}