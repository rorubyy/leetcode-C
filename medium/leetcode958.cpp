#include <iostream>
#include <queue>
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

bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> bfsQ;
    if (!root)
        return true;
    bfsQ.push(root);

    while (bfsQ.front() != nullptr)
    {
        TreeNode *cur = bfsQ.front();
        bfsQ.push(cur->left);
        bfsQ.push(cur->right);
        bfsQ.pop();
    }
    while (!bfsQ.empty() && bfsQ.front() == nullptr)
    {
        bfsQ.pop();
    }
    return bfsQ.empty();
}
TreeNode *buildTree(vector<int> &arr, int index)
{
    TreeNode *root = nullptr;
    if (index < arr.size() && arr[index] != NULL)
    {
        root = new TreeNode(arr[index]);
        root->left = buildTree(arr, 2 * index + 1);
        root->right = buildTree(arr, 2 * index + 2);
    }
    return root;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int index = 0;
    isCompleteTree(buildTree(arr,0));
    return 0;
}