class Solution {
    public int searchInsert(int[] nums, int target) {
        
        int result = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                result = i;
                break;
            } else if (nums[i] < target) {
                result++;
            }
            
        
        }
        
        return result;
    }
}
