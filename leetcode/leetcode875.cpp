
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = *max_element(piles.begin(), piles.end()), mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            totalHours += (piles[i] - 1) / mid + 1;
        }
        if (totalHours > h)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}
int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    minEatingSpeed(piles, h);
    return 0;
}