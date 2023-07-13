#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void makeMap(vector<vector<int>> &outDegree, vector<int> &inDegree, vector<vector<int>> &prerequisites)
{ // find a node with indegree=0, set as starting point
    for (auto edge : prerequisites)
    {
        outDegree[edge[1]].push_back(edge[0]);
        inDegree[edge[0]]++;
    }
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> outDegree(numCourses);
    vector<int> inDegree(numCourses, 0);
    makeMap(outDegree, inDegree, prerequisites);
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    int vis = 0;
    // BFS
    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        vis++;
        for (int nxtNode : outDegree[curNode])
        {
            inDegree[nxtNode]--;
            // 代表nxtNode前面的點都走過了
            if (inDegree[nxtNode] == 0)
                q.push(nxtNode);
        }
    }
    return vis == numCourses;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites{{0, 1}};
    canFinish(numCourses, prerequisites);
}