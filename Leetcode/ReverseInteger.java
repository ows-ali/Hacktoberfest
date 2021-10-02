// Problem Statement:- https://leetcode.com/problems/reverse-integer/

class Solution {
    public int reverse(int x) {
        long rev = 0;        
        while(x!=0){
            rev = rev*10 + (x%10);
            x = x /10;
        }
        if(rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE) return 0;
        return (int) rev;
    }
}
