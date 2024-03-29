#include <iostream>
#include <vector>

using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (nums[m] == target)
            return m;
        else if (nums[m] > target)
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    searchInsert(nums, target);
    return 0;
}