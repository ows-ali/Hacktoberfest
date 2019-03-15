/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res=new ListNode(0);
        ListNode curr=res;
        int r=0,c=0,x;
        ListNode last1=l1;
        ListNode last2=l2;
        while(last1!=null && last2!=null){
            x=last1.val+last2.val+r;
            r=x/10;
            //System.out.println(r);
           curr.next=new ListNode(x%10);
            curr=curr.next;
           if(last1!=null) last1=last1.next;
           if(last2!=null) last2=last2.next;
        }

        System.out.println(r);
        while(last1!=null){
            x=last1.val+r;
            r=x/10;
           curr.next=new ListNode(x%10); 
            curr=curr.next;
            last1=last1.next;
        }
        while(last2!=null){
            x=last2.val+r;
            r=x/10;
           curr.next=new ListNode(x%10);
            curr=curr.next;
            last2=last2.next;   
        }
        if(r>0)
            curr.next=new ListNode(r);
         
        
        return res.next;
        
        
    }
}
