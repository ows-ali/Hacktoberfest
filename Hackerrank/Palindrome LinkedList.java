/*Palindrome LinkedList

Check if a given linked list is palindrome or not. Return true or false.
Indexing starts from 0.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
0 2 3 2 5 -1
Sample Output 2 :
false
*/


/*
class LinkedListNode<T> {
	public T data;
	public LinkedListNode<T> next;

	public LinkedListNode(T data) {
		this.setData(data);
		this.next = null;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

}
* */
public class Solution {
	public static boolean isPalindrome_2(LinkedListNode<Integer> head) {
        if(head == null)
        return true;
 
    LinkedListNode<Integer> p = head;
    LinkedListNode<Integer> prev = new LinkedListNode<Integer> (head.data);
 
    while(p.next != null){
        LinkedListNode<Integer>  temp = new LinkedListNode<Integer> (p.next.data);
        temp.next = prev;
        prev = temp;
        p = p.next;
    }
 
    LinkedListNode<Integer>  p1 = head;
    LinkedListNode<Integer>  p2 = prev;
 
    while(p1!=null){
        if(p1.data != p2.data)
            return false;
 
        p1 = p1.next;
        p2 = p2.next;
    }
 
    return true;
    }
}