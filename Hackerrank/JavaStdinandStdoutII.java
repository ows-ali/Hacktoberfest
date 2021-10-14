import java.io.*;
import java.util.*;

public class JavaStdinandStdoutII {
    public static void main(String[] args) {
        Scanner myscanner = new Scanner(System.in);
        
        int first = myscanner.nextInt();
        double second = myscanner.nextDouble();
        myscanner.nextLine();
        String third = new String(myscanner.nextLine());
                   
        System.out.println("String: " + third);
        System.out.println("Double: " + second);
        System.out.println("Int: " + first);
    }
}
