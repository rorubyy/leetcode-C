#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int r = matrix.size(), c = matrix[0].size();
    int n = r * c;
    int cnt = 0;
    int r_str = 0, c_str = 0, r_end = r - 1, c_end = c - 1;
    bool flag = false;
    vector<int> ans;
    while (cnt < n)
    {
        for (int c = c_str; cnt < n && c <= c_end; c++)
        {
            ans.push_back(matrix[r_str][c]);
            cnt++;
        }
        r_str++;
        for (int r = r_str; cnt < n && r <= r_end; r++)
        {
            ans.push_back(matrix[r][c_end]);
            cnt++;
        }
        c_end--;
        for (int c = c_end; cnt < n && c >= c_str; c--)
        {
            ans.push_back(matrix[r_end][c]);
            cnt++;
        }
        r_end--;
        for (int r = r_end; cnt < n && r >= r_str; r--)
        {
            ans.push_back(matrix[r][c_str]);
            cnt++;
        }
        c_str++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix1 = {{3}, {2}};
    spiralOrder(matrix);
}