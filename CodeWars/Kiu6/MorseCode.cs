using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class MorseCode
    {
        public static string Decode(string morseCode)
        {
            StringBuilder text = new StringBuilder();

            var words = morseCode.Trim().Replace("   ", "W").Split('W');

            foreach(string word in words)
            {
                var letter = word.Split(' ');

                foreach (string unicode in letter)
                {
                    // MorseCode.Get can get the letter
                    //text.Append(MorseCode.Get(unicode));
                    text.Append("");
                }

                text.Append(" ");
            }

            return text.Remove(text.Length-1, 1).ToString();
        }
    }
}