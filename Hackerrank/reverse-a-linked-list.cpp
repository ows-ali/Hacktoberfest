/*approach :
We create three pointers to traverse the current previous and the next node, and with each current node, we modify its next pointer and update the pointer again*/


#include <bits/stdc++.h>
using namespace std;
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if(!llist) return llist;
    
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* next = nullptr;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    
    return prev;
}
