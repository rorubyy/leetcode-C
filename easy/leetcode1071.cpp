#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string gcdOfStrings(string str1, string str2)
{
    string str1AppendStr2 = str1+str2, str2AppendStr1 = str2+str1;
    int str1Len, str2Len;
    if (str1AppendStr2 != str2AppendStr1)
        return "";
    while (1)
    {
        str1Len = str1.length(), str2Len = str2.length();
        if (str1 == str2)
            return str1;
        else if (str1Len > str2Len)
        {
            str1 = str1.substr(str2Len);
        }
        else if (str2Len > str1Len)
        {
            str2 = str2.substr(str1Len);
        }
    }
}

int main()
{
    string str1 = "ABCABC", str2 = "ABC";
    gcdOfStrings(str1, str2);

    return 0;
}