#include <iostream>
#include <unordered_set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
long long helper(vector<int> &nums, vector<int> &cost, int mid)
{
    long long sum = 0LL;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += 1L * abs(nums[i] - mid) * cost[i];
    }
    return sum;
}
long long minCost(vector<int> &nums, vector<int> &cost)
{
    int l = nums[0], r = nums[0];
    for (int i : nums)
    {
        l = min(l, i);
        r = max(r, i);
    }
    long ans = 0;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        long long c1 = helper(nums, cost, mid);
        long long c2 = helper(nums, cost, mid + 1);
        if (c1 > c2)
        {
            l = mid + 1;
            ans = c2;
        }
        else
        {
            r = mid - 1;
            ans = c1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums{1, 3, 5, 2}, cost{2, 3, 1, 14};
    minCost(nums, cost);
}