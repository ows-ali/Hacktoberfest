using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    class Program
    {
        public static void Main(String[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] ar = Array.ConvertAll<string, int>(Console.ReadLine().Trim().Split(' '), e => int.Parse(e));

            if(isSorted(ar, n))
            {
                Console.WriteLine("yes");
                return;
            }

            int a = -1;
            int b = -1;

            for(int i = 0; i < n - 1; i++)
            {
                if(ar[i] > ar[i + 1])
                {
                    a = i;
                    break;
                }
            }

            for(int i = n - 1; i > 0; i--)
            {
                if(ar[i] < ar[i - 1])
                {
                    b = i;
                    break;
                }
            }

            if(a != -1 && b != -1)
            {
                int temp = ar[a];
                ar[a] = ar[b];
                ar[b] = temp;

                if(isSorted(ar, n))
                {
                    Console.WriteLine("yes");
                    Console.WriteLine($"swap {a + 1} {b + 1}");
                    return;
                }

                ar[b] = ar[a];
                ar[a] = temp;
            }

            int[] nar = new int[n];

            for(int i = 0; i < a; i++)
            {
                nar[i] = ar[i];
            }

            for(int i = 0; i <= b - a; i++)
            {
                nar[a + i] = ar[b - i];
            }

            for(int i = b + 1; i < n; i++)
            {
                nar[i] = ar[i];
            }

            if(isSorted(nar, n))
            {
                Console.WriteLine("yes");
                Console.WriteLine($"reverse {a + 1} {b + 1}");
                return;
            }

            Console.WriteLine("no");
        }

        public static bool isSorted(int[] ar, int n)
        {
            for(int i = 1; i < n; i++)
            {
                if(ar[i] < ar[i - 1])
                {
                    return false;
                }
            }

            return true;
        }
    }
}
