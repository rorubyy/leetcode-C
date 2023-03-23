#include <iostream>
#include <vector>

using namespace std;
int find(int x, vector<int> &parent)
{
    if (x != parent[x])
    {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}
void disjoint(int a, int b, vector<int> &parent)
{
    a = find(a, parent);
    b = find(b, parent);
    a > b ? parent[a] = b : parent[b] = a;
}
bool same(int a, int b, vector<int> &parent)
{
    return find(a, parent) == find(b, parent);
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    int cableNum = connections.size(), group = n;
    vector<int> parent(n);

    if (cableNum < n - 1)
        return -1;
    // initialize
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    // union find
    for (auto con : connections)
    {
        if (!same(con[0], con[1], parent))
        {
            group--;
            disjoint(con[0], con[1], parent);
        }
    }
    return group - 1 < 0 ? 0 : group - 1;
}
int main()
{
    int n = 5;
    vector<vector<int>> connections{{0, 1}, {0, 2}, {3, 4}, {2, 3}};
    makeConnected(n, connections);
}