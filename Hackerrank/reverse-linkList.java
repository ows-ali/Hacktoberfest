import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static class SinglyLinkedListNode {
        public int data;
        public SinglyLinkedListNode next;

        public SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    static class SinglyLinkedList {
        public SinglyLinkedListNode head;
        public SinglyLinkedListNode tail;

        public SinglyLinkedList() {
            this.head = null;
            this.tail = null;
        }

        public void insertNode(int nodeData) {
            SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

            if (this.head == null) {
                this.head = node;
            } else {
                this.tail.next = node;
            }

            this.tail = node;
        }
    }

    public static void printSinglyLinkedList(SinglyLinkedListNode node, String sep) {
        while (node != null) {
            System.out.print(node.data);

            node = node.next;

            if (node != null) {
                System.out.print(sep);
            }
        }
    }

    class Result {


        public static void reversePrint(SinglyLinkedListNode llist) {

            SinglyLinkedListNode prev = null;
            SinglyLinkedListNode current = llist;
            SinglyLinkedListNode next = null;
            while (current != null) {
                next = current.next;
                current.next = prev;
                prev = current;
                current = next;
            }
            llist = prev;

            while (llist != null) {
                System.out.print(llist.data + " ");
                llist = llist.next;
            }

        }

        private static final Scanner scanner = new Scanner(System.in);

        public static void main(String[] args) {
            int tests = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int testsItr = 0; testsItr < tests; testsItr++) {
                SinglyLinkedList llist = new SinglyLinkedList();

                int llistCount = scanner.nextInt();
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int i = 0; i < llistCount; i++) {
                    int llistItem = scanner.nextInt();
                    scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                    llist.insertNode(llistItem);
                }

                reversePrint(llist.head);
            }

            scanner.close();
        }
    }
