#include <iostream>
#include "header/TreeNode.h"
#include <vector>
#include <queue>

using namespace std;

int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> q;
    int level = 0, ans = -1, maxSum = INT_MIN;
    q.push(root);
    while (!q.empty())
    {
        level++;
        int size = q.size(), temp = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *top = q.front();
            q.pop();
            temp += top->val;
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
        if (temp > maxSum)
        {
            ans = level;
            maxSum = temp;
        }
    }
    return ans;
}
int main()
{
    vector<int> root{1, 7, 0, 7, -8, -100001, -100001};
    maxLevelSum(buildTree(root, 0));
}