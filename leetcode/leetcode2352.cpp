#include <iostream>
#include <vector>
#include <map>
using namespace std;
int equalPairs(vector<vector<int>> &grid)
{
    int n = grid.size(), ans = 0;
    vector<vector<int>> v = grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i] == grid[j])
                ans++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    equalPairs(grid);
}