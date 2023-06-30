#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &map, vector<vector<bool>> &visited, int r, int c, int row, int col)
{
    // out of bound
    return (r >= row || c >= col || r < 0 || c < 0 || map[r][c] == 1 || visited[r][c]);
}
void dfs(vector<vector<int>> &map, int r, int c, int row, int col, bool &flag, vector<vector<bool>> &visited)
{
    if (r == row - 1)
    {
        flag = true;
        return;
    }
    visited[r][c] = true;
    vector<int> dir{1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i];
        int nc = c + dir[(i + 1) % 4];
        if (!isValid(map, visited, nr, nc, row, col))
            dfs(map, nr, nc, row, col, flag, visited);
    }
}
vector<vector<int>> makeMap(vector<vector<int>> &cell, int row, int col, int mid)
{
    vector<vector<int>> map(row, vector<int>(col, 0));
    for (int i = 0; i <= mid; i++)
        map[cell[i][0] - 1][cell[i][1] - 1] = 1;
    return map;
}
int latestDayToCross(int row, int col, vector<vector<int>> &cells)
{
    int left = 0, right = row * col - 1, days = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        auto map = makeMap(cells, row, col, mid);
        bool flag = false;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < col; i++)
        {
            if (map[0][i] == 0&&!visited[0][i])
            {
                dfs(map, 0, i, row, col, flag, visited);
                if (flag)
                    break;
            }
        }
        if (flag)
        {
            days = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return days + 1;
}
int main()
{
    int row = 3, col = 3;
    vector<vector<int>> cells{{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}};

    latestDayToCross(row, col, cells);
}