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

int maxDepth(TreeNode *root)
{
    return (root == NULL) ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    TreeNode leftChildL2(15);
    TreeNode rightChildL2(7);
    TreeNode rightChildL1(20, &leftChildL2, &rightChildL2);

    TreeNode leftChildL1(9);
    TreeNode root(3, &leftChildL1, &rightChildL1);

    maxDepth(&root);

    return 0;