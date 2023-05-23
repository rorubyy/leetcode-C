#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n;

public:
    KthLargest(int k, vector<int> &nums)
    {
        n = k;
        for (auto num : nums)
        {
            minHeap.push(num);
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        while (minHeap.size() > n)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main()
{
    vector<int> nums{4, 5, 8, 2};
    KthLargest *kthLargest = new KthLargest(3, nums);
    int ans;
    ans = kthLargest->add(3);
    ans = kthLargest->add(5);
    ans = kthLargest->add(10);
    ans = kthLargest->add(9);
    ans = kthLargest->add(4);
}
