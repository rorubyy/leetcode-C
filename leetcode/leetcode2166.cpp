#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bitset
{
public:
    vector<int> bits;
    int oneCnt = 0, flipCnt = 0;
    Bitset(int size)
    {
        bits.resize(size, 0);
        oneCnt = 0, flipCnt = 0;
    }

    void fix(int idx)
    {
        if ((bits[idx] + flipCnt) % 2 == 1)
            return;
        bits[idx]++;
        oneCnt++;
    }

    void unfix(int idx)
    {
        if ((bits[idx] + flipCnt) % 2 == 0)
            return;
        bits[idx]--;
        oneCnt--;
    }

    void flip()
    {
        oneCnt = bits.size() - oneCnt;
        flipCnt++;
    }

    bool all()
    {
        if (oneCnt == bits.size())
            return true;
        return false;
    }

    bool one()
    {
        if (oneCnt > 0)
            return true;
        return false;
    }

    int count()
    {
        return oneCnt;
    }
    string toString()
    {
        string s = "";
        for (auto bit : bits)
        {
            s += to_string((bit+flipCnt)%2);
        }
        return s;
    }
};

int main()
{
    Bitset *obj = new Bitset(5);
    obj->fix(3);
    obj->fix(1);
    obj->flip();
    bool param_4 = obj->all();
    obj->unfix(0);
    obj->flip();
    bool param_5 = obj->one();
    obj->unfix(0);
    int param_6 = obj->count();
    string param_7 = obj->toString();
}