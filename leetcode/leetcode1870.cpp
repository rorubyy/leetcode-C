#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
bool isOnTime(vector<int> &dist, int mid, double hour)
{
    double ans = 0;
    for (int i = 0; i < dist.size(); i++)
        ans += i == dist.size() - 1 ? double(dist[i]) / double(mid) : ((dist[i] + mid - 1) / mid);
    return ans > hour ? false : true;
}
int minSpeedOnTime(vector<int> &dist, double hour)
{

    if (hour <= dist.size() - 1)
        return -1;
    int left = 1, right = 1e7;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        isOnTime(dist, mid, hour) ? right = mid : left = mid + 1;
    }
    return left;
}

int main()
{
    vector<int> dist{5, 3, 4, 6, 2, 2, 7};
    double hour = 10.92;
    minSpeedOnTime(dist, hour);
}