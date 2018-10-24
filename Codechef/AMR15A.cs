using System;

namespace ConsoleApp1
{  

    class Program
    {
        static void Main(string[] args)
        {
            int n;
            int x;
            n = int.Parse(Console.ReadLine());
            int[] weapons = new int[n];
            int eve = 0;
            int odd = 0;
            for (int i=0; i<n; i++)
            {
                x = int.Parse(Console.ReadLine());
                EvenOrOdd(ref eve,ref odd, x);
            }
            if (eve > odd)
            {
                Console.WriteLine("READY FOR BATTLE");
            }
            else
            {
                Console.WriteLine("NOT READY");
            }
            Console.ReadKey();
        }

        private static void EvenOrOdd(ref int e,ref int o, int n)
        {
            if (n % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }
    }
}
