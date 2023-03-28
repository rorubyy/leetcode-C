#include <iostream>
#include <queue>
#include <vector>
#include "header/TreeNode.h"

using namespace std;


bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> bfsQ;
    if (!root)
        return true;
    bfsQ.push(root);

    while (bfsQ.front() != nullptr)
    {
        TreeNode *cur = bfsQ.front();
        bfsQ.push(cur->left);
        bfsQ.push(cur->right);
        bfsQ.pop();
    }
    while (!bfsQ.empty() && bfsQ.front() == nullptr)
    {
        bfsQ.pop();
    }
    return bfsQ.empty();
}

int main()
{
    vector<int> arr = {1, 2, 3, NULL, 5};
    isCompleteTree(buildTree(arr, 0));
    return 0;
}