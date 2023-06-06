#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    int n = l.size();
    vector<bool> querys;
    for (int i = 0; i < n; i++)
    {
        int left = l[i], right = r[i];
        bool flag = false;
        auto first = nums.begin() + left, last = nums.begin() + right + 1;
        vector<int> temp(first, last);
        sort(temp.begin(), temp.end());
        int dif = temp[1] - temp[0];
        for (int j = 2; j < temp.size(); j++)
        {
            if (temp[j] - temp[j - 1] != dif)
            {
                flag = true;
                querys.push_back(false);
                break;
            }
        }
        if (flag == false)
            querys.push_back(true);
    }
    return querys;
}
int main()
{
    vector<int> nums{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
    vector<int> l{0, 1, 6, 4, 8, 7}, r{4, 4, 9, 7, 9, 10};
    checkArithmeticSubarrays(nums, l, r);
}