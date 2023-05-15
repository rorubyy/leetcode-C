#ifndef TREENODE
#define TREENODE

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *buildList(vector<int> &arr, int index)
{
    ListNode *root = nullptr;
    if (index < arr.size() && arr[index])
    {
        root = new ListNode(arr[index]);
        root->next = buildList(arr, index + 1);
    }
    return root;
}
#endif