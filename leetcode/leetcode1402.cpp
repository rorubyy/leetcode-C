#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int maxSatisfaction(vector<int> &satisfaction)
{
    int dishLen = satisfaction.size();
    vector<int> dp(dishLen, 0);
    sort(satisfaction.rbegin(), satisfaction.rend()); // descending
    for (int i = 0; i < dishLen; i++)
    {
        int nowValue = 0;
        for (int j = i; j >= 0; j--)
        {
            nowValue += satisfaction[j] * (i - j + 1);
        }
        dp[i] = max(nowValue, dp[max(0, i - 1)]);
    }
    return dp[dishLen - 1];
}
int main()
{
    vector<int> satisfaction{-1, -8, 0, 5, -9};
    maxSatisfaction(satisfaction);
    return 0;
}