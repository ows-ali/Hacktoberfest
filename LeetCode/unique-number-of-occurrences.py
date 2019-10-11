# Question Link: https://leetcode.com/problems/unique-number-of-occurrences/

class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        l=[]
        c=[]
        for i in arr:
            if i in l:
                continue
            l.append(i)
            if arr.count(i) in c:
                return False
            c.append(arr.count(i))
        return True
    
