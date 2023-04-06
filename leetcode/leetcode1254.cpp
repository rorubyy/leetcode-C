#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int x, int y, int row, int col)
{
    if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] != 0)
        return;

    vector<int> dir{1, 0, -1, 0};
    grid[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i];
        int ny = y + dir[(i + 1) % 4];
        dfs(grid, nx, ny, row, col);
    }
}

int closedIsland(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size(), count = 0;
    // ignore boundary of 0
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i * j == 0 || i == row - 1 || j == col - 1) && grid[i][j] == 0)
            {
                dfs(grid, i, j, row, col);
            }
        }
    }

    // calculate island
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (grid[i][j] == 0)
            {
                dfs(grid, i, j, row, col);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
    closedIsland(grid);
}