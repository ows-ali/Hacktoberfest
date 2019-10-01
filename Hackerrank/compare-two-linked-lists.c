

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode* temp1;
    SinglyLinkedListNode* temp2;
    temp1 = head1;
    temp2 = head2;
    
    while((temp1->data==temp2->data) && (temp1->next!=NULL && temp2->next!=NULL))
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1->data==temp2->data && (temp1->next==NULL && temp2->next==NULL))
        return 1;
    else 
        return 0;

}

