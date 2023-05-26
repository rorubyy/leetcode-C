#include <iostream>
#include <vector>

using namespace std;
int solver(int i, int M, vector<vector<int>> &dp, vector<int> &piles, vector<int> &suf)
{
    int n = piles.size();
    if (i == piles.size())
        return 0;
    if (dp[i][M] != 0)
        return dp[i][M];

    int sum = 0;
    for (int x = 1; x <= 2 * M; x++)
    {
        if (i + x - 1 >= n)
            break;
        sum += piles[i + x - 1];
        dp[i][M] = max(dp[i][M], sum + suf[i + x] - solver(i + x, max(x, M), dp, piles, suf));
    }
    return dp[i][M];
}

int stoneGameII(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> suf(n + 1);
    suf[n] = 0;

    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + piles[i];

    return solver(0, 1, dp, piles, suf);
}
int main()
{
    vector<int> piles{1, 2, 3, 4, 5, 100};
    stoneGameII(piles);
}