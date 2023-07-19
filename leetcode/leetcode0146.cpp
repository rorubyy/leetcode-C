#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> mp;
    int n;

public:
    LRUCache(int capacity)
    {
        n = capacity;
        head->next = tail;
        tail->next = head;
    }
    void addNode(Node *newNode)
    {
        // add to head
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *nde = mp[key];
            int val = nde->val;
            // 因為被使用到重新計算recent used
            mp.erase(key);
            deleteNode(nde);
            // 重新加入head
            addNode(nde);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *nde = mp[key];
            mp.erase(key);
            deleteNode(nde);
        }
        if (mp.size() == n)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};
int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);    // return 4
}