#include <iostream>
#include <vector>

using namespace std;
int numberOfSubarrays(vector<int> &nums, int k)
{
    int j = 0, oddCnt = 0, cnt = 0, total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & 1)
        {
            oddCnt++;
            if (oddCnt >= k)
            {
                cnt = 1;
                while (!(nums[j++] & 1))
                    cnt++;
                total += cnt;
            }
        }
        else if (oddCnt >= k)
        {
            total += cnt;
        }
    }
    return total;
}

int main()
{
    vector<int> nums{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    numberOfSubarrays(nums, k);
}