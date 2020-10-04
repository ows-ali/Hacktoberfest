using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu8
{
    public static class LostWithoutAMap
    {
        public static int[] LostWithoutAMapFunction(int[] x)
        {
            //Select allows to see all array items.
            return x.Select(i => i*2).ToArray();
        }
    }
}