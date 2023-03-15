
#include <iostream>
#include <vector>

using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        int missNum = arr[mid] - mid - 1;
        if (missNum < k)
        {
            left = mid + 1;
        }
        else // move to the left
        {
            right = mid - 1;
        }
    }
    // int ans = arr[left - 1] + (k - (arr[left - 1] - (left - 1) - 1));
    return k + left;
}
int main()
{
    vector<int> arr = {2};
    int k = 1;
    findKthPositive(arr, k);
    return 0;
}