#include <iostream>
#include <vector>

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

void traceInorder(TreeNode *root, vector<int> &inorder)
{
    if (root)
    {
        traceInorder(root->left, inorder);
        inorder.push_back(root->val);
        traceInorder(root->right, inorder);
    }
}

int minDiffInBST(TreeNode *root)
{
    vector<int> inorder;
    traceInorder(root, inorder);
    int inorderLen = inorder.size(), ans = INT16_MAX;
    for (int i = 0; i < inorderLen - 1; i++)
    {
        ans = min(inorder[i] - inorder[i - 1], ans);
    }
    return ans;
}

int main()
{
    TreeNode leftChildL4(519);
    TreeNode leftChildL3 = (1277, &leftChildL4, NULL);
    TreeNode rightChildL3(2776);
    TreeNode rightChildL2(2236, &leftChildL3, &rightChildL3);
    TreeNode root(0, NULL, &rightChildL2);

    minDiffInBST(&root);

    return 0;
}