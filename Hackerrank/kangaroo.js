// This algorithm determines whether two 'kangaroos' ever jump into the same
// position simultaneously, given each kangaroo's starting position and 
// jumping distance.  
// x1, v1: integers, starting position and jump distance for kangaroo 1
// x2, v2: integers, starting position and jump distance for kangaroo 2
function kangaroo(x1, v1, x2, v2){
    let i = 1
    while (i < 10000) {
        x1 += v1;
        x2 += v2;
        if (x1 == x2) {
            return 'YES'
        }
        i++
    }
    return 'NO'
}
let x1 = 1, v1 = 3, x2 = 4, v2 = 2
console.log(kangaroo(x1, v1 , x2, v2));