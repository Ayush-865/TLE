#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &i : a)
        cin >> i.second >> i.first;

    sort(a.begin(), a.end());

    int ans = 0;
    ordered_set st;

    for (auto p : a)
    {
        ans += st.size() - st.order_of_key(p.second);
        st.insert(p.second);
    }
    cout << ans << "\n";
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