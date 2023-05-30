#include <iostream>
#include <set>

using namespace std;

class MyHashSet
{
public:
    set<int> hashSet;
    MyHashSet()
    {
    }

    void add(int key)
    {
        hashSet.insert(key);
    }

    void remove(int key)
    {
        hashSet.erase(key);
    }

    bool contains(int key)
    {
        if (hashSet.find(key) != hashSet.end())
            return true;
        return false;
    }
};
int main()
{
    MyHashSet *obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    bool param_1 = obj->contains(1);
    bool param_2 = obj->contains(3);
    obj->add(2);
    bool param_3 = obj->contains(2);
    obj->remove(2);
    bool param_4 = obj->contains(2);
}