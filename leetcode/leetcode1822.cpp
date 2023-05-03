#include <iostream>
using namespace std;

int arraySign(vector<int> &nums)
{
    double product = 1;
    for (auto n : nums)
    {
        product *= n;
        if (n == 0)
            return 0;
    }
    int ans = 0;
    product > 0 ? ans = 1 : ans = -1;
    return ans;
}
int main()
{
    vector<int> nums{-1, -2, -3, -4, 3, 2, 1};
    arraySign(nums);
}