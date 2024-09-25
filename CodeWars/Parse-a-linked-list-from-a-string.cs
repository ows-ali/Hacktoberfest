using System;

public static class Kata
{
    public static Node Parse(string nodes)
    {
        Node head = null;
        Node prev = null;
        var array = nodes.Split(" -> ");

        foreach (var current in array)
        {
            if (current.Trim() == "null")
                break;

            var value = int.Parse(current.Trim());

            var newNode = new Node(value);

            if (head == null)
            {
                head = newNode;
            }
            else
            {
                prev.Next = newNode;
            }

            prev = newNode;
        }

        return head;
    }
}