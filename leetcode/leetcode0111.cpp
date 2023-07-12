#include <iostream>
#include "header/TreeNode.h"
#include <vector>
using namespace std;

int calDepth(TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->left)
        return calDepth(root->right) + 1;
    if (!root->right)
        return calDepth(root->left) + 1;
    return min(calDepth(root->left), calDepth(root->right)) + 1;
}
int minDepth(TreeNode *root)
{
    return calDepth(root);
}
int main()
{
    vector<int> root{1, 2, 3, 4, 5};
    // vector<int> root{0, 2, 4, 1, -100001, 3, -1, 5, 1, -100001, -100001, 6, -100001, 8, -100001};
    minDepth(buildTree(root, 0));
}