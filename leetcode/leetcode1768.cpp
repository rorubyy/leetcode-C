#include <iostream>
#include <string>
using namespace std;
string mergeAlternately(string word1, string word2)
{
    int i = 0, w1Len = word1.size(), w2Len = word2.size();
    string ans = "";
    while (i < w1Len || i < w2Len)
    {
        if (i >= w1Len)
        {
            ans.append(word2.substr(i));
            return ans;
        }
        if (i >= w2Len)
        {
            ans.append(word1.substr(i));
            return ans;
        }
        ans.push_back(word1[i]);
        ans.push_back(word2[i]);
        i++;
    }
    return ans;
}
int main()
{
    string word1 = "abcd", word2 = "pq";
    mergeAlternately(word1, word2);
}