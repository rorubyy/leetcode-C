#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

double average(vector<int> &salary)
{
    double minSal = INT64_MAX, maxSal = 0;
    double ans = 0;
    for (auto sal : salary)
    {
        if (sal < minSal)
        {
            minSal = sal;
        }
        if (sal > maxSal)
        {
            maxSal = sal;
        }
        ans += sal;
    }
    return (ans - minSal - maxSal) / (salary.size() - 2);
}
int main()
{
    vector<int> salary{4000, 3000, 1000, 2000};
    average(salary);
}