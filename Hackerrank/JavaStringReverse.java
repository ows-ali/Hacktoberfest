import java.io.*;
import java.util.*;

/**
 * Given a string , print Yes if it is a palindrome, print No otherwise.
 * 
 */
public class JavaStringReverse {

    public static void main(String[] args) {
        
		Scanner sc = new Scanner(System.in);
		String A = sc.next();
		
		StringBuilder sb = new StringBuilder(A);
		
		if (sb.reverse().toString().equals(A)) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		
		sc.close();
    }
}