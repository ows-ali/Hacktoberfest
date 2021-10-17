import java.lang.*;
import java.util.InputMismatchException;
import java.util.Scanner;

class JavaAray {
    public static void main(String args[])
    {
        int n;
        int arr[];
        Scanner sc=new Scanner(System.in);
        try{
            n=sc.nextInt();
            arr[]=new int[n];
            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextInt();
                System.out.println();
            }

            for(int i=0;i<n;i++)
            {
                System.out.println(arr[i]);
            }

        }
        catch(InputMismatchException ex){
            System.out.println("Only integers are allowed ");
        }
        

    }
}