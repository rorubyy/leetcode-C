#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int one = 0, two = 0;
    for (auto num : nums)
    {
        one = (one ^ num) & ~two;
        two = (two ^ num) & ~one;
    }
    return one;
}
int main()
{
    vector<int> nums{2, 2, 3, 2};
    singleNumber(nums);
}