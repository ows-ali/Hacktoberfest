// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> ans;

    void helper(TreeNode *root, int lvl)
    {

        if (ans.size() <= lvl)
        {
            vector<int> temp{root->val};
            ans.push_back(temp);
        }
        else
        {
            ans[lvl].push_back(root->val);
        }

        if (root->left)
            helper(root->left, lvl + 1);
        if (root->right)
            helper(root->right, lvl + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        ans.clear();
        if (root)
            helper(root, 0);
        return ans;
    }
};