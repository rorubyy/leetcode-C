#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dirs{{-1, -0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front().first;
        int row = p.first, col = p.second, lenOfPath = q.front().second;
        if(row==n-1&&col==n-1)
            return lenOfPath;
        q.pop();
        for (auto dir : dirs)
        {
            int next_row = row + dir[0], next_col = col + dir[1];
            if (next_row < n && next_col < n && next_row >= 0 && next_col >= 0 && grid[next_row][next_col] == 0 && !visited[next_row][next_col])
            {
                q.push({{next_row, next_col}, lenOfPath + 1});
                visited[next_row][next_col] = true;
            }
            if (next_row == n - 1 && next_col == n - 1)
                return lenOfPath + 1;
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid{{0}};
    shortestPathBinaryMatrix(grid);
}