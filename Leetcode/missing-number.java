import java.util.*;

public class power_set {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a String  for Power sets");
        int arrp[] = { 1, 2, 3, 5 };
        int missing_num = missingNumber(arr);
        System.out.println("Missing number --> " + missing_num);
        sc.close();
    }

    public int missingNumber(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            // Calcualting XOR of all the elements in the array
            // res = arr[0] ^ arr[1] ^ .....
            res ^= nums[i];
        }

        for (int i = 0; i <= nums.length; i++) {
            // XOR of all the elements in the arrry with total range elements
            // USing the XOR properties repeating elements cancel each other
            // Atlast Missing ( non repeating ) element is left behind in the result
            // variable
            res = res ^ i;
        }
        return res;

    }
}
