// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     data int32
 *     next *SinglyLinkedListNode
 * }
 *
 */
func reverse(head *SinglyLinkedListNode) *SinglyLinkedListNode {
        var prev *SinglyLinkedListNode = nil
        var current *SinglyLinkedListNode = head 
        var next *SinglyLinkedListNode = nil
        for (current != nil) { 
            next = current.next 
            current.next = prev 
            prev = current 
            current = next 
        } 
        head = prev 
        return head
}
