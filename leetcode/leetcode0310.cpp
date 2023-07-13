#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if(n==1)
        return {0};
    vector<vector<int>> map(n);
    vector<int> degree(n, 0);
    for (auto edge : edges)
    {
        map[edge[0]].push_back(edge[1]);
        map[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    queue<int> q;
    vector<int> root;
    // push degree=1 as leaf
    for (int i = 0; i < n; i++)
        if (degree[i] == 1)
            q.push(i);
    while (!q.empty())
    {
        int sz = q.size();
        root.clear();
        while (sz--)
        {
            int cur = q.front();
            q.pop();
            // root存放最後為根的結果 每次clear會把child清除
            root.push_back(cur);
            for (int i = 0; i < map[cur].size(); i++)
            {
                int nxt = map[cur][i];
                degree[nxt]--;
                if (degree[nxt] == 1)
                    q.push(nxt);
            }
        }
    }
    return root;
}
int main()
{
    int n = 6;
    vector<vector<int>> edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    findMinHeightTrees(n, edges);
}