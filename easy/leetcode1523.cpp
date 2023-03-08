#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int countOdds(int low, int high)
{
    return (low % 2 == 0 && high % 2 == 0) ? (high - low) / 2 : (high - low) / 2 + 1;
}

int main()
{
    int low = 3, high = 7;
    countOdds(low, high);
    return 0;
}