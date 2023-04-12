#include <iostream>
#include <vector>
using namespace std;
string simplifyPath(string path)
{
    vector<string> dir;
    string nowRoot = "", ans = "";
    int 
    len = path.size();

    for (int i = 1; i <= len; i++)
    {
        if (i < len && path[i] != '/')
        {
            nowRoot += path[i];
        }
        else
        {
            if (nowRoot == "..")
            {
                if (!dir.empty())
                    dir.pop_back();
            }
            else if (nowRoot != "." && nowRoot != "")
                dir.push_back(nowRoot);
            nowRoot = "";
        }
    }
    for (auto str : dir)
    {
        ans += "/";
        ans += str;
    }
    ans == "" ? ans += "/" : ans;
    return ans;
}
int main()
{
    string path = "/home/";
    simplifyPath(path);
}