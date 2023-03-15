#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> &nums)
{
    int min_step = 0, numsLen = nums.size(), now = 0, prev = 0; // now: current index max distance , prev: previos index max distance
    for (int i = 0; i < numsLen - 1; i++)
    {
        now = max(now, i + nums[i]);
        if (prev == i)
        {
            min_step++;
            prev = now;
        }
    }
    return min_step;
}
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    jump(nums);
    return 0;
}