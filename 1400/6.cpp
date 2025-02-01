#include <bits/stdc++.h>
using namespace std;

#define int long long

class ST{
    private:
        vector<int> st;
    public:
    void build(int node, int left, int right, vector<int> &a){
        if(left == right){
            st[node] = a[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2*node+1, left, mid, a);
        build(2*node+2, mid+1, right, a);
        st[node] = st[2*node+1] & st[2*node+2];
    }

    int query(int node, int left, int right, int l, int r){
        if(l > right || r < left)
            return (1U << 32) - 1;
        if(l <= left && r >= right)
            return st[node];
        int mid = (left + right) / 2;
        return query(2*node+1, left, mid, l, r) & query(2*node+2, mid+1, right, l, r);
    }

    ST(vector<int> &a){
        int n = a.size();
        st.resize(4*n);
        build(0, 0, n-1, a);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    ST st(a);

    int q;
    cin >> q;
    while (q--)
    {
        int l, k;
        cin >> l >> k;
        l;
        
        int ans = -1;
        int low = l-1, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (st.query(0, 0, n-1, l-1, mid) >= k)
            {
                ans = mid+1;
                low=mid+1;
            }
            else
                high = mid-1;
        }
        if (ans == -1)
            cout << -1 << " ";
        else
            cout << ans << " ";
    }
    cout << endl;
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