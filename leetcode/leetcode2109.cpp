#include <iostream>
#include <vector>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    string s1 = "";
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == spaces[idx])
        {
            if (idx < spaces.size()-1)
                idx++;
            s1.push_back(32);
        }
        s1.push_back(s[i]);
    }
    return s1;
}
int main()
{
    string s = "icodeinpython";
    vector<int> spaces{1, 5, 7, 9};
    addSpaces(s, spaces);
}