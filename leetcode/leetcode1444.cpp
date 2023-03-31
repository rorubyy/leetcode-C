#include <iostream>
#include <vector>
using namespace std;
int dfs(int row, int col, int k, int r, int c, vector<vector<vector<int>>> &dp, vector<vector<int>> &presum)
{
    int ans = 0;
    if (presum[r][c] == 0)
        return 0;
    if (k == 0)
        return 1;
    if (dp[k][r][c] != -1)
        return dp[k][r][c];
    for (int h = r + 1; h < row; h++) // horizontal cut
    {
        if (presum[r][c] - presum[h][c] > 0) // a piece of pizza need to be greater than one apple
            ans = (ans + dfs(row, col, k - 1, h, c, dp, presum)) % 1000000007;
    }
    for (int v = c + 1; v < col; v++) // vertical cut
    {
        if (presum[r][c] - presum[r][v] > 0)
            ans = (ans + dfs(row, col, k - 1, r, v, dp, presum)) % 1000000007;
    }
    return dp[k][r][c] = ans;
}
int ways(vector<string> &pizza, int k)
{
    int row = pizza.size(), col = pizza[0].size();
    vector<vector<int>> presum(vector(row + 1, vector(col + 1, 0)));
    vector<vector<vector<int>>> dp(vector(k, vector(row, vector(col, -1))));
    for (int r = row - 1; r >= 0; r--)
    {
        for (int c = col - 1; c >= 0; c--)
        {
            presum[r][c] = presum[r + 1][c] + presum[r][c + 1] - presum[r + 1][c + 1] + (pizza[r][c] == 'A');
        }
    }
    return dfs(row, col, k - 1, 0, 0, dp, presum);
}
int main()
{
    vector<string> pizza{"A..", "AAA", "..."};
    int k = 3;
    ways(pizza, k);
}
