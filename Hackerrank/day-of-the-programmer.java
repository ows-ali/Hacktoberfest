import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the dayOfProgrammer function below.
    static String dayOfProgrammer(int year) {
        boolean leap=false;
        String day;
        int d=13,m=9;
        leap =(year%4==0);
        if(year>1918){
            if(year%400==0)leap=true;
            else if(year%4==0&&year%100!=0)leap=true;
            else leap=false;
        }
        if(leap)d--;
        if(year==1918)d=26;
        if(d<10&&m<10)
        day= "0"+d+".0"+m+"."+year;
        else if(d<10)
        day= "0"+d+"."+m+"."+year;
        else if(m<10)
        day= d+".0"+m+"."+year;
        else 
        day= d+"."+m+"."+year;
        return day;
        
    
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int year = Integer.parseInt(bufferedReader.readLine().trim());

        String result = dayOfProgrammer(year);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
