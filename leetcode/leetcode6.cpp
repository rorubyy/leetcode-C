#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string convert(string s, int numRows)
{
    string ans = "";
    int sLen = s.size();
    int firstRowIndex = (numRows - 1) * 2;

    for (int i = 0; i < numRows; i++)
    {
        int rowIndex = firstRowIndex - (i * 2);
        if (i == numRows - 1)
            rowIndex = firstRowIndex;
        int flag = 0;
        for (int j = i; j < sLen; j += rowIndex)
        {
            ans += s[j];
            if (i > 0 && i < numRows - 1)
            {
                if (flag == 0)
                {
                    rowIndex = firstRowIndex - (i * 2);
                    flag = 1;
                }
                else
                {
                    rowIndex = abs(firstRowIndex - rowIndex);
                    flag = 0;
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;
    convert(s, numRows);
    return 0;
}