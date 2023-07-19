#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int longestSubsequence(vector<int> &arr, int difference)
{
    // dp
    int n = arr.size();
    vector<int> dp(n, 0);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i] - difference) != mp.end())
        {
            dp[i] = 1 + dp[mp[arr[i] - difference]];
        }
        else
        {
            dp[i] = 1;
        }
        mp[arr[i]] = i;
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<int> arr{1, 5, 7, 8, 5, 3, 4, 2, 1, 7};
    int difference = -2;
    longestSubsequence(arr, difference);
}