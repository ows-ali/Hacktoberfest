package com.company;

public class PracticeCodility {
    public static void main(String[] args) {
        // write your code here

        System.out.println(Solution.solution("aabcabc", 1));

    }

    static class Solution {
        public static int solution(String S, int K) {

            char[] copyS = S.toCharArray();
            char[] selArr = new char[K];
            for (int i = 0; i < selArr.length; i++) {
                if (i == 0) {
                    selArr[0] = copyS[0];
                    continue;
                }
                selArr[i] = '\0';
            }

            int min = 0, max = 0;

            for (int i = 1; i < copyS.length; i++) {

                boolean midFlag = false;

                for (int j = 0; j < selArr.length; j++) {

                    if (copyS[i] == selArr[j]) {
                        midFlag = false;
                        break;
                    } else if (selArr[j] == '\0') {
                        selArr[j] = copyS[i];
                        midFlag = false;
                        break;
                    } else
                        midFlag = true;
                }

                if (midFlag) {
                    min = i;
                    break;
                }

            }

            if (min == 0) return -1;

            String copyStr = S.substring(min);
            char[] copyStrLen = copyStr.toCharArray();

            for (int k = copyStrLen.length - 1; k > 0; k--) {

                boolean finalFlag = false;

                for (int l = 0; l < selArr.length; l++) {

                    if (copyStrLen[k] == selArr[l]) {
                        finalFlag = false;
                        break;
                    } else finalFlag = true;

                }

                if (finalFlag) {
                    max = k + 1;
                    break;
                }

            }

            copyStr = copyStr.substring(0, max);
            char[] reCheckStr = copyStr.toCharArray();
            boolean reCheckFlag = false;
            for (int m = 1; m < reCheckStr.length; m++) {
                if (reCheckStr[0] != reCheckStr[m]) {
                    reCheckFlag = true;
                    break;
                }
            }

            if (!reCheckFlag) return 1;

            return copyStr.length();
        }

    }
}
