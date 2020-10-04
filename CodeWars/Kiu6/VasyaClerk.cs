using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeWars.kiu6
{
    public static class VasyaClerk
    {
        public static string Tickets(int[] peopleInLine)
        {
            int _25 = 0;
            int _50 = 0;
            int _100 = 0;
            string possible = "YES";

            foreach (int people in peopleInLine)
            {
                switch (people)
                {
                    case (25):
                        _25 += 1;
                        break;
                    case (50):
                        if(_25 > 0)
                        {
                            _25 -= 1;
                            _50 += 1;
                        } else { possible = "NO"; }
                        break;
                    case (100):
                        if(_50 > 0 && _25 > 0)
                        {
                            _50 -= 1;
                            _25 -= 1;
                            _100 += 1;
                        } else if(_25 > 2)
                        {
                            _25 -= 3;
                            _100 += 1;
                        } else { possible = "NO"; }
                        break;
                }
            }
            return possible;
        }
    }
}