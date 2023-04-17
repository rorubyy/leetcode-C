#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxKid = *max_element(candies.begin(), candies.end());
    vector<bool> greatestNum;
    for (auto can : candies)
    {
        can + extraCandies >= maxKid ? greatestNum.push_back(true) : greatestNum.push_back(false);
    }
    return greatestNum;
}
int main()
{
    vector<int> candie{2, 3, 5, 1, 3};
    int extrextraCandies = 3;
    kidsWithCandies(candie, extrextraCandies);
}