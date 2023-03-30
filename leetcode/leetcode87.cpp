#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool isScramble(string s1, string s2, unordered_map<string, bool> mp)
{
    if (s1.length() != s2.length())
        return false;
    if (s1 == s2)
        return true;
    string sort_s1 = s1, sort_s2 = s2;
    sort(sort_s1.begin(), sort_s1.end());
    sort(sort_s2.begin(), sort_s2.end());
    if (sort_s1 != sort_s2)
        return false;

    int n = s1.length();

    string key = s1 + "" + s2;
    bool flag = false;
    if (mp.find(key) != mp.end())
    {
        return mp[key];
    }

    for (int i = 1; i < n; i++)
    {
        if (isScramble(s1.substr(0, i), s2.substr(0, i), mp) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i), mp))
        {
            flag = true;
            return true;
        }
        if (isScramble(s1.substr(0, i), s2.substr(n - i, i), mp) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i), mp))
        {
            flag = true;
            return true;
        }
        mp[key] = flag;
    }
    return false;
}

int main()
{
    string s1 = "eebaacbcbcadaaedceaaacadccd", s2 = "eadcaacabaddaceacbceaabeccd";
    unordered_map<string, bool> mp;

    isScramble(s1, s2, mp);
}
