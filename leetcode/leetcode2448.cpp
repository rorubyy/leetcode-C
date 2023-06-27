#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

long long minCost(vector<int> &nums, vector<int> &cost)
{
    unordered_set<int> set;
    long long minCost = INT_MAX, nowCost = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (set.find(nums[i]) != set.end())
        {
            continue;
        }
        set.insert(nums[i]);
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
                continue;
            nowCost = nowCost + (abs(nums[j] - nums[i])) * cost[j];
        }
        minCost = min(minCost, nowCost);
        nowCost = 0;
    }
    return minCost;
}

int main()
{
    vector<int> nums{1, 3, 5, 2}, cost{2, 3, 1, 14};
    minCost(nums, cost);
}