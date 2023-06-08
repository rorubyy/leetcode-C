#include <iostream>
#include <vector>
#include <string>

using namespace std;
int minFlips(int a, int b, int c)
{
    int ans = 0;
    while ((a | b) != c)
    {
        if ((c & 1) == 0)
        {
            if ((a & 1) == 1)
                ans++;
            if ((b & 1) == 1)
                ans++;
        }
        else
        {
            if (((a & 1) == 0) && ((b & 1) == 0))
                ans++;
        }
        c >>= 1;
        b >>= 1;
        a >>= 1;
    }
    return ans;
}
int main()
{
    int a = 2, b = 6, c = 5;
    minFlips(a, b, c);
}