#include <bits/stdc++.h>
using namespace std;

#define int long long

int maxSubarraySum(vector<int> &arr)
{
    int maxi = arr[0];
    int currSum = arr[0];
    int start = 0, end = 0;
    int maxLength = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (currSum + arr[i] > arr[i])
        {
            currSum = currSum + arr[i];
            end = i;
        }
        else
        {
            currSum = arr[i];
            start = i;
            end = i;
        }
        if (currSum > maxi)
        {
            maxi = currSum;
            maxLength = end - start + 1;
        }
    }
    return maxLength == arr.size() ? LLONG_MIN : maxi;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    cout << (sum > maxSubarraySum(nums) ? "YES" : "NO") << endl;
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