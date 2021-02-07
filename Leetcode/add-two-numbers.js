//https://leetcode.com/problems/add-two-numbers/

var addTwoNumbers = function(l1, l2) {
  const head = new ListNode();
  let current = head;
  let carry = 0;
  while (l1 || l2 || carry) {
    current.next = new ListNode();
    current = current.next;
    let val = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
    carry = val >= 10 ? 1 : 0;
    current.val = val % 10;
    l1 = l1 ? l1.next : null;
    l2 = l2 ? l2.next : null;
  }
  return head.next;
};