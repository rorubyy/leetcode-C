#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int projectsLen = profits.size();
    vector<pair<int, int>> projects(projectsLen);

    for (int i = 0; i < projectsLen; i++)
    {
        projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end());

    priority_queue<int> maxCapital;
    int index = 0;
    while (k--)
    {
        while (index < projectsLen && projects[index].first <= w)
        {
            maxCapital.push(projects[index].second);
            index++;
        }
        if (maxCapital.empty())
            break;
        w += maxCapital.top();
        maxCapital.pop();
    }

    return w;
}
int main()
{
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3}, capital = {0, 9, 10};
    findMaximizedCapital(k, w, profits, capital);
    return 0;
}