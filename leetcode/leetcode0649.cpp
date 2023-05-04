#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

string predictPartyVictory(string senate)
{
    queue<int> qr, qd;
    int i = 0, n = senate.size();

    for (int i = 0; i < n; i++)
    {
        senate[i] == 'R' ? qr.push(i) : qd.push(i);
    }
    while (!qr.empty() && !qd.empty())
    {
        int r_idx = qr.front(), d_idx = qd.front();
        d_idx > r_idx ? qr.push(i + n) : qd.push(i + n);
        qr.pop();
        qd.pop();
        i++;
    }
    return qr.empty() ? "Dire" : "Radiant";
}
int main()
{
    string senate = "RDDDDRD";
    predictPartyVictory(senate);
}