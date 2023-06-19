#include <iostream>
#include <vector>
using namespace std;
int largestAltitude(vector<int> &gain)
{
    int n = gain.size(), max_ans = 0;
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(ans[i - 1] + gain[i - 1]);
        max_ans = max(max_ans, ans[i]);
    }
    return max_ans;
}
int main()
{
    vector<int> gain{-5, 1, 5, 0, -7};
    largestAltitude(gain);
}