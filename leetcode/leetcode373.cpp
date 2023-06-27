#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    int n1 = nums1.size(), n2 = nums2.size(), n;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (pq.size() >= k)
            {
                if (nums1[i] + nums2[j] < pq.top().first)
                    pq.pop();
                else
                    break;
            }
            pq.push(make_pair(nums1[i] + nums2[j], make_pair(nums1[i], nums2[j])));
        }
    }
    while (!pq.empty())
    {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }
    return ans;
}
int main()
{
    vector<int> nums1{1, 7, 11}, nums2{2, 4, 6};
    int k = 3;
    kSmallestPairs(nums1, nums2, k);
}