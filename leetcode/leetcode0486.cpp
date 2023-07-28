#include <iostream>
#include <vector>

using namespace std;

int dfs(int head, int tail, vector<int> &nums, int turn)
{
    if (head >= nums.size() || tail < 0)
        return 0;
    if (head > tail)
        return 0;
    if (turn == 0)
        return max(nums[head] + dfs(head + 1, tail, nums, 1), nums[tail] + dfs(head, tail - 1, nums, 1));
    else
        return min(-nums[head] + dfs(head + 1, tail, nums, 0), -nums[tail] + dfs(head, tail - 1, nums, 0));
}

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    int score = dfs(0, n - 1, nums, 0);
    return score >= 0;
}
int main()
{
    vector<int> nums{1, 5, 2};
    PredictTheWinner(nums);
}