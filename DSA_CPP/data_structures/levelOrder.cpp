

/*

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
Example :
Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is 
much greater than number of nodes on a level.
*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
vector<vector<int> > Solution::levelOrder(TreeNode* A)
{
    vector<vector<int>> v;
    
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty())
    {
        int sz = q.size();
        vector<int> v1(sz);
        
        for(auto i=0; i<sz; i++)
        {
            TreeNode *tmp = q.front();
            q.pop();
            
            v1[i] = (tmp->val);
        
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        
        v.push_back(v1);
    }
    
    return v;
}




