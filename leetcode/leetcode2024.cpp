#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// int maxConsecutiveAnswers(string answerKey, int k)
// {
//     // sliding window
//     // maintain a window with two pointers i and j represent left and right boundaries
//     int maxFreq = 0, i = 0;
//     int n = answerKey.size();
//     unordered_map<char, int> charCnt;
//     for (int j = 0; j < n; j++)
//     {
//         char curChar = answerKey[j];
//         charCnt[curChar]++;
//         maxFreq = max(maxFreq, charCnt[curChar]);
//         if (j - i + 1 > maxFreq + k)
//         {
//             charCnt[answerKey[i]]--;
//             i++;
//         }
//     }
//     return n - i;
// }
int maxConsecutiveAnswers(string answerKey, int k)
{
    int extra = 0, maxFreq = 0, i = 0, j = 0, n = answerKey.size();
    while (j < n)
    { // find consecutive TRUE
        if (answerKey[j] == 'F')
        {
            extra++;
            while (extra > k)
            {
                if (answerKey[i] == 'F')
                    extra--;
                i++;
            }
        }
        maxFreq = max(maxFreq, j - i + 1);
        j++;
    }
    i = 0, j = 0, extra = 0;
    while (j < n)
    { // find consecutive FALSE
        if (answerKey[j] == 'T')
        {
            extra++;
            while (extra > k)
            {
                if (answerKey[i] == 'T')
                    extra--;
                i++;
            }
        }
        maxFreq = max(maxFreq, j - i + 1);
        j++;
    }
    return maxFreq;
}
int main()
{
    string answerKey = "TTFTTFTT";
    int k = 1;
    maxConsecutiveAnswers(answerKey, k);
}