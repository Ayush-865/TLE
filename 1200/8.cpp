#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define pb push_back
#define mp make_pair

pair<ll, ll> minMax(vll v, ll left, ll right)
{
    ll n = v.size();
    ll min = INT_MAX, max = INT_MIN;
    ll a = -1, b = -1;
    f(i, left, right + 1)
    {
        if (v[i] < min)
        {
            min = v[i];
            a = i;
        }
        if (v[i] > max)
        {
            max = v[i];
            b = i;
        }
    }
    return mp(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        f(i, 0, n)
        {
            cin >> v[i];
        }
        ll left = 0, right = n - 1;
        bool flag = false;
        while (left < right)
        {
            pair<ll, ll> p = minMax(v, left, right);
            if (p.first != left && p.first != right && p.second != left && p.second != right)
            {
                flag = true;
                break;
            }
            if (p.first == left || p.second == left)
                left++;
            if (p.first == right || p.second == right)
                right--;
        }
        if (flag)
        {
            cout << left + 1 << " " << right + 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}