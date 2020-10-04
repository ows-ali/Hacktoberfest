using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu7
{
    public static class BorrowerSpeak
    {
        public static string Borrow(string s)
        {
            s = s.ToLower();

            return System.Text.RegularExpressions.Regex.Replace(s, @"[^\w\s.!@$%^&*()\-\/]+", "");
        }

        public static string Better(string s) => System.Text.RegularExpressions.Regex.Replace(s, @"[^\w]", "").ToLower();
    }
}