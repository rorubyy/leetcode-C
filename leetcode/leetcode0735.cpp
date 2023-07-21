#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (st.empty() || asteroids[i] > 0)
            st.push(asteroids[i]);
        else
        {
            while (!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top())
                st.pop();
            if (!st.empty() && st.top() == abs(asteroids[i]))
                st.pop();
            else
            {
                if (st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            }
        }
    }
    while (!st.empty())
    {
        ans.insert(ans.begin(), st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    vector<int> asteroids{-2, -2, 1, -2};
    asteroidCollision(asteroids);
}