#include <iostream>
#include <vector>
using namespace std;
bool isBadVersion(int n)
{
    if (n >= 1)
        return true;
    return false;
}
int firstBadVersion(int n)
{
    int l = 1, r = n, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        bool now = isBadVersion(m), pre = isBadVersion(m - 1);
        if (now && !pre)
        {
            return m;
        }
        else if (!now)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return m;
}

int main()
{
    int n = 3;
    firstBadVersion(n);
}