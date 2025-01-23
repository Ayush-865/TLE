#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define pb push_back
#define mp make_pair

ll sum(ll a)
{
    return (a * (a + 1)) / 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll lcm = (x * y) / __gcd(x, y);
        ll a = n / x - n / lcm;
        ll b = n / y - n / lcm;
        cout << (sum(n) - sum(n - a)) - (sum(b)) << endl;
    }
    return 0;
}