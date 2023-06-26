#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;
long long totalCost(vector<int> &costs, int k, int candidates)
{
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq_l, pq_r;
    int cnt = 0, l = 0, r = costs.size() - 1;
    while (cnt < candidates)
    {
        while (pq_l.size() < candidates && l <= r)
            pq_l.push(costs[l++]);
        while (pq_r.size() < candidates && r >= l)
            pq_r.push(costs[r--]);
        int cost1 = pq_l.size() > 0 ? pq_l.top() : INT_MAX;
        int cost2 = pq_r.size() > 0 ? pq_r.top() : INT_MAX;

        if (cost1 <= cost2)
        {
            ans += cost1;
            pq_l.pop();
        }
        else
        {
            ans += cost2;
            pq_r.pop();
        }
        cnt++;
    }
    return ans;
}
int main()
{
    vector<int> costs{25, 65, 41, 31, 14, 20, 59, 42, 43, 57, 73, 45, 30, 77, 17, 38, 20, 11, 17, 65, 55, 85, 74, 32, 84};
    int k = 24, candidates = 8;
    totalCost(costs, k, candidates);
}