#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> st, lazy;

void build(int node, int start, int end, vector<int> &nums)
{
    if (start == end)
    {
        st[node] = nums[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node + 1, start, mid, nums);
    build(2 * node + 2, mid + 1, end, nums);
    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

void propagate(int node, int start, int end)
{
    if (lazy[node] == 0)
        return;

    // Apply lazy value to current node
    st[node] += lazy[node] * (end - start + 1);

    // Propagate lazy value to children
    if (start != end)
    {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
}

void point_update(int node, int start, int end, int index, int value)
{
    propagate(node, start, end);
    if (start == end)
    {
        st[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index <= mid)
        point_update(2 * node + 1, start, mid, index, value);
    else
        point_update(2 * node + 2, mid + 1, end, index, value);
    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int update_range(int node, int start, int end, int l, int r, int value)
{
    propagate(node, start, end);

    if (start > r || end < l)
        return st[node];

    if (start >= l && end <= r)
    {
        lazy[node] += value;
        propagate(node, start, end);
        return st[node];
    }

    int mid = (start + end) / 2;
    return st[node] = update_range(2 * node + 1, start, mid, l, r, value) +
                      update_range(2 * node + 2, mid + 1, end, l, r, value);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    st.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    build(0, 0, n - 1, nums);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            update_range(0, 0, n - 1, i - 1, i - 1, x);
            cout << st[0] << endl;
        }
        else
        {
            int x;
            cin >> x;
            update_range(0, 0, n - 1, 0, n - 1, x);
            cout << st[0] << endl;
        }
    }
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
