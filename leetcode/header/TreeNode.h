#ifndef TREENODE
#define TREENODE

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
TreeNode *buildTree(vector<int> &arr, int index)
{
    TreeNode *root = nullptr;
    if (index < arr.size() && arr[index] >= -100000)
    {
        root = new TreeNode(arr[index]);
        root->left = buildTree(arr, 2 * index + 1);
        root->right = buildTree(arr, 2 * index + 2);
    }
    return root;
}
#endif