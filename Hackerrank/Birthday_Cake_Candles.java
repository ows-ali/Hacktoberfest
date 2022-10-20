import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Birthday_Cake_Candles {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int tallest = 0;
        int frequency = 0;
       
        for(int i=0; i < n; i++){
            int height = in.nextInt();
            
            if(height > tallest){
                tallest = height;
                frequency = 1;
            }
            else if(height == tallest) frequency++;
        }
        System.out.println(frequency);
    }
}
