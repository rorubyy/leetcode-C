#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
long long distinctNames(vector<string> &ideas)
{
    vector<unordered_set<string>> dictionary(26);
    int ideasLen = ideas.size();
    long long ans = 0;
    for (int i = 0; i < ideasLen; i++)
    {
        dictionary[ideas[i][0] - 97].insert(ideas[i].substr(1));
    }

    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            unordered_set<string> set;
            set.insert(dictionary[i].begin(), dictionary[i].end());
            set.insert(dictionary[j].begin(), dictionary[j].end());
            ans += (set.size() - dictionary[i].size()) * (set.size() - dictionary[j].size());
        }
    }
    return ans * 2;
}

int main()
{
    vector<string> ideas = {"aaa", "baa", "cdd", "bbb", "cbb", "dbb"};
    distinctNames(ideas);
    return 0;
}