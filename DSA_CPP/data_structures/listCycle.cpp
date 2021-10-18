/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
Example :
Input : 
                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4
Return the node corresponding to node 3. 

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 
 ListNode* Solution::detectCycle(ListNode* A)
{
    ListNode *slow, *fast, *st;

    slow = fast = head;
    
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            st = head;

            while (slow != st)
            {
                st = st->next;
                slow = slow->next;
                return st;
            }
         }
    }
    
    return NULL;
    
}




