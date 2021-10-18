struct ListNode {
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	ListNode *runner1 = head, *runner2 = head;        
    if(head == nullptr) return false;
    if(head->next == nullptr) return false;
 	// Check if cycle if valid node   
    while(runner1->next != nullptr && runner2->next != nullptr && runner2->next->next != nullptr){
        runner1 = runner1->next;
        runner2 = runner2->next->next;
        if(runner1 == runner2) return true;
    }
    return false;
}