#include <iostream>
#include <vector>
#include <set>

using namespace std;
bool dfs(vector<bool> &isVisited, vector<bool> &dfsVisited, int src, vector<vector<int>> &graph, set<int> &cycle)
{
    isVisited[src] = true;
    dfsVisited[src] = true;

    for (int i = 0; i < graph[src].size(); i++)
    {
        int child = graph[src][i];
        if (!isVisited[child])
        { // 這回合還沒有走過child這個點 透過dfs去traverse這個點尋找是否有cycle
            if (dfs(isVisited, dfsVisited, child, graph, cycle))
            {
                cycle.insert(child);
                return true;
            }
        }
        else
        { // 這回合已經走過child這個點並且之前有透過dfs走到這個點過 --> cycle
            if (dfsVisited[child])
            {
                cycle.insert(child);
                return true;
            }
        }
    }
    dfsVisited[src] = false;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    // detect if this node is a cycle dfs
    int n = graph.size();
    set<int> cycle;
    vector<bool> isVisited(n, false), dfsVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (dfs(isVisited, dfsVisited, i, graph, cycle))
            cycle.insert(i);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (cycle.find(i) == cycle.end())
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    vector<vector<int>> graph{{}, {0, 2, 3, 4}, {3}, {4}, {}};
    eventualSafeNodes(graph);
}
