/**https://leetcode.com/problems/3sum/ */

import java.util.List;
import java.util.Collections;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.HashMap;
import java.util.Map;

class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        Set<Integer> dups = new HashSet<>();
        Map<Integer, Integer> seen = new HashMap<>();
        
        
        for(int i = 0; i < nums.length; i++){
            //returns false if already in set
            if(dups.add(nums[i])){
                for(int j = i+1; j < nums.length; j++){
                    int complement = -nums[i]-nums[j];
                    if(seen.containsKey(complement) && seen.get(complement ) == i){
                        List<Integer> triplet = Arrays.asList(nums[i], nums[j], complement);
                        Collections.sort(triplet);//ensure no repetitions of same numbers in diff positions
                        result.add(triplet);
                    }
                    seen.put(nums[j],i);
                }
            }
        }
        return new ArrayList<>(result);
    
    }

    /**Select Proceed when 'build issue' comes up. The correct output shows up in terminal window  */
    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        ThreeSum results = new ThreeSum();

        System.out.println(results.threeSum(nums));
        
    }
    
    
}