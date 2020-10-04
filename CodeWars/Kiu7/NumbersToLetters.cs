using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu7
{
    public static class NumbersToLetters
    {
        public static string Switcher(string[] x)
        {
            StringBuilder sb = new StringBuilder();

            foreach (string st in x)
            {
                switch (st)
                {
                    case "1":
                        sb.Append("z");
                        break;
                    case "2":
                        sb.Append("y");
                        break;
                    case "3":
                        sb.Append("x");
                        break;
                    case "4":
                        sb.Append("w");
                        break;
                    case "5":
                        sb.Append("v");
                        break;
                    case "6":
                        sb.Append("u");
                        break;
                    case "7":
                        sb.Append("t");
                        break;
                    case "8":
                        sb.Append("s");
                        break;
                    case "9":
                        sb.Append("r");
                        break;
                    case "10":
                        sb.Append("q");
                        break;
                    case "11":
                        sb.Append("p");
                        break;
                    case "12":
                        sb.Append("o");
                        break;
                    case "13":
                        sb.Append("n");
                        break;
                    case "14":
                        sb.Append("m");
                        break;
                    case "15":
                        sb.Append("l");
                        break;
                    case "16":
                        sb.Append("k");
                        break;
                    case "17":
                        sb.Append("j");
                        break;
                    case "18":
                        sb.Append("i");
                        break;
                    case "19":
                        sb.Append("h");
                        break;
                    case "20":
                        sb.Append("g");
                        break;
                    case "21":
                        sb.Append("f");
                        break;
                    case "22":
                        sb.Append("e");
                        break;
                    case "23":
                        sb.Append("d");
                        break;
                    case "24":
                        sb.Append("c");
                        break;
                    case "25":
                        sb.Append("b");
                        break;
                    case "26":
                        sb.Append("a");
                        break;
                    case "27":
                        sb.Append("!");
                        break;
                    case "28":
                        sb.Append("?");
                        break;
                    case "29":
                        sb.Append(" ");
                        break;
                    default:
                        sb.Append("");
                        break;
                }
            }

            return sb.ToString();
        }
    }
}