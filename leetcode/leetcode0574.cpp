#include <iostream>
#include <vector>

using namespace std;
void dfs(int s, vector<vector<int>> &isConnected, vector<bool> &visited)
{
    visited[s] = true;
    int n = isConnected[s].size();
    for (int i = 0; i < n; i++)
    {
        if (isConnected[s][i] == 1 && visited[i] == false)
            dfs(i, isConnected, visited);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected[0].size();
    int provinces = 0;
    vector<bool> visited(n, false);
    // initialize
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, isConnected, visited);
            provinces++;
        }
    }
    return provinces;
}
int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    findCircleNum(isConnected);
}