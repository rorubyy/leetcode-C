#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    vector<vector<int>> pairs(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        pairs[i][0] = nums2[i];
        pairs[i][1] = nums1[i];
    }
    sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
         { return b[0] < a[0]; });

        priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0, res = 0;
    for (const vector<int> &pair : pairs)
    {
        sum += pair[1];
        pq.push(pair[1]);
        if (pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k)
        {
            res = max(res, sum * pair[0]);
        }
    }
    return res;
}
int main()
{
    vector<int> nums1{1, 3, 3, 2}, nums2{2, 1, 3, 4};
    int k = 3;
    maxScore(nums1, nums2, k);
}