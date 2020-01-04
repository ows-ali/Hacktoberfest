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

    static String dayOfProgrammer(int y) {
        String date = "";
        if(y>=1700 && y<=1917){
            if(y%4==0){
                date = date + "12.09." + y;
            }
            else{
                date = date + "13.09." + y;
            }
        }
        else if(y==1918){
            if(y%4==0){
                date = date + "25.09." + y;
            }
            else{
                date = date + "26.09." + y;
            }
        }
        else if(y>=1919){
             if( (y%4==0 && y%100!=0) || y%400==0 ){
                date = date + "12.09." + y;
            }
            else{
                date = date + "13.09." + y;
            }
        }

        return date;
    }

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int y = s.nextInt();
        String ans = dayOfProgrammer(y);
        System.out.print(ans);
       
    }

}
