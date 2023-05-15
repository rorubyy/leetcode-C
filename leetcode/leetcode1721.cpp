#include <iostream>
#include "header/ListNode.h"
using namespace std;
void swap(ListNode *left, ListNode *right)
{
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
}
ListNode *swapNodes(ListNode *head, int k)
{
    int n = 1;
    ListNode *cur = head, *left_ptr = head, *right_ptr = head;
    while (cur)
    {
        if (n < k)
            left_ptr = left_ptr->next;
        if (n > k)
            right_ptr = right_ptr->next;
        cur = cur->next;
        n++;
    }
    swap(left_ptr, right_ptr);
    return head;
}
int main()
{
    vector<int> head{1, 2, 3, 4, 5};
    swapNodes(buildList(head, 0), 2);
}