// https://leetcode.com/problems/binary-tree-right-side-view/submissions/

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
    vector<int> solve(TreeNode *root, vector<int> res, int lvl)
    {
        if (root == NULL)
        {
            return res;
        }
        if (res.size() == lvl)
        { // root
            res.push_back(root->val);
        }
        res = solve(root->right, res, lvl + 1); // right
        res = solve(root->left, res, lvl + 1);  // left 
        return res;
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        res = solve(root, res, 0);
        return res;
    }
};