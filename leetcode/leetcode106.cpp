#include <iostream>
#include <queue>
#include <vector>
#include "header/TreeNode.h"
#include <unordered_map>

using namespace std;
TreeNode *buildTreeHelper(int inStr, int inEnd, int postStr, int postEnd, vector<int> &postorder, unordered_map<int, int> &inorderMap)
{
    if (inStr > inEnd || postStr > postEnd)
        return nullptr;
    int curRoot = postorder[postEnd];
    TreeNode *root = new TreeNode(curRoot);
    int inorderRootIdx = inorderMap[curRoot];
    int leftSubtreeLen = inorderRootIdx - inStr;
    root->left = buildTreeHelper(inStr, inorderRootIdx - 1, postStr, postStr + leftSubtreeLen - 1, postorder, inorderMap);
    root->right = buildTreeHelper(inorderRootIdx + 1, inEnd, postStr + leftSubtreeLen, postEnd - 1, postorder, inorderMap);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inorderMap;
    int treeLen = postorder.size();
    for (int i = 0; i < treeLen; i++)
    {
        inorderMap[inorder[i]] = i;
    }
    return buildTreeHelper(0, treeLen - 1, 0, treeLen - 1, postorder, inorderMap);
}

int main()
{
    vector<int> inorder{9, 3, 15, 20, 7}, postorder{9, 15, 7, 20, 3};
    buildTree(inorder, postorder);
    return 0;
}