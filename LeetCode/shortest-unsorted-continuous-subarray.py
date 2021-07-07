# Question's link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        x=0;y=0
        l=sorted(nums)
        m=[]
        for i in range(len(l)):
            l[i]=nums[i]-l[i]
            if l[i]!=0:
                m.append(i)
        x=min(m,default=0)
        y=max(m,default=0)
        
        if x==0 and y==0:
            return 0
        return y-x+1
        
            
                
        
        
