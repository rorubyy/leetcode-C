#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char> &chars)
{
    int charsLen = chars.size(), charCount = 1;
    char key = chars[0], preKey;
    if (charsLen == 1)
    {
        return charsLen;
    }
    for (int i = 1; i < charsLen; i++)
    {
        preKey = key; // preKey check if the last char is put into vector or not
        if (chars[i] == key)
        {
            charCount++;
            if (i != charsLen - 1)
                continue;
        }
        chars.push_back(key);

        if (charCount != 1)
        {
            string countString = to_string(charCount);
            for (char c : countString)
            {
                chars.push_back(c);
            }
        }
        charCount = 1;
        key = chars[i];
    }
    if (preKey != key)
    {
        chars.push_back(key);
    }
    chars.erase(chars.begin(), chars.begin() + charsLen);
    return chars.size();
}
int main()
{
    vector<char> chars{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'};
    int ans = compress(chars);
    return 0;
}