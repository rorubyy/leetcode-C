#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
bool isSimilarGroup(string s1, string s2)
{
    if (s1 == s2)
        return true;
    int diff = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (diff > 2)
            return false;
        if (s1[i] != s2[i])
        {
            diff++;
        }
    }
    return diff == 2;
}

int find(int x, vector<int> &parent)
{
    if (x != parent[x])
    {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void disjoint(int a, int b, vector<int> &parent, int &count)
{
    a = find(a, parent);
    b = find(b, parent);
    if (a == b)
        return;
    a > b ? parent[a] = b : parent[b] = a;
    count--;
}
int numSimilarGroups(vector<string> &strs)
{
    int strsNum = strs.size(), count = strs.size();
    // Union find
    vector<int> parent(strsNum);
    for (int i = 0; i < strsNum; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < strsNum; i++)
    {
        for (int j = i + 1; j < strsNum; j++)
        {
            if (isSimilarGroup(strs[i], strs[j]))
            {
                disjoint(i, j, parent, count);
            }
        }
    }
    return count;
}
int main()
{
    vector<string> strs{"omv", "ovm"};
    numSimilarGroups(strs);
}