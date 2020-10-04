using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu7
{
    public static class SumOddNumbers
    {
        public static long RowSumOddNumbers(long n)
        {
            long result = 0;
            long number = 0;

            if (n == 1)
            {
                return 1;
            }
            else
            {
                number = n + (long)Math.Pow((n - 1), 2);
                result = number;
                for (int i = 1; i < n; i++)
                {
                    number += 2;
                    result = result + number;
                }
                return result;
            }
        }

        public static long BetterResult(long n)
        {
            return (long)Math.Pow(n, 3);
        }
    }
}