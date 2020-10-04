using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu8
{
    public static class EvenOrOdd
    {
        public static string EvenOrOddFunction(int number)
        {
            if (number%2 == 0)
            {
                return "Even";
            } else
            {
                return "Odd";
            }
        }
    }
}