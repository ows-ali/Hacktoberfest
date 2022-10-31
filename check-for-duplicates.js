const singleNonDuplicate = (nums) => {
    let num = [];
    binarySearch(nums, 0, nums.length - 1, num);
    return num[0];
};

const binarySearch = (nums, l, h, num) => {
    if(l <= h){
        const mid = Math.ceil((l + h) / 2);
        
        //if the next and prev element are different than current that means it is a single element.
        if(nums[mid] !== nums[mid + 1] && nums[mid] !== nums[mid - 1]){
                num.push(nums[mid]);
                return;
        }

        binarySearch(nums, mid + 1, h, num);
        binarySearch(nums, l, mid - 1, num);
    }
}Copy
Input:
console.log(singleNonDuplicate([1,1,2,2,3,3,3,4,4,4,4,8,8,10]));
console.log(singleNonDuplicate([1,1,2,2,2,3,4,4,4,4,8,8]));

Output:
10
3
