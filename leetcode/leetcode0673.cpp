#include <iostream>
#include <vector>
using namespace std;
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxLen = 1, result = 0;
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    count[i] += count[j];
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
            result += count[i];
    }
    return result;
}
int main()
{
    vector<int> nums{1, 3, 5, 4, 7};
    findNumberOfLIS(nums);
}