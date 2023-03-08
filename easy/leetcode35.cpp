#include <iostream>
#include <vector>

using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    searchInsert(nums, target);
    return 0;
}