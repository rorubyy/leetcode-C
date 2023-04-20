#include <iostream>
#include <queue>
#include "header/TreeNode.h"

using namespace std;
unsigned long maxVal(unsigned long a, unsigned long b)
{
    return a > b ? a : b;
}
int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, unsigned long>> q;
    unsigned long maxWidth = 0;

    if (!root)
        return 0;

    q.push({root, 1});
    // BFS
    while (!q.empty())
    {
        unsigned long strIdx = q.front().second, endIdx = q.back().second, levelSize = q.size();
        maxWidth = maxVal(maxWidth, endIdx - strIdx + 1);
        while (levelSize--)
        {
            TreeNode *cur = q.front().first;
            unsigned long curIdx = q.front().second;
            if (cur->left)
            {
                q.push({cur->left, curIdx * 2});
            }
            if (cur->right)
            {
                q.push({cur->right, curIdx * 2 + 1});
            }
            q.pop();
        }
    }
    return maxWidth;
}

int main()
{
    vector<int> arr{1, 3, 2, 5, NULL, NULL, 9, 6, NULL, NULL, NULL, NULL, NULL, 7, NULL};
    TreeNode *root = buildTree(arr, 0);
    widthOfBinaryTree(root);
}