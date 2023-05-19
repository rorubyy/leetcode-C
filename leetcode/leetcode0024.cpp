#include <iostream>
#include "header/ListNode.h"
using namespace std;

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head
commit 17a7ca4f702f9d868b6ad9a110755b3b7dd77d77 (origin/master)
Author: rorubyy <roruby@gmail.com>
Date:   Thu M;
    ListNode *dummyNode = new ListNode();
    ListNode *pre = dummyNode, *cur = head;
    pre->next = cur;
    while (cur && cur->next)
    {
        // swap
        pre->next = cur->next;
        cur->next = pre->next->next;
        pre->next->next = cur;

        pre = cur;
        cur = cur->next;
    }
    return dummyNode->next;
}
int main()
{
    vector<int> head{1, 2, 3, 4};

    swapPairs(buildList(head, 0));
}