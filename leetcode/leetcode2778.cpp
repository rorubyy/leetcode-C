#include <iostream>
#include <vector>

using namespace std;

int sumOfSquares(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    vector<int> division;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            ans += nums[i - 1] * nums[i - 1];
    }
    return ans;
}

int main()
{
    vector<int> nums{2, 7, 1, 19, 18, 3};
    sumOfSquares(nums);
}