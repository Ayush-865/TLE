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
        ll n, res = 2;
        cin >> n;
        vll arr(n);
        f(i, 0, n)
        {
            cin >> arr[i];
        }
        while (1)
        {
            set<ll> remainder;
            f(i, 0, n)
            {
                remainder.insert(arr[i] % res);
            }
            if (remainder.size() == 2)
                break;
            res *= 2;
        }
        cout << res << endl;
    }
    return 0;
}