using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu7
{
    public static class Mumbling
    {
        public static String Accum(string s)
        {
            char[] arr = s.ToLower().ToCharArray();
            StringBuilder str = new StringBuilder();

            for (int i = 0; i < arr.Length; i++)
            {
                for (int z = 0; z <= i; z++)
                {
                    if(z == 0)
                    {
                        str.Append(Char.ToUpper(arr[i]));
                    } else
                    {
                        str.Append(arr[i]);
                    }
                }
                str.Append("-");
            }
            str.Remove(str.Length-1, 1);
            return str.ToString();
        }
    }
}