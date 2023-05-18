#include "header/ListNode.h"
#include <iostream>
#include <stack>

using namespace std;

int pairSum(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    int max_sum = 0;
    stack<int> twins;
    while (fast)
    {
        twins.push(slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }
    while (slow)
    {
        int temp = twins.top();
        twins.pop();
        max_sum = max(temp + slow->val, max_sum);
        slow = slow->next;
    }
    return max_sum;
}
int main()
{
    vector<int> head{5, 4, 2, 1};
    pairSum(buildList(head, 0));
}