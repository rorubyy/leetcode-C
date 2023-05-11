#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{
    int head = 0, tail = nums.size() - 1;
    vector<int> ans;
    while (head <= tail)
    {
        int neg = pow(nums[head],2), pos = pow(nums[tail],2);
        if (neg > pos)
        {
            ans.insert(ans.begin(), neg);
            head++;
        }else{
            ans.insert(ans.begin(),pos);
            tail--;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    sortedSquares(nums);
}