#include <iostream>
#include <vector>

using namespace std;
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<int> output;
    vector<int> indegree(n, 0);

    for (auto e : edges)
        indegree[e[1]]++;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            output.push_back(i);
    return output;
}
int main()
{
    vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    findSmallestSetOfVertices(6, edges);
}