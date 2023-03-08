#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int minimumDeviation(vector<int> &nums)
{
    int numsLen = nums.size();
    set<int> orderNums;

    for (int num : nums)
    {
        if (num % 2 == 1)
        {
            num *= 2;
        }
        orderNums.insert(num);
    }
    int deviation = INT32_MAX, tempDeviation = *orderNums.rbegin() - *orderNums.begin();
    while (*orderNums.rbegin() % 2 == 0)
    {
        int end = *orderNums.rbegin();
        orderNums.erase(end);
        orderNums.insert(end / 2);l
        
    }
    while (tempDeviation < deviation)
    {
        int end = *orderNums.rbegin(), begin = *orderNums.begin();
        if (end % 2 == 0)
        {
            int evenEnd = end / 2;
            if (evenEnd > *orderNums.begin())
            {
                orderNums.erase(end);
                orderNums.insert(evenEnd);
            }
        }
        if (begin % 2 == 1)
        {
            int oddBegin = begin * 2;
            if (oddBegin < *orderNums.rbegin())
            {
                orderNums.erase(orderNums.begin());
                orderNums.insert(oddBegin);
            }
        }
        deviation = tempDeviation;
        tempDeviation = *orderNums.rbegin() - *orderNums.begin();
    }
    return tempDeviation;
}
int main()
{
    vector<int> nums = {399, 908, 648, 357, 693, 502, 331, 649, 596, 698};
    minimumDeviation(nums);
    return 0;
}