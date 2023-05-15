#include <iostream>
#include <vector>
using namespace std;

long long dp(vector<vector<int>> &questions, vector<int> &point, int idx, int n)
{
    if (idx >= n)
        return 0;
    if (point[idx] != -1)
        return point[idx];
    long long ans = max(questions[idx][0] + dp(questions, point, idx + questions[idx][1] + 1, n), dp(questions, point, idx + 1, n)); // solve or skip
    point[idx] = ans;
    return ans;
}

long long mostPoints(vector<vector<int>> &questions)
{
    int n = questions.size();
    vector<int> point(n, -1);
    return dp(questions, point, 0, n);

}

int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 2}, {4, 4}, {2, 5}};
    mostPoints(questions);
}
