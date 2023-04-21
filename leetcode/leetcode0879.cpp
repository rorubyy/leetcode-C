#include <iostream>
#include <vector>
using namespace std;
int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    int C = group.size(), MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp(C + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= C; i++)
    {
        int g = group[i - 1], p = profit[i - 1];
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= minProfit; k++)
            {
                dp[i][j][k] = (dp[i - 1][j][k] + (j >= g ? dp[i - 1][j - g][max(0, k - p)] : 0)) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = (ans + dp[C][i][minProfit]) % MOD;
    }
    return ans;
}
int main()
{
    int n = 5, minProfit = 3;
    vector<int> group{2, 2}, profit{2, 3};
    profitableSchemes(n, minProfit, group, profit);
}