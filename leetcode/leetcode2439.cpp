#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minimizeArrayValue(vector<int> &nums)
{
    long long sum = 0, result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        result = max(result, (sum + i) / (i + 1));
    }
    return int(result);
}
int main()
{
    vector<int> nums{3, 7, 1, 6};
    minimizeArrayValue(nums);
}