#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> output;
    int n = nums.size();
    if (n == 0)
        return output;

    int start = nums[0], end;
    string s;

    for (int i = 1; i <= n; i++)
    {
        if (i == n || nums[i] != nums[i - 1] + 1)
        {
            end = nums[i - 1];
            start == end ? s = to_string(start) : s = to_string(start) + "->" + to_string(end);
            output.push_back(s);
            i == n ? start = -1 : start = nums[i];
        }
    }
    return output;
}
int main()
{
    vector<int> nums{0, 1, 2, 4, 5, 7};
    summaryRanges(nums);
}