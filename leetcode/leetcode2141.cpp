
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;
bool canRun(vector<int> &batteries, long long minutes, int n)
{
    // lack
    long long lack = 0;

    for (int i = 0; i < n; i++)
    {
        if (batteries[i] < minutes)
            lack += minutes - batteries[i];
    }
    for (int i = n; i < batteries.size(); i++)
    {
        lack -= batteries[i];
        if (lack <= 0)
            return true;
    }
    return lack <= 0;
}

long long maxRunTime(int n, vector<int> &batteries)
{
    sort(batteries.begin(), batteries.end(), greater<int>());
    long long left = 0, right = 0;
    for (auto b : batteries)
    {
        right += b;
    }
    right /= n;
    while (left < right)
    {
        long long mid = (left + right + 1) / 2;
        canRun(batteries, mid, n) ? left = mid : right = mid - 1;
    }
    return left;
}
int main()
{
    int n = 3;
    vector<int> batteries{10, 10, 3, 5};
    maxRunTime(n, batteries);
}