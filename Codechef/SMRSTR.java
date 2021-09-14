
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


/**
 * Created by drishti.a on Oct,2019
 */
class smrstr {
    public static void main(String[] args) throws IOException {
        int t,n,q;
        long c;
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        String x;
        t=Integer.parseInt(sc.readLine());
        while(t>0)
        {

            String ar[]=sc.readLine().split(" ");
            n=Integer.parseInt(ar[0]);
            q=Integer.parseInt(ar[1]);
            c=1;
            ar = sc.readLine().split(" ");

            for (int i = 0; i < n; i++) {
                c*=Integer.parseInt(ar[i]);
                if (c > 1000000000)
                    break;

            }
            ar = sc.readLine().split(" ");
            for (int i = 0; i < q; i++) {
                System.out.print((Integer.parseInt(ar[i]) / c) + " ");
            }
            System.out.println();
            t--;
        }
    }
}
