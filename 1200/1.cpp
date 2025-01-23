#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define pb push_back
#define mp make_pair

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, maxi = 0;
        cin >> n;
        vll a(n), b(n), c(n);
        vector<pair<ll, ll>> va, vb, vc;
        f(i, 0, n)
        {
            cin >> a[i];
            va.pb(mp(a[i], i));
        }
        f(i, 0, n)
        {
            cin >> b[i];
            vb.pb(mp(b[i], i));
        }
        f(i, 0, n)
        {
            cin >> c[i];
            vc.pb(mp(c[i], i));
        }

        sort(va.begin(), va.end(), std::greater<>());
        sort(vb.begin(), vb.end(), std::greater<>());
        sort(vc.begin(), vc.end(), std::greater<>());

        f(i, 0, 3)
        {
            f(j, 0, 3)
            {
                f(k, 0, 3)
                {
                    if (va[i].second != vb[j].second && vb[j].second != vc[k].second && va[i].second != vc[k].second)
                    {
                        maxi = max(va[i].first + vb[j].first + vc[k].first, maxi);
                    }
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}