/*
  https://leetcode.com/problems/plus-one/
*/

class Solution {
    public int[] plusOne(int[] digits) {
        int[] sum = new int[digits.length + 1];
        
        //init
        int carry = 1;
        int s = 0;
        
        for (int i = sum.length - 1; i >= 0; i--) {
            s = (i == 0) ? carry : digits[i - 1] + carry;
            sum[i] = s % 10;
            carry = s / 10;
        }
        
        int len = 0;
        boolean newarr = false;
        if (sum[0] == 0) {
            len = sum.length - 1;
            newarr = true;
        }
        if (newarr) {
            int[] temp = new int[len];

            for (int i = 0; i < len; i++) {
                temp[i] = sum[i + 1];
            }
        
            return temp;
        } else {
            return sum;
        }
        
    }
}