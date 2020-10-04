using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu7
{
    public static class BreakingChocolate
    {
        public static int BreakChocolate(int n, int m)
        {
            if (n==0 || m==0)
            {
                return 0;
            } else
            {
                return (n * m) - 1;
            }
        }
    }
}
