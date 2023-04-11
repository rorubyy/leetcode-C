#include <iostream>
using namespace std;
string removeStars(string s)
{
    string ans = "";
    for (auto ch : s)
    {
        if (ch != '*')
        {
            ans.push_back(ch);
            continue;
        }
        ans.pop_back();
    }
    return ans;
}
int main()
{
    string s = "leet**cod*e";
    removeStars(s);
}