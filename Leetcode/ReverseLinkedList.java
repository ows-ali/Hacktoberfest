// Problem Statement:- https://leetcode.com/problems/reverse-linked-list/

class Solution {
    ListNode previous = null;
    public ListNode reverseList(ListNode head) {
         while(head != null){
          ListNode node = head.next;
             head.next = previous;
             previous = head;
             head = node;
             
         }
        return previous;
    }
}