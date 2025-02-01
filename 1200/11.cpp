#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> v1(n + 1), v2(n + 1);
    for (int i = 1; i <= n; i++) {
        v1[i] = s[i - 1] - '0'; // Convert binary string to numeric vector
        v2[i] = i;             // Store indices 1, 2, ..., n
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (v1[i] == 0) {
            sum += v2[i];       // Add cost for index i
            for (int j = i + i; j <= n; j += i) {
                if (v1[j] == 0) {
                    v1[j] = 2; // Mark as processed
                } else if (v1[j] == 1) {
                    break;     // Stop if a `1` is encountered
                }
            }
        }
    }
    cout << sum << endl;
}

int32_t main() {
    IO
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
