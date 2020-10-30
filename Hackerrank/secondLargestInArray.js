/**
 *   Return the second largest number in the array.
 **/

const nums = [2, 3, 6, 6, 5];

function getSecondLargest(nums) {
  var first = 0,
    second = 0;

  for (var i = 0; i < nums.length; i++) {
    if (nums[i] > first) {
      second = first;
      first = nums[i];
    } else if (nums[i] > second && nums[i] < first) {
      second = nums[i];
    }
  }
  return second;
}

console.log(getSecondLargest(nums));
