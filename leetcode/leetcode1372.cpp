#include "header/TreeNode.h"
#include <vector>
#include <iostream>

using namespace std;
void dfs(int cnt, int dir, TreeNode *root, int &maxLen)
{
    maxLen = max(maxLen, cnt);
    if (!root)
        return;

    if (dir == 0) //go left
    {
        cnt += 1;
        dfs(cnt, 1, root->right, maxLen);
        dfs(0, 0, root->left, maxLen);
    }
    else //g right
    {
        cnt += 1;
        dfs(cnt, 0, root->left, maxLen);
        dfs(0, 1, root->right, maxLen);
    }
}

int longestZigZag(TreeNode *root)
{
    int maxLen = 0;
    dfs(0, 0, root->left, maxLen); // dir left=0,right=1
    dfs(0, 1, root->right, maxLen);
    return maxLen;
}

int main()
{
    vector<int> arr{1, NULL, 1, NULL, NULL, 1, 1, NULL, NULL, NULL, NULL, NULL, NULL, 1, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL, NULL};
    longestZigZag(buildTree(arr, 0));
    return 0;
}