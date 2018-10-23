#https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem

bool has_cycle(Node* head) {

    if (head == NULL || head->next == NULL){
        return false;
    }
    else{
        Node *runner = head->next->next;
            
        while (runner != NULL && runner != head){
            runner = runner->next->next;
            head = head->next;
        }
        if (runner == NULL){
            return false;
        }
        else{
            return true;
        }
    }
}
