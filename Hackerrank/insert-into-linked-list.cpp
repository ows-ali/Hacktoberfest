#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position)
{

    SinglyLinkedListNode *cur = llist;

    /* initialize new node to be inserted at given position */
    SinglyLinkedListNode *nth = new SinglyLinkedListNode(data);
    nth->data = data;
    nth->next = NULL;

    if (position == 0)
    {
        /* insert new node at head */
        llist = nth;
        llist->next = cur;
        return llist;
    }
    else
    {
        /* traverse list */
        int count = 0;
        SinglyLinkedListNode *pre = new SinglyLinkedListNode(data);

        while (count != position)
        {
            if (count == (position - 1))
            {
                pre = cur;
            }
            cur = cur->next;
            count++;
        }

        /* insert new node here */
        pre->next = nth;
        nth->next = cur;

        return llist;
    }
}