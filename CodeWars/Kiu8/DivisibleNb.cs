using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu8
{
    public static class DivisibleNb
    {
        public static bool isDivisible(long n, long x, long y)
        {
            if (n%x == 0 && n%y == 0) { return true; } else { return false; }
        }
    }
}