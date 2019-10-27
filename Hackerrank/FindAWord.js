function processData(input) {
    const nums = input.match(/\d+(?=\n)/g)
    const arr = input.replace(/[0-9]+\n/g, '').split('\n')
    let ans;
    let rgx;
    for (let n = parseInt(nums[0]); n < arr.length; n++){
        ans = 0;
        for (let n2 = 0; n2 < parseInt(nums[0]); n2++){
            rgx = new RegExp(`(?<=\\W|\\b)${arr[n]}(?=\\W|\\b)`, 'g')
            ans = ans+getMatch(rgx, arr[n2])
        }
        console.log(ans)
    }
} 

function getMatch(rgx, str){
    return rgx.test(str) ? str.match(rgx).length : 0
}