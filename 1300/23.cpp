#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int>> findFactors(int n)
{
    vector<pair<int, int>> factors;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            int a = i;
            int b = n / i;
            factors.push_back({a, b});
        }
    }
    return factors;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> factors = findFactors(n);
    for (auto factor : factors)
    {
        vector<pair<int, int>> factorsA = findFactors(factor.first);
        vector<pair<int, int>> factorsB = findFactors(factor.second);
        for (auto factorA : factorsA)
        {
            if (factorA.first != factorA.second && factorA.first != factor.second && factorA.second != factor.second)
            {
                cout << "YES" << endl;
                cout << factorA.first << " " << factorA.second << " " << factor.second << endl;
                return;
            }
        }
        for (auto factorB : factorsB)
        {
            if (factorB.first != factorB.second && factorB.first != factor.first && factorB.second != factor.first)
            {
                cout << "YES" << endl;
                cout << factorB.first << " " << factorB.second << " " << factor.first << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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