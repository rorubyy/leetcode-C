#include <iostream>
#include <vector>
#include <queue>

using namespace std;
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<pair<int, double>> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    priority_queue<pair<double, int>> pq;
    vector<double> dist(n, -1);
    dist[start] = 1;
    pq.push({1, start});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int curNode = cur.second;
        double curDist = cur.first;
        for (auto it : adj[curNode])
        {
            int adjNode = it.first;
            double adjDist = it.second;
            if (adjDist * curDist > dist[adjNode])
            {
                dist[adjNode] = adjDist * curDist;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if (dist[end] == -1)
        return 0;
    return dist[end];
}
int main()
{
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb{0.5, 0.5, 0.2};
    maxProbability(n, edges, succProb, start, end);
}
