#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 0, right = arr.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (mid > 0 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid + 1] > arr[mid])
            left = mid + 1;
        else if (arr[mid + 1] < arr[mid])
            right = mid - 1;
    }
    return left;
}
int main()
{
    vector<int> arr{0, 2, 1, 0};
    peakIndexInMountainArray(arr);
}