#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// find parent of the node
int find(int i, vector<int> &map)
{
    if (i != map[i])
        map[i] = find(map[i], map);
    return map[i];
}

int minScore(int n, vector<vector<int>> &roads)
{
    vector<int> map(n + 1), minDistance(n + 1);

    // initialize
    for (int i = 1; i <= n; i++)
    {
        map[i] = i;
        minDistance[i] = INT16_MAX;
    }

    for (int i = 0; i < roads.size(); i++)
    {
        int root_a = find(roads[i][0], map), root_b = find(roads[i][1], map);
        int minPath = min(minDistance[root_a], minDistance[root_b]);
        minPath = min(minPath, roads[i][2]);

        int gmax = max(root_a, root_b);
        int gmin = min(root_a, root_b);
        map[gmax] = gmin;
        minDistance[gmax] = minPath;
        minDistance[gmin] = minPath;
    }
    return minDistance[find(n, map)];
}
int main()
{
    vector<vector<int>> roads{{4, 5, 7468}, {6, 2, 7173}, {6, 3, 8365}, {2, 3, 7674}, {5, 6, 7852}, {1, 2, 8547}, {2, 4, 1885}, {2, 5, 5192}, {1, 3, 4065}, {1, 4, 7357}};
    int n = 6;
    minScore(n, roads);
    return 0;
}