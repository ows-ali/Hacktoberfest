let twoSum = function(nums, target) {
    let indices = {};
    nums.forEach((item, index) => {
        indices[item] = index;
    })
    for(let i = 0; i<=nums.length; i++){
        let r = target - nums[i];

        if(indices[r] !== undefined && i !== indices[r]){
            return [i, indices[r]]
        }
    }
}