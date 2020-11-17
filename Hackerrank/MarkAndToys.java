/*https://www.hackerrank.com/challenges/mark-and-toys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting*/

public class Solution {

    // Complete the maximumToys function below.
    static int maximumToys(int[] prices, int k) {
        Arrays.sort(prices);
        int i,sum=0;
        for(i=0;sum<k;++i){
            sum=sum+prices[i];
        }
        return (i-1);

    }
