#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<vector<int>> &adjList, int &reverse, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (auto neighbor : adjList[node])
    {
        if (!visited[abs(neighbor)])
        {
            reverse += neighbor < 0 ? 1 : 0;
            dfs(adjList, reverse, visited, abs(neighbor));
        }
    }
}
int minReorder(int n, vector<vector<int>> &connections)
{
    int reverse = 0;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n, false);
    for (auto &con : connections)
    {
        int from = con[0], to = con[1];
        adjList[from].push_back(-to);
        adjList[to].push_back(from);
    }
    dfs(adjList, reverse, visited, 0);
    return reverse;
}
int main()
{
    int n = 5;
    vector<vector<int>> connections{{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    minReorder(n, connections);
}