using System;
using System.Collections.Generic;
using System.IO;
class Solution {

    static int stringReduction (string a) {
        int[] ar = new int[3];
            for(int i = 0; i < a.Length; i++)
            {
                if(a[i] == 'a')
                {
                    ar[0]++;
                }else if(a[i] == 'b')
                {
                    ar[1]++;
                }
                else
                {
                    ar[2]++;
                }
            }

            if((ar[0] == 0 && ar[1] == 0) || (ar[1]== 0 && ar[2] == 0)||(ar[0] == 0 && ar[2] == 0))
            {
                return a.Length;
            }

            if ((ar[0] % 2 == 0 && ar[1] %2== 0) && (ar[1] %2 == 0 && ar[2] %2== 0))
            {
                return 2;
            }

            if ((ar[0] % 2 == 1 && ar[1] % 2 == 1) && (ar[1] % 2 == 1 && ar[2] % 2 == 1))
            {
                return 2;
            }

            return 1;
    }

    static void Main(String[] args) {
        int res;
        int _t_cases = Convert.ToInt32(Console.ReadLine());
        for (int _t_i=0; _t_i<_t_cases; _t_i++) {
            String _a = Console.ReadLine();
            res=stringReduction(_a);
            Console.WriteLine(res);
        }
    }
}
