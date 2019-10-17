package com.company;

public class PracticeCode {

    public static void main(String[] args) {
        // write your code here

        int[] A = new int[]{4, 2, 1, 6, 5};
        int[] B = new int[]{3, 2, 1, 7, 7};

        Solution.solution(A, B);

    }

    static class Solution {
        public static int solution(int[] A, int[] B) {

            for (int i = 0; i < A.length; i++) {

                if (A[i] > B[i]) {

                    boolean flag = true;

                    for (int j = 0; j < A.length; j++) {

                        if (B[i] == A[j]) {
                            flag = false;
                            break;
                        }

                    }

                    if (flag) {
                        int temp = A[i];
                        A[i] = B[i];
                        B[i] = temp;
                    }

                }


            }

            int count = 1;
            for (int i = 0; i < A.length; i++) {

                if (A[i] == count) {
                    count++;

                    i = -1;
                }

            }

            System.out.println(count);

            return count;
        }
    }

}