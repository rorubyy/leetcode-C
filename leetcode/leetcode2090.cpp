#include <iostream>
#include <vector>
using namespace std;
vector<int> getAverages(vector<int> &nums, int k)
{
    int pre = 0, n = nums.size();
    long long sum = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i < k || i >= n - k)
        {
            if (i < k)
                sum += nums[i];
            ans.push_back(-1);
        }
        else
        {
            if (i == k)
            {
                for (int j = i; j < 2 * k + 1; j++)
                {
                    sum += nums[j];
                }
            }
            else
            {
                sum = sum - nums[pre++] + nums[i + k];
            }
            ans.push_back(sum / (k * 2 + 1));
        }
    }
    return ans;
}
int main()
{
    vector<int> nums{7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    getAverages(nums, k);
}