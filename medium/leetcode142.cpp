
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head; // fast: two step, slow: one step
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (!fast || !fast->next)
        return NULL;
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
int main()
{
    // initialize a cycle list
    vector<int> values = {3, 2, 0, -4};
    ListNode *head = new ListNode(values[0]);
    ListNode *cur = head;
    for (int i = 1; i < values.size(); i++)
    {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    cur->next = head->next;
    detectCycle(head);
    return 0;
}