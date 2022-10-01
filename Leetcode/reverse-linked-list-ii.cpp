//https://leetcode.com/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
    
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head,int size) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr && size--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(curr)
        head->next = curr;

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right)
            return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int size = right-left+1;
        while (--left) {
            prev = curr;
            curr = curr->next;
        }
        if(!prev)
          return reverseList(curr,size);

        prev->next = reverseList(curr,size);
        return head;
    }
    
    