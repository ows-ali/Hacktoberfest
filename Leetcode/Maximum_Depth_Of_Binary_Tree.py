class Solution:
    def maxDepth(self,root: Optional[TreeNode])->int:
        if root==None:
            return 0
        return Solution.dfs(root,0)

    def dfs(root,cnt):
        cnt+=1
        l,r=0,0
        if root.left==None and root.right==None:
            return cnt
        if root.left:
            l=Solution.dfs(root.left,cnt)
        if root.right:
            r=Solution.dfs(root.right,cnt)
        return max(l,r)
        