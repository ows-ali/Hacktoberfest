// https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

 // Using brute force to find the solution
const twoSum = (nums, target) => {
    
    for(let i = 0; i< nums.length; i++) {
        for(let y = i + 1; y < nums.length; y++) {
            if (nums[i] + num[y] === target) {
                return [i, y]
            }    
        }
    }
};