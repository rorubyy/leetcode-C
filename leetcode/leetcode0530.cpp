#include <iostream>
#include "header/TreeNode.h"
#include <vector>
using namespace std;

void inorder(TreeNode *root, int &min_diff, int &val)
{
    if (!root)
        return;
    if (root->left)
        inorder(root->left, min_diff, val);
    if (val != -1)
    {
        min_diff = min(min_diff, root->val - val);
    }
    val = root->val;
    if (root->right)
        inorder(root->right, min_diff, val);
}
int getMinimumDifference(TreeNode *root)
{
    int min_diff = INT_MAX, val = -1;
    inorder(root, min_diff, val);
    return min_diff;
}
int main()
{
    vector<int> root{1, 0, 48, -1, -1, 12, 49};
    getMinimumDifference(buildTree(root, 0));
}