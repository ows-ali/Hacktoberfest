using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Numerics;
using System.Diagnostics;

namespace ConsoleApplication
{

    class Program
    {
        public static void Main(String[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int k = int.Parse(Console.ReadLine());
            decimal[] ar = new decimal[n + 1];
            for(int i = 1; i <= n; i++)
            {
                ar[i] = int.Parse(Console.ReadLine());
            }
            decimal[] s = new decimal[n + 1];
            Array.Sort<decimal>(ar);

            for(int i = 1; i < n; i++)
            {
                s[i] = ar[i] + s[i - 1];
            }

            int val = 1 - k;
            decimal sum = 0;
            for(int  i = 1; i <= k; i++)
            {
                sum += val*ar[i];
                val += 2;
            }

            decimal prev = sum;

            for(int i = k + 1; i <= n; i++)
            {
                decimal newSum = (k - 1) * ar[i];
                newSum += prev;
                newSum += (k - 1) * ar[i - k];
                newSum -= 2 * (s[i - 1] - s[i - k]);

                if(newSum <= sum)
                {
                    sum = newSum;
                }
                prev = newSum;
            }

            Console.WriteLine(sum);
        }
    }
}