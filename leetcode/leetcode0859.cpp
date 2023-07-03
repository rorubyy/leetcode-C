#include <iostream>
#include <set>
using namespace std;
bool buddyStrings(string s, string goal)
{
    int n = s.length();
    if (s == goal)
    {
        set<char> st(s.begin(), s.end());
        return st.size() < goal.size();
    }
    int i = 0, j = n - 1;
    while (s[i] == goal[i])
        i++;
    while (s[j] == goal[j])
        j--;
    swap(s[i], s[j]);
    return s == goal;
}
int main()
{
    string s = "aa", goal = "aa";
    buddyStrings(s, goal);
}