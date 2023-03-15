
#include <iostream>
#include <vector>

using namespace std;

vector<int> lpsProcess(string needle)
{
    int nLen = needle.size();
    vector<int> lps(nLen, 0);
    int prefixIndex = 0, i = 1;
    while (i < nLen)
    {
        if (needle[i] == needle[prefixIndex])
        {
            lps[i] = prefixIndex + 1;
            prefixIndex++;
            i++;
        }
        else
        {
            if (prefixIndex == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                prefixIndex = lps[prefixIndex - 1];
        }
    }
    return lps;
}
int strStr(string haystack, string needle)
{
    int hLen = haystack.size(), nLen = needle.size();
    vector<int> lps = lpsProcess(needle);
    // KMP
    int i = 0, j = 0;
    while (i < hLen)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
        if (j == nLen)
        {
            return i - nLen;
        }
    }
    return -1;
}
int main()
{
    string haystack = "mississippi", needle = "issip";
    strStr(haystack, needle);
    return 0;
}