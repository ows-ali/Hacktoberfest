using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {

    /*
     * Complete the timeConversion function below.
     */
    static string timeConversion(string s) {
         string time = "";
         string hours = Convert.ToString(s[0]) + Convert.ToString(s[1]);
         char isNight = s[s.Length - 2];
         for(int i = 0; s[i] != 'P' && s[i] != 'A'; i++) {
             time += s[i];
         }
         int h = Convert.ToInt32(hours);
         if((isNight == 'A' && h < 12) || (isNight == 'P' && h== 12)) {
             return time;
         } else {
             
             if(h == 12) {
                 h = 00;
             }else {
                 h += 12;
             }
        
             hours = Convert.ToString(h);
             if(hours[0] == '0') {
                 hours ="00";
             }
             time = time.Remove(0, 2);
             
             time = time.Insert(0, Convert.ToString(hours[0]));
             time = time.Insert(1, Convert.ToString(hours[1]));
             return time;
         }

    }

    static void Main(string[] args) {
        TextWriter tw = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = timeConversion(s);

        tw.WriteLine(result);

        tw.Flush();
        tw.Close();
    }
}