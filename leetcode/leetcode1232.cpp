#include <iostream>
#include <vector>

using namespace std;
bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int x1 = coordinates[0][0], y1 = coordinates[0][1], x2 = coordinates[1][0], y2 = coordinates[1][1];
    for (int i = 2; i < coordinates.size(); i++)
    {
        int x3 = coordinates[i][0], y3 = coordinates[i][1];
        if (((y2 - y1) * (x3 - x1)) != ((x2 - x1) * (y3 - y1)))
            return false;
    }
    return true;
}
int main()
{
    vector<vector<int>> coordinates{{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    checkStraightLine(coordinates);
}