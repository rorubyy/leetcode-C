#include <iostream>
#include <vector>

using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int l = 0, r = n - 1;
    if (target >= letters[r])
        return letters[0];
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (letters[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return letters[l];
}

int main()
{
    vector<char> letter{'c', 'f', 'j'};
    char target = 'c';
    nextGreatestLetter(letter, target);
}