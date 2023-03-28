#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
int shipWithinDays(vector<int> &weights, int days)
{
    int minCapacity = *max_element(weights.begin(), weights.end()), maxCapacity = accumulate(weights.begin(), weights.end(), 0);
    int left = minCapacity, right = maxCapacity, mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        int cur = 0, requireDay = 1;
        for (int weight : weights)
        {
            if (cur + weight > mid)
            {
                cur = 0;
                requireDay++;
            }
            cur += weight;
        }
        if (requireDay <= days)
        {
            right = mid; // capacity is sufficient , reduce right pointer
        }
        else
        {
            left = mid + 1; // capacity is insufficient , add left pointer
        }
    }
    return left;
}

int main()
{
    vector<int> weights = {10, 50, 100, 100, 50, 100, 100, 100};
    int days = 5;
    shipWithinDays(weights, days);
    return 0;
}
