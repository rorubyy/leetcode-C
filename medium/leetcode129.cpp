#include <iostream>
#include <queue>

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
int dfs(TreeNode *root, int sum)
{
    if (!root)
        return 0;
    sum = sum * 10 + root->val;
    if (!root->left && !root->right)
        return sum;
    return dfs(root->left, sum) + dfs(root->right, sum);
}
int sumNumbers(TreeNode *root)
{
    int sum = 0;
    dfs(root, sum);
}
int main()
{
    TreeNode leftChildL2(5);
    TreeNode leftChildR2(1);
    TreeNode leftChildL1(9, &leftChildL2, &leftChildR2);
    TreeNode rightChildL2(0);
    TreeNode root(4, &leftChildL1, &rightChildL2);
    sumNumbers(&root);

    return 0;
}