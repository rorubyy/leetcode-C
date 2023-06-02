#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
void dfs(vector<vector<int>> &diGraph, vector<bool> &visited, int s, int &bombs)
{
    int n = diGraph.size();
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if (diGraph[s][i] != -1 && !visited[i])
        {
            bombs++;
            dfs(diGraph, visited, i, bombs);
        }
    }
}

int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    vector<vector<int>> diGraph(n, vector<int>(n, -1));
    // draw a direct graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            float d = sqrt(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2));
            if (d <= bombs[i][2])
                diGraph[i][j] = 1;
        }
    }

    // DFS
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        int bombs = 1;
        dfs(diGraph, visited, i, bombs);
        res = max(bombs, res);
    }
    return res;
}

int main()
{
    vector<vector<int>> bombs{{2, 1, 3}, {6, 1, 4}};

    maximumDetonation(bombs);
}