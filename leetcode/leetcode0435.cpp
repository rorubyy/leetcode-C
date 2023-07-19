#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
static bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), compare);
    int ans = 0, n = intervals.size(), end = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
        // if current start is smaller than previous end ,  remove it
        if (intervals[i][0] < end)
            ans++;
        else
            end = intervals[i][1];
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1, 4}, {2, 3}, {3, 4}};
    eraseOverlapIntervals(intervals);
}