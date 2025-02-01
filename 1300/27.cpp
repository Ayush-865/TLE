#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans=INT_MIN, start=0, end=n-1;

    while(start<=end){
        int mid=(start+end)/2;
        vector<int> b(a.begin(), a.begin()+mid+1);
        sort(b.begin(), b.end());
        int size=0;
        if(b.size()%2==0){
            for(int i=0; i<b.size(); i+=2){
                size+=max(b[i], b[i+1]);
            }
        }
        else{
            int max1=0, max2=0;
            for(int i=0; i<b.size(); i+=2){
                max1+=max(b[i], b[i+1]);
            }
            max1+=b[b.size()-1];
            for(int i=1; i<b.size(); i+=2){
                max2+=max(b[i], b[i+1]);
            }
            max2+=b[0];
            size=min(max1, max2);
        }
        if(size<=h){
            ans=mid+1;
            start=mid+1;
        }
        else
            end=mid-1;
    }
    cout << ans << endl;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
}