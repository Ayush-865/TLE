#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divisors.push_back(i);

    for (auto divisor : divisors)
    {

        for (int i = 0; i < divisor; i++)
        {
        }
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