
import java.io.*;
import java.util.*;

public class JavaStringReverse {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        /* Enter your code here. Print output to STDOUT. */
        String copy = "";
        int flag = 0;
        int len = s.length();
        char copy2;
        for (int i = len - 1; i >= 0; i--) {
            copy2 = s.charAt(i);
            copy += copy2;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != copy.charAt(i)) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
