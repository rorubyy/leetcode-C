
#include <iostream>
#include <vector>
#include <random>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
        srand(time(NULL));
    }
    int getRandom()
    {
        int count = 0, result;
        ListNode *cur = head;
        while (cur)
        {
            count++;
            if (rand() % count == 0)
            {
                result = cur->val;
            }
            cur = cur->next;
        }
        return result;
    }
};

int main()
{
    vector<int> values = {1, 2, 3};
    ListNode *head = new ListNode(values[0]);
    ListNode *cur = head;
    for (int i = 1; i < values.size(); i++)
    {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }

    Solution *obj = new Solution(head);
    vector<int> randomList(10, 0);
    for (int i = 0; i < 10; i++)
    {
        randomList[i] = obj->getRandom();
    }
    return 0;
}