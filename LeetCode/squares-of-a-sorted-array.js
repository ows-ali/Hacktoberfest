var sortedSquares = function(A) {
    for (let i=0;i<A.length;i++) {
        A[i] = A[i]*A[i]
    }
    for (let j=0;j<A.length;j++) {
        for (let i=0;i<A.length;i++) {
            if (A[i] > A[i+1]) {
                temp = A[i+1]
                A[i+1] = A[i]
                A[i] = temp
            }
        }
    }
    return A
};
