#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    // dp maintain a vector save every point with sublen
    int n = nums.size(), sum = 0, i = 0;
    int ans = INT8_MAX;
    for (int j = 0; j < n; j++)
    {
        sum += nums[j];
        while (sum >= target && j < n)
        {
            ans = min(ans, j - i + 1);
            sum -= nums[i];
            i++;
        }
    }
    return ans == INT8_MAX ? 0 : ans;
}
int main()
{
    int target = 11;
    vector<int> nums{1, 2, 3, 4, 5};
    minSubArrayLen(target, nums);
}
