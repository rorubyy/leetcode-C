#include <iostream>
#include <vector>

using namespace std;
int countNegatives(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] >= 0)
            {
                ans++;
            }
            else
                break;
        }
    }
    return n * m - ans;
}
int main()
{
    vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
int countNegatives(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] >= 0)
            {
                ans++;
            }
            else
                break;
        }
    }
    return n * m - ans;
}    countNegatives(grid);
}