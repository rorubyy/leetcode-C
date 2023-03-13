#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isMirror(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}
int main()
{
    TreeNode leftChildL2(3);
    TreeNode leftChildR2(4);
    TreeNode leftChildL1(2, &leftChildL2, &leftChildR2);
    TreeNode rightChildL2(4);
    TreeNode rightChildR2(3);
    TreeNode rightChildL1(2, &rightChildL2, &rightChildR2);
    TreeNode root(1, &leftChildL1, &rightChildL1);

    isSymmetric(&root);

    return 0;
}