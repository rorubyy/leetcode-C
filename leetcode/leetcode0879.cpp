#include <iostream>
#include <vector>
using namespace std;
int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    int crimeLen = group.size();
    vector<vector<vector<int>>> dp(crimeLen + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
    dp[0][0][0] = 1;
    int MOD = 1e9 + 7;

    for (int i = 1; i <= crimeLen; i++)
    {
        int g = group[i - 1], p = profit[i - 1];
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= minProfit; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k] + (j >= g ? dp[i - 1][j - g][max(0, k - p)] : 0);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= n; j++)
    {
        ans = (ans + dp[crimeLen][j][minProfit]) % MOD;
    }

    return 1;
}
int main()
{
    int n = 5, minProfit = 3;
    vector<int> group{2, 2}, profit{2, 3};
    profitableSchemes(n, minProfit, group, profit);
}