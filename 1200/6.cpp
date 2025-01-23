#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define pb push_back
#define mp make_pair

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, b, state = 0, count = 0;
        cin >> n;
        vector<ll> v;
        f(i, 0, n)
        {
            cin >> b;
            v.pb(b);
        }
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        f(i, 1, n)
        {
            if ((v[i - 1] > v[i]) && state != 1)
            {
                count++;
                state = 1;
            }
            else if ((v[i - 1] < v[i]) && state != -1)
            {
                count++;
                state = -1;
            }
        }
        cout << count + 1 << "\n";
    }
    return 0;
}