#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int maxDistance(vector<vector<int>> &grid)
{
    queue<pair<int, int>> land;
    int gridLen = grid.size(), index = 0, ans = 0;
    for (int i = 0; i < gridLen; i++) // set land queue
    {
        for (int j = 0; j < gridLen; j++)
        {
            if (grid[i][j] == 1)
            {
                land.push({i, j});
            }
        }
    }
    {
        return -1;
    }
    while (!land.empty())
    {
        vector<int> dir = {-1, 0, 1, 0};
        int landLen = land.size();
        while (landLen > 0)
        {
            int rowValue = land.front().first, colValue = land.front().second;
            land.pop();
            for (int i = 0; i < 4; i++)
            {
                int rowDir = dir[i] + rowValue, colDir = dir[(i + 1) % 4] + colValue;
                if (rowDir < gridLen & rowDir >= 0 && colDir < gridLen && colDir >= 0 && grid[rowDir][colDir] == 0)
                {
                    grid[rowDir][colDir] = 1;
                    land.push({rowDir, colDir});
                }
            }
            landLen--;
        }
        ans++;
    }
    return ans - 1;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    maxDistance(grid);
    return 0;
}