var sortArrayByParity = function(A) {
    let even = [];
    let odd = [];
    for (let i=0;i<A.length;i++){
        if (A[i] % 2 === 0) {
            even.push(A[i])
        } else {odd.push(A[i])}
    }


    return (even.concat(odd))
};
