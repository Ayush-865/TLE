#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> freqMap;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        freqMap[v[i]]++;
    }

    int kFreq = freqMap[k];

    // First, check if k is already most frequent
    bool alreadyMax = true;
    for (auto l : freqMap)
    {
        int num = l.first;
        int freq = l.second;
        if (freq > kFreq)
        {
            alreadyMax = false;
            break;
        }
    }
    if (alreadyMax)
    {
        cout << "0\n";
        return;
    }

    // Find positions where k appears
    vector<int> kPos;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == k)
            kPos.push_back(i);
    }

    int ans = n; // Maximum possible operations

    // For each consecutive sequence of k's, try to make it most frequent
    for (int i = 0; i < kPos.size(); i++)
    {
        // Try sequences starting at position i
        int currK = 0; // count of k in current window
        map<int, int> windowFreq;

        for (int j = i; j < kPos.size(); j++)
        {
            // For each end position j
            int left = kPos[i];  // leftmost position of k
            int right = kPos[j]; // rightmost position of k

            currK = j - i + 1; // number of k's we're keeping

            // Count frequencies between left and right
            windowFreq.clear();
            int maxOtherFreq = 0;
            for (int pos = left; pos <= right; pos++)
            {
                windowFreq[v[pos]]++;
                if (v[pos] != k)
                {
                    maxOtherFreq = max(maxOtherFreq, windowFreq[v[pos]]);
                }
            }

            // If k is most frequent in this window
            if (currK > maxOtherFreq)
            {
                int operations = 0;
                if (left > 0)
                    operations++; // need to remove prefix
                if (right < n - 1)
                    operations++; // need to remove suffix
                ans = min(ans, operations);
            }
        }
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