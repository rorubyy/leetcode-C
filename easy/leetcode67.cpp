#include <iostream>
#include <vector>
#include <queue>

using namespace std;
string addBinary(string a, string b)
{
    int aLen = a.size(), bLen = b.size(), carry = 0;
    string binaryAns = "";
    for (int i = 0; i <= max(aLen, bLen); i++)
    {
        int aIndex = aLen - 1 - i, bIndex = bLen - 1 - i;
        int aINT = (aIndex >= 0) ? a[aIndex] - 48 : 0, bINT = (bIndex >= 0) ? b[bIndex] - 48 : 0;

        int binary = (aINT + bINT + carry) % 2;
        carry = (aINT + bINT + carry) / 2;
        if (i == max(aLen, bLen) && binary == 0)
            return binaryAns;
        binaryAns.insert(binaryAns.begin(), binary + 48);
    }
    return binaryAns;
}

int main()
{
    string a = "1010", b = "1011";
    addBinary(a, b);
    return 0;
}