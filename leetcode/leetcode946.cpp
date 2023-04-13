#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int i = 0;
    stack<int> sta;
    for (auto val : pushed)
    {
        sta.push(val);
        while (!sta.empty() && sta.top() == popped[i])
        {
            sta.pop();
            i++;
        }
    }
    return sta.empty();
}

int main()
{
    vector<int> pushed{2, 1, 0}, poped{1, 2, 0};
    validateStackSequences(pushed, poped);
}