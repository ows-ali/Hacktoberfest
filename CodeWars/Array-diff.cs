using System;
using System.Collections;
using System.Collections.Generic;

public class Kata
{
    public static int[] ArrayDiff(int[] a, int[] b)
    {
        var hashSet = new HashSet<int>(b);
        var response = new List<int>();

        foreach (var x in a)
        {
            if (!hashSet.Contains(x))
            {
                response.Add(x);
            }
        }

        return response.ToArray();
    }
}