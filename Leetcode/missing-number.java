import java.util.*;

public class power_set {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a String  for Power sets");
        String str = sc.next();
        System.out.println("Power Set of " + str);
        set_power(str);

        sc.close();
    }

    // We have solved it in O(2^n)
    public static void set_power(String str) {

        for (int i = 0; i < (Math.pow(2, str.length())); i++) {

            for (int j = 0; j < str.length(); j++) {
                // choosing the allowed characters using set bit positions
                if ((i & (1 << j)) != 0) {
                    System.out.print(str.charAt(j) + "");
                }
            }
            System.out.println();
        }

    }

}
