#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define pb push_back
#define mp make_pair

const int mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n;
        r = (n * (n - 1)) / 2;
        vll a(r);
        f(i, 0, r)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll k = 1, ptr = 0;
        f(i, 0, n - 1)
        {
            ll mini = INT_MAX;
            ptr += n - k;
            k++;
            cout << a[ptr - 1] << " ";
        }
        cout << mod - 7 << endl;
    }
    return 0;
}