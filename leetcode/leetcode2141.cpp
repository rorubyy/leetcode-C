
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;
bool isEmpty(int k)
{
    if(k==0)
        return true;
    return false;
}
bool isValid(vector<int> &batteries, int minutes, int n)
{
    vector<int> temp = batteries;
    sort(temp.begin(), temp.end(), greater<int>());

    for (int i = 0; i < minutes; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j]--;
        }
        temp = remove_if(temp.begin(), temp.end(), isEmpty);
    }
    return true;
}
long long maxRunTime(int n, vector<int> &batteries)
{
    int left = *min_element(batteries.begin(), batteries.end()), right = accumulate(batteries.begin(), batteries.end(), 0);
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        isValid(batteries, mid, n) ? left = mid + 1 : right = mid;
    }
    return left;
}
int main()
{
    int n = 2;
    vector<int> batteries{3, 3, 3};
    maxRunTime(n, batteries);
}