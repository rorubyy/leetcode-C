#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    int people_num = people.size();
    int min_idx = 0, max_idx = people_num - 1, min_boat = 0;
    sort(people.begin(), people.end());
    while (min_idx <= max_idx)
    {
        if (people[min_idx] + people[max_idx] <= limit)
        {
            min_idx++;
        }
        max_idx--;
        min_boat++;
    }
    return min_boat;
}
int main()
{
    vector<int> people{3, 5, 3, 4};
    int limit = 3;
    numRescueBoats(people, limit);
}