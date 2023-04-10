#include <iostream>
#include <vector>
#include <stack>

using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (c == '[' || c == '{' || c == '(')
            st.push(c);
        else if (!st.empty() && (c == st.top() + 1 || c == st.top() + 2))
            st.pop();
        else
            return false;
    }
    return st.empty();
}
int main()
{
    string s = "[]";
    isValid(s);
}