import java.util.*;
class conflip{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int i=1;i<=T;i++){
            int G=sc.nextInt();
            for(int j=1;j<=G;j++){
            int I=sc.nextInt();
            int N=sc.nextInt();
            int Q=sc.nextInt();
            if(N%2!=0){
                if(I==Q){System.out.println((int)Math.floor(N/2));}
                else{System.out.println(N-(int)Math.floor(N/2));}
            }
            else{System.out.println(N/2);}
        }
        }
    }
}