// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/

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
    set<TreeNode *> s;
    stack<TreeNode *> st;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = NULL;
        for (int pre = 0, in = 0; pre < preorder.size();)
        {

            TreeNode *node = NULL;
            do
            {
                node = new TreeNode(preorder[pre]);
                if (root == NULL)
                {
                    root = node;
                }
                if (st.size() > 0)
                {
                    if (s.find(st.top()) != s.end())
                    {
                        s.erase(st.top());
                        st.top()->right = node;
                        st.pop();
                    }
                    else
                    {
                        st.top()->left = node;
                    }
                }
                st.push(node);
            } while (preorder[pre++] != inorder[in] && pre < preorder.size());

            node = NULL;
            while (st.size() > 0 && in < inorder.size() &&
                   st.top()->val == inorder[in])
            {
                node = st.top();
                st.pop();
                in++;
            }

            if (node != NULL)
            {
                s.insert(node);
                st.push(node);
            }
        }

        return root;
    }
};