import java.io.IOException;
import java.util.Scanner;
import java.lang.Math;

//Original problem URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1017

public class Main {
 
    public static void main(String[] args) throws IOException {
 
        Scanner in = new Scanner(System.in);
        float x1 = in.nextFloat();
        float y1 = in.nextFloat();
        float x2 = in.nextFloat();
        float y2 = in.nextFloat();
        
        double total = Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2));
        
        System.out.printf("%.4f\n", total);
 
    }
 
}