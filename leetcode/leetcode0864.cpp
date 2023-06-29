#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
// Return number of set bits in number
int getNumberOfBits(int mask)
{
    int ans = 0;

    while (mask != 0)
    {
        ans += (mask & 1);
        mask >>= 1; // Right Shift (same as divide by 2).
    }

    return ans;
}
bool isValid(int x, int y, int row, int col)
{
    return (x < row && y < col && x >= 0 && y >= 0);
}
bool isLowerCase(char c)
{
    return (c >= 'a' && c <= 'z');
}
bool isUpperCase(char c)
{
    return (c >= 'A' && c <= 'Z');
}
int getBits(int mask)
{
    int ans = 0;
    while (mask != 0)
    {
        ans += (mask & 1);
        mask >>= 1;
    }
    return ans;
}
int shortestPathAllKeys(vector<string> &grid)
{
    queue<vector<int>> q; // i,j,mask
    string key = "abcdef";
    int row = grid.size(), col = grid[0].size(), numOfKey = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (key.find(grid[i][j]) != key.npos)
                numOfKey++;
            if (grid[i][j] == '@')
                q.push({i, j, 0});
        }
    }


    set<vector<int>> vis; // i,j,curMask
    int step = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            vector<int> currCell = q.front();
            q.pop();
            int currX = currCell[0], currY = currCell[1], mask = currCell[2];
            if (getBits(mask) == numOfKey)
                return step;
            for (int k=0;k<4;k++)
            {
                int nextX = currX + dx[k], nextY = currY + dy[k];
                if (!isValid(nextX, nextY, row, col) || grid[nextX][nextY] == '#')
                    continue;
                char newChar = grid[nextX][nextY];
                int newMask = mask;
                if (isLowerCase(newChar))
                {
                    newMask |= (1 << (newChar - 'a'));
                }
                // visited check and lock letter
                if (vis.find({nextX, nextY, newMask}) != vis.end() || (isUpperCase(newChar) && !(mask & (1 << (newChar - 'A')))))
                    continue;
                q.push({nextX, nextY, newMask});
                vis.insert({nextX, nextY, newMask});
            }
        }
        step++;
    }
    return -1;
}
int main()
{
    vector<string> grid{"@.a..", "###.#", "b.A.B"};
    shortestPathAllKeys(grid);
}