import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int N=0 ;
            int R = 0;
            
            int p;
            
            for (N=0;N<n;++N)
            {
                
                p=(int) Math.pow(2,N);
              if(N>0){
                 R = (p*b)+R;}
              else{
                  R = a+(p*b);}
                   System.out.print(R+" ");
        }
        System.out.print("\n");
     }
        in.close();
}
}