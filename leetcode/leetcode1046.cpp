#include <iostream>
#include <queue>
using namespace std;
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    for (auto s : stones)
    {
        pq.push(s);
    }
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if (first != second)
            pq.push(first - second);
    }
    return pq.size() > 0 ? pq.top() : 0;
}
int main()
{
    vector<int> stones{2, 2};
    lastStoneWeight(stones);
}