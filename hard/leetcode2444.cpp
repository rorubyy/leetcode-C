#include <vector>
#include <iostream>

using namespace std;
long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    int nLen = nums.size(), minPos = -1, maxPos = -1, leftBound = -1;
    long long count = 0;
    for (int i = 0; i < nLen; i++)
    {
        if (nums[i] >= minK && nums[i] <= maxK)
        {
            minPos = nums[i] == minK ? i : minPos;
            maxPos = nums[i] == maxK ? i : maxPos;
            count += max(0, min(minPos, maxPos) - leftBound);
        }
        else
        {
            minPos = -1;
            maxPos = -1;
            leftBound = i;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {3, 5, 7, 1, 5, 3, 1, 5, 7};
    int minK = 1, maxK = 5;
    countSubarrays(nums, minK, maxK);
}