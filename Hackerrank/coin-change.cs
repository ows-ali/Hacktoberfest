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
        public static long[,] dp = new long[52, 252];

        public static void Main(String[] args)
        {
            int[] l0 = Array.ConvertAll<string, int>(Console.ReadLine().Trim().Split(' '), e => int.Parse(e));
            int[] coins = Array.ConvertAll<string, int>(Console.ReadLine().Trim().Split(' '), e => int.Parse(e));
            int sum = l0[0];
            int n = l0[1];
            for(int i = 0; i < 52; i++)
            {
                for(int j = 0; j < 252; j++)
                {
                    dp[i, j] = -1;
                }
            }

            Console.WriteLine(calculate(coins, sum, n - 1, 0));
        }

        public static long calculate(int[] coins, int sum, int numCoin, int i)
        {
            if(sum == 0)
            {
                return 1;
            }

            if(sum < 0)
            {
                return 0;
            }

            if(i > numCoin)
            {
                return 0;
            }

            if(dp[i, sum] == -1)
            {
                dp[i, sum] = calculate(coins, sum, numCoin, i + 1) + calculate(coins, sum - coins[i], numCoin, i);
            }

            return dp[i, sum];
        }
    }
}