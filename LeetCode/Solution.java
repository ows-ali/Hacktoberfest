package LeetCode;



public class Solution {
    public int[] twoSum(int[] nums, int target) {

        int a=0;

        for (int i = 0; i < nums.length-1; i++) {

            if(nums[i]+nums[i+1]==target){
                a=i;
                break;
            }
            if(a==i) {
                 System.out.println("["+a + "," + (a + 1)+"]");
            }
        }
        return new int[]{};

    }

    public static void main(String[] args) {
Solution s=new Solution();
//s.twoSum();
  m    }
}