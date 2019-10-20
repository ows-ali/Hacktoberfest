#!/bin/python3
# https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
# INPUT FORMAT
# The first line of input contains , the number of elements in the linked list.
# The next  lines contain one element each, which are the elements of the linked list.
class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node


        self.tail = node

def printLinkedList(head):
    while head:
        print(head.data)
        head = head.next

if __name__ == '__main__':
    llist_count = int(input())

    llist = SinglyLinkedList()

    for _ in range(llist_count):
        llist_item = int(input())
        llist.insert_node(llist_item)

    printLinkedList(llist.head)
