#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, set<int>> mp;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mp[a[i]].insert(i);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) 
        if((sum-a[i])%2==0 
        && mp.find((sum-a[i])/2)!=mp.end() 
        && (mp[(sum-a[i])/2].find(i)==mp[(sum-a[i])/2].end() || mp[(sum-a[i])/2].size()>1) )
            ans.push_back(i+1);


    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}


int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
}