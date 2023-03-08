
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

#define ll long long

using namespace std;
long long minimumTime(vector<int> &time, int totalTrips)
{
    ll minOneTripTime = *min_element(time.begin(), time.end());
    ll left = 1, right = long(minOneTripTime * totalTrips), mid;

    long long minimumTime;
    while (left <= right)
    {
        ll nowTotalTrip = 0;
        mid = left + (right - left) / 2;
        for (int i = 0; i < time.size(); i++)
        {
            nowTotalTrip += mid / time[i];
        }
        if (nowTotalTrip >= totalTrips)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    vector<int> time = {1, 2, 3};
    int totalTrips = 3;
    minimumTime(time, totalTrips);
    return 0;
}