#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int cnt = 0;
    int r_str = 0, r_end = n - 1, c_str = 0, c_end = n - 1;
    while (cnt < n * n)
    {
        for (int c = c_str; cnt < n * n && c <= c_end; c++)
        {
            ans[r_str][c] = ++cnt;
        }
        r_str++;
        for (int r = r_str; cnt < n * n && r <= r_end; r++)
        {
            ans[r][c_end] = ++cnt;
        }
        c_end--;
        for (int c = c_end; cnt < n * n && c >= c_str; c--)
        {
            ans[r_end][c] = ++cnt;
        }
        r_end--;
        for (int r = r_end; cnt < n * n && r >= r_str; r--)
        {
            ans[r][c_str] = ++cnt;
        }
        c_str++;
    }
    return ans;
}
int main()
{
    int n = 3;
    generateMatrix(n);
}