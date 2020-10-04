using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class StrongestEvenNumber
    {
        public static int strongestEven(int n, int m)
        {
            int result = 0;
            int power = 0;

            for(; n<=m; n++)
            {
                int i = 0;
                int number = n;

                while(number%2==0)
                {
                    number = number / 2;
                    i++;
                }

                if(power < i)
                {
                    result = n;
                    power = i;
                }
            }

            return result;
        }
    }
}