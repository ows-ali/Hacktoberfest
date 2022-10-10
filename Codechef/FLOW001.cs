using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CODECHEF
{
    public class FLOW001
    {
        public static void Main()
	    {
            int T = int.Parse(Console.ReadLine());

            for (int i = 0; i < T; i++)
            {
                string[] lines = Console.ReadLine().Split(' ');
                int result =  int.Parse(lines[0]) + int.Parse(lines[1]);
                Console.WriteLine(result);
            }
	    }
    }
}