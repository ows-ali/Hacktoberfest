// Given the sample satrix
// 11 2 4
// 4  5 6
// 10 8 -12

// The variable diagonal_from_left refers to the values that are diagonal from the left to the right.
// It starts from the matrix position of (0,0) and (1,1) for the next iteration
// Each iteration, we take the sum of the elements in the matrix that are diagonal from the left to the right.

// The same applies for the variable diagonal_from_right. It refers to the values that are diagonal from the right to the left.
// It starts from the the matrix position of (0, last element of the row in the matrix), (0, 2) in this sample example given

// Since this is a square matrix, we can take the length of the row or the column as the number of times to iterate the loop

function diagonalDifference(arr) {
  let diag_from_left = 0;
  let diag_from_right = 0;
  let column_length = arr[0].length - 1;

  for (let i = 0; i < arr.length; i++) {
    diag_from_left += arr[i][i];

    diag_from_right += arr[i][column_length];

    column_length--;
  }

  return Math.abs(diag_from_left - diag_from_right);
}
