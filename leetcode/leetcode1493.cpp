#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int n = nums.size(), cnt = 0;
    vector<int> one;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            i == 0 ? one.push_back(0) : one.push_back(cnt);
            cnt = 0;
        }
        else
        {
            cnt++;
            if (i == n - 1)
                one.push_back(cnt);
        }
    }
    int nO = one.size();
    if (nO == 1) //no zero
        return n - 1;
    int ans = 0;
    for (int i = 0; i < nO - 1; i++)
    {
        ans = max(ans, one[i + 1] + one[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums{1, 1, 1};
    longestSubarray(nums);
}