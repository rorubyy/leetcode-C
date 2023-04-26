#include <iostream>
using namespace std;
int addDigits(int num)
{
    string num2str = to_string(num);
    while (num2str.size() > 1)
    {
        int temp = 0;
        for (auto s : num2str)
        {
            temp += (int(s) - 48);
        }
        num2str = to_string(temp);
    }
    return int(num2str[0]) - 48;
}

int main()
{
    int num = 38;
    addDigits(num);
}