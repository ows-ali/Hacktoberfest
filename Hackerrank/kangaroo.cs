using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {
    

    static string kangaroo(int x1, int v1, int x2, int v2,int sx1,int sx2, int counter,string y,string n) {
        
        
        for(int i=x1;i<10000;i++)
        {
            sx1=sx1+v1;
            sx2=sx2+v2;
            if(sx1==sx2)
            {
                counter++;
                break;
            }
            
            
            
        }
        if(counter>0)
            {
                return y;
            }
            
            
                return n;
            
    }

    static void Main(String[] args) {
        
        
        string[] tokens_x1 = Console.ReadLine().Split(' ');
        int x1 = Convert.ToInt32(tokens_x1[0]);
        int v1 = Convert.ToInt32(tokens_x1[1]);
        int x2 = Convert.ToInt32(tokens_x1[2]);
        int v2 = Convert.ToInt32(tokens_x1[3]);
        int sx1,sx2,counter;
        sx1=x1;
        sx2=x2;
        counter=0;
        string y="YES";
        string n="NO";
        string result = kangaroo(x1, v1, x2, v2, sx1,sx2,counter,y,n);
        Console.WriteLine(result);
    }
}
