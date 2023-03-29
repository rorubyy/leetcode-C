#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    unordered_set<int> daysOrder;
    int dayLen = days.size(), lastDay = days[dayLen - 1];
    vector<int> dp(lastDay + 1, 0);
    for (auto day : days)
    {
        daysOrder.insert(day);
    }
    for (int i = 1; i <= lastDay; i++)
    {
        if (daysOrder.find(i) == daysOrder.end())
            dp[i] = dp[i - 1];
        else
            dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0,i - 7)] + costs[1], dp[max(0,i - 30)] + costs[2]));
    }

    return dp[lastDay];
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {7, 2, 15};
    mincostTickets(days, costs);
    return 0;
}
