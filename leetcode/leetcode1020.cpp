#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void dfs(int r, int c, vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
        return;
    grid[r][c] = 0;
    vector<int> dir{1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i];
        int nc = c + dir[(i + 1) % 4];
        dfs(nr, nc, grid);
    }
}
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
            {
                dfs(i, j, grid);
            }
        }
    }
    int count = 0;
    for (auto row : grid)
    {
        for (auto col : row)
        {
            if (col == 1)
                count++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> grid{{0}, {1}, {1}, {0}, {0}};
    numEnclaves(grid);
}