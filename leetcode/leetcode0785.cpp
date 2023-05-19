
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> bipartite(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (bipartite[i] != 0)
            continue;
        queue<int> q;
        q.push(i);
        bipartite[i] = 1;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int node : graph[cur])
            {
                if (bipartite[node] == 0)
                {
                    bipartite[node] = -bipartite[cur];
                    q.push(node);
                }
                else if (bipartite[node] == bipartite[cur])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    bool ans = isBipartite(graph);
}
