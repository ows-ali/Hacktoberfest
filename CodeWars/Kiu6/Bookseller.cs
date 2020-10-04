using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class Bookseller
    {
        public static string stockSummary(string[] lstOfArt, string[] lstOf1stLetter)
        {
            StringBuilder result = new StringBuilder();
            
            if(lstOfArt.Length == 0 || lstOf1stLetter.Length == 0)
            {
                result.Append("");
            } else
            {
                foreach (string key in lstOf1stLetter)
                {
                    result.Append("(" + key + " : ");
                    int sum = 0;

                    foreach (string book in lstOfArt)
                    {
                        if (string.Equals(key, book.Substring(0, 1)))
                        {
                            sum += Int32.Parse(book.Substring(book.IndexOf(" ")));
                        }
                    }
                    result.Append(sum + ") - ");
                }
                if (result.Length > 1) result.Remove(result.Length - 3, 3);
            }
            
            return result.ToString();
        }
    }
}