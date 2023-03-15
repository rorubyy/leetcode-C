#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    map<char, int> dictionary;
    int wordsLen = words.size(), orderLen = order.length();
    for (int i = 0; i < orderLen; i++)
    {
        dictionary[order[i]] = i;
    }

    for (int i = 0; i < wordsLen - 1; i++)
    {
        int j = i + 1, checkOrder = 0;
        int firstWordLen = words[i].length(), secondWordLen = words[j].length();
        int checkMinLen = min(firstWordLen, secondWordLen);

        for (int z = 0; z < checkMinLen; z++)
        {
            int firstWordLetter = dictionary[words[i][z]];
            int secondWordLetter = dictionary[words[j][z]];
            if (firstWordLetter < secondWordLetter)
            {
                checkOrder = 1;
                break;
            }
            else if (firstWordLetter == secondWordLetter)
            {
                if (firstWordLen <= secondWordLen && z == checkMinLen - 1)
                {
                    checkOrder = 1;
                    break;
                }
                continue;
            }
            else
            {
                checkOrder = 0;
                break;
            }
        }
        if (checkOrder == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<string> words = {"app","apple"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    isAlienSorted(words, order);
    return 0;
}