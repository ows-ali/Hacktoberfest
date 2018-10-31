// This function returns the number of sub-arrays can be found in a given array
// meeting the criteria below.  The array represents a chocolate bar, with each
// square holding an integer, s=[2, 2, 1, 3, 2]
// We need to find segments where integers sum to the recipient's birth day, d = 4,
// and the length of the segments equal the recipient's birth month, m = 2
// For this example, expected output:
// 2

function birthday(s, d, m) {
    function sumFrag(frag) {
        return frag.reduce((sum, val) => sum += val, 0)
    }
    let segs = 0
    for (let i = 0; i < s.length-m; i++) {
        if (sumFrag(s.slice(i, i+m)) === d) segs++;
    }
    return segs
}