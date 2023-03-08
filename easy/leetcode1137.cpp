#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n)
{
    int n0 = 0, n1 = 1, n2 = 1;
    int ans[38];
    ans[0] = 0, ans[1] = 1, ans[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    return ans[n];
}

int main()
{
    int ans = tribonacci(4);
    cout << ans;
    return 0;
}