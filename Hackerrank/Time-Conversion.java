import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the timeConversion function below.
     */
    static String timeConversion(String s) {
        /*
         * Write your code here.
         */
    String hr=s.substring(0,2);
    String min=s.substring(3,8);
    int h=Integer.parseInt(hr);
    String result;
    if(s.charAt(8)=='P'){
      if(h!=12){h=h+12;}  
    }
    if(s.charAt(8)=='A'){
      if(h==12){h=0;}
    }
    if(h>9){
      result=h+":"+min;
    }
    else{
   result="0"+h+":"+min;
    
    }
    return result;
    }
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scan.nextLine();

        String result = timeConversion(s);

        bw.write(result);
        bw.newLine();

        bw.close();
    }
}
