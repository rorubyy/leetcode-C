#include <iostream>
#include <vector>

using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int numsLen = nums.size(), index = 0;
    while (index < numsLen - 1)
    {
        int first = index, second = index + 1;
        if (nums[first] == nums[second])
        {
            index += 2;
            continue;
        }
        return nums[index];
    }
    return nums[index];
}
int main()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    singleNonDuplicate(nums);
    return 0;
}