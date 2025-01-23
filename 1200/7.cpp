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
        int n, m, sum = 0;
        cin >> n >> m;
        vii v(n, vi(m));
        f(i, 0, n)
        {
            f(j, 0, m)
            {
                cin >> v[i][j];
            }
        }
        f(i, 0, n - 1)
        {
            f(j, i + 1, n)
            {
                int s = 0;
                f(k, 0, m)
                {
                    s += abs(v[i][k] - v[j][k]);
                }
                sum += s;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}