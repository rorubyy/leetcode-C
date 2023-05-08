#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    int ans = 0, n = mat.size();
    for (int i = 0; i < n; i++)
    {
        int primaryDia = i, secondDia = n - 1 - i;
        primaryDia == secondDia ? ans += mat[i][primaryDia] : ans = ans + mat[i][primaryDia] + mat[i][secondDia];
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    diagonalSum(mat);
}