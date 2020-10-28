import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the largestRectangle function below.
    static long largestRectangle(int[] h) {

        Stack<Integer> st = new Stack<>();
        long max=0;
        int l=h.length;
        st.push(h[0]);
        for(int j=1;j<l;j++)
        {
            //System.out.println(st);
            //System.out.println(st.peek()<=h[j]);
            if(st.peek()<=h[j])
            {
                st.push(h[j]);
            }
            else
            {
                int i=1;
                long area;
                while(st.peek()>h[j])
                {
                    area=i*st.pop();
                    i++;
                    if(max<area)
                        max=area;
                    if(st.isEmpty())
                        break;
                }
                for(;i>0;i--)
                    st.push(h[j]);
                
            }
        }
        int i=1;
        long area;
        while(!st.isEmpty())
        {
            area=i*st.pop();
            i++;
            if(max<area)
                max=area;
        }    
        //System.out.println("maximum area is "+max);
        return max;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] h = new int[n];

        String[] hItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int hItem = Integer.parseInt(hItems[i]);
            h[i] = hItem;
        }

        long result = largestRectangle(h);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
