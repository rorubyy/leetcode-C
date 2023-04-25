#include <iostream>
#include <set>
using namespace std;
class SmallestInfiniteSet
{
public:
    int cur = 1;
    set<int> st;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            st.insert(i);
        }
    }

    int popSmallest()
    {
        cur= *st.begin();
        st.erase(cur);
        return cur;
    }

    void addBack(int num)
    {
        st.insert(num);
    }
};

int main()
{
    SmallestInfiniteSet *obj = new SmallestInfiniteSet();
    int param_1 = obj->popSmallest();
    obj->addBack(2);
}