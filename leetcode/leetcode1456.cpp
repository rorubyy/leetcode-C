#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int maxVowels(string s, int k)
{
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    int ans = 0;

    for (int i = 0, local = 0; i < s.size(); i++)
    {
        local += vowels.count(s[i]);
        if (i - k >= 0)
            local -= vowels.count(s[i - k]);
        ans = max(ans, local);
    }

    return ans;
}
int main()
{
    string s = "abciiidef";
    int k = 3;
    maxVowels(s, k);
}