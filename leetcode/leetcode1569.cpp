#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;
long long binomialCoefficient(int n, int k)
{
    const int MOD = 1e9 + 7;

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= min(i, k); j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    return dp[n][k];
}
int countBST(vector<int> &nums)
{
    if (nums.size() <= 2)
        return 1;

    vector<int> left, right;
    int root = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < root)
            left.push_back(nums[i]);
        else
            right.push_back(nums[i]);
    }

    long long l = countBST(left);
    long long r = countBST(right);

    // Calculate the number of combinations using the Catalan number formula
    long long tc = binomialCoefficient(left.size() + right.size(), left.size());

    return (l * r % 1000000007 * tc % 1000000007);
}


int numOfWays(vector<int> &nums)
{
    const int MOD = 1e9 + 7;
    return (countBST(nums) - 1 + MOD) % MOD;
}

int main()
{
    vector<int> nums{3, 4, 5, 1, 2};
    numOfWays(nums);
}