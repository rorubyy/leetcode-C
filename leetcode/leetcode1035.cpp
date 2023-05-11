#include <iostream>
#include <vector>
using namespace std;
int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, 0));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (nums1[i] == nums2[j])
                (i == 0 || j == 0) ? dp[i][j] = 1 : dp[i][j] = 1 + dp[i - 1][j - 1];
            if (i > 0)
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            if (j > 0)
                dp[i][j] = max(dp[i][j - 1], dp[i][j]);
        }
    }
    return dp[n1 - 1][n2 - 1];
}
int main()
{
    vector<int> nums1 = {1, 4, 2}, nums2 = {1, 2, 4};
    maxUncrossedLines(nums1, nums2);
}