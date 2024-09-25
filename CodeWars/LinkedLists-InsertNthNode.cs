using System;

public partial class Node
{
    public int Data;
    public Node Next;

    public Node(int data)
    {
        this.Data = data;
        this.Next = null;
    }

    public static Node InsertNth(Node head, int index, int data)
    {

        if (index < 0)
            throw new ArgumentOutOfRangeException(nameof(index), "Index is out of the range of the list.");

        var newNode = new Node(data);

        if (index == 0)
        {
            newNode.Next = head;
            return newNode;
        }

        var current = head;
        int count = 0;

        while (current != null && count < index - 1)
        {
            current = current.Next;
            count++;
        }

        if (current == null)
        {
            throw new ArgumentOutOfRangeException(nameof(index), "Index is out of the range of the list.");
        }

        newNode.Next = current.Next;
        current.Next = newNode;

        return head;

    }
}