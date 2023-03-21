#include <iostream>
#include <vector>

using namespace std;
long long zeroFilledSubarray(vector<int> &nums)
{
    long long output = 0, contiguousZero = 0;
    for (int i = 0; i <= nums.size(); i++)
    {
        if (i < nums.size() && nums[i] == 0)
        {
            contiguousZero++;
            continue;
        }
        output += (1 + contiguousZero) * contiguousZero / 2;
        contiguousZero = 0;
    }
    return output;
}
int main()
{
    vector<int> nums{0, 0, 0, 2, 0, 0};
    zeroFilledSubarray(nums);
    return 0;
}