#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minIncrements(int n, vector<int> &cost)
{
    int ans = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int left = i * 2 + 1, right = i * 2 + 2;
        ans += abs(cost[left] - cost[right]);
        cost[i] += max(cost[left], cost[right]);
    }
    return ans;
}

int main()
{
    int n = 15;
    vector<int> cost{764, 1460, 2664, 764, 2725, 4556, 5305, 8829, 5064, 5929, 7660, 6321, 4830, 7055, 3761};
    minIncrements(n, cost);
}