class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if A == []:
            return 0
        A.sort()
        first_sum = A[0]
        prev = A[0]
        new_sum = A[0]
        
        for i in range(1, len(A)):
            curr = A[i]
           
            first_sum += curr
           
            if curr <= prev:
                
                prev +=1
                new_sum += prev
            else:
                
                prev = curr
                new_sum += curr
      
        return new_sum - first_sum