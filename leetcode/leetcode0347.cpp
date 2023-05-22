#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    vector<pair<int, int>> vec;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto i : mp)
    {
        pq.push(make_pair(i.second, i.first));
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 3, 3};
    int k = 2;
    topKFrequent(nums, k);
}