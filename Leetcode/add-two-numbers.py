# From https://leetcode.com/problems/add-two-numbers/
# Solution done in Python 3

# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.addTwoNumbers(self,l1,l2)
    
    def addTwoNumbers(self,l1,l2,carry=0) -> ListNode:
        
        #Invoke our base case when we have no more nodes in the next state
        if(l1 is None and l2 is None and carry == 0):
            return None
        
        result = ListNode(carry)
        value = carry
        
        if(l1 is not None):
            value = value + l1.val
        
        if(l2 is not None):
            value = value + l2.val
            
        result.val = value%10
        
        #Use recursion to calculate the next item in result
        result.next = self.addTwoNumbers(l1.next if l1 != None else None,
                                 l2.next if l2 !=None else None,
                                 1 if value>=10 else 0)
        
        return result