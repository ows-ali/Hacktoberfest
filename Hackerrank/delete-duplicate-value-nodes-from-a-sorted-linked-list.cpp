#https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist == NULL){
        return NULL;
    }else if(llist->next == NULL){
        return llist;
    }else{
        SinglyLinkedListNode* curr = llist;        
        while(curr->next != NULL){
            if(curr->data == curr->next->data){
                curr->next = curr->next->next;
            }else{
              curr = curr->next;
            }
        }
        return llist;
    }

}

