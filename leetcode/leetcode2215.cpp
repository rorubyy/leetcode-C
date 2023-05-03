#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
    vector<vector<int>> ans(2);
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ans[0], ans[0].end()));
    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(ans[1], ans[1].end()));
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4, 6};
    findDifference(nums1, nums2);
}