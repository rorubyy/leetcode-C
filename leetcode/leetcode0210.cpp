#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void makeMap(vector<int> &inDegree, vector<vector<int>> &outDegree, vector<vector<int>> &prerequisites)
{
    for (auto edge : prerequisites)
    {
        outDegree[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }
}
vector<int> bfs(vector<int> &inDegree, vector<vector<int>> &outDegree, int numCourses)
{
    vector<int> ans;
    queue<int> q;
    int vis = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        vis++;
        int curNode = q.front();
        ans.insert(ans.begin(), curNode);
        q.pop();
        for (auto nxtNode : outDegree[curNode])
        {
            inDegree[nxtNode]--;
            if (inDegree[nxtNode] == 0)
                q.push(nxtNode);
        }
    }
    return vis == numCourses ? ans : vector<int>();
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> outDegree(numCourses);
    makeMap(inDegree, outDegree, prerequisites);
    return bfs(inDegree, outDegree, numCourses);
}
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites{{1, 0}};
    findOrder(numCourses, prerequisites);
}