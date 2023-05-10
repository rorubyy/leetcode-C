#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (nums[m] == target)
            return m;
        else if (nums[m] > target) // move to left
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    vector<int> nums{-1};
    int target = 2;
    search(nums, target);
}