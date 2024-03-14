package Codewars;
/*
 * URL: https://www.codewars.com/kata/53369039d7ab3ac506000467/train/java
 */

import java.util.InputMismatchException;
import java.util.Scanner;

public class YESORNO {
    public static void main(String[] args) throws InputMismatchException{

        try (Scanner sc = new Scanner(System.in)) {
            boolean arg = sc.nextBoolean();
            System.out.println(boolToWord(arg));
        }catch(InputMismatchException ex){
        }
    }

    public static String boolToWord(boolean b) {
        if (b) return "Yes";
        return "No";
    }
    
}
