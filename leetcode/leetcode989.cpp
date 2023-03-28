#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> addToArrayForm(vector<int> &num, int k)
{
    int quotient = k, remainder, numLen = num.size();
    vector<int> ans = num;
    int carry = 0, index = numLen - 1;
    for (int i = numLen - 1; i >= 0; i--)
    {
        remainder = quotient % 10;
        quotient = quotient / 10;
        ans[i] = (num[i] + remainder + carry) % 10;
        carry = (num[i] + remainder + carry) / 10;
    }
    while (quotient != 0)
    {
        remainder = quotient % 10;
        quotient = quotient / 10;
        ans.insert(ans.begin(), (remainder + carry) % 10);
        carry = (remainder + carry) / 10;
    }
    if (carry == 1)
    {
        ans.insert(ans.begin(), carry);
    }

    return ans;
}

int main()
{
    vector<int> nums = {9, 0};
    int k = 999;
    addToArrayForm(nums, k);
    return 0;
}