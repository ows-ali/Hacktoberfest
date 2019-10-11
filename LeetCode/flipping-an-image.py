# Question's Link: https://leetcode.com/problems/flipping-an-image/

class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in range(len(A)):
            l=[]
            for j in range(len(A[i])-1,-1,-1):
                if A[i][j]==1:
                    l.append(0)
                else:
                    l.append(1)
                
            A[i]=l
        return A
            
            
