class Solution {
    public int[] dailyTemperatures(int[] T) {
        int a[] = new int[T.length];
        int c=0;
        for(int i=0;i<T.length;i++){
            for(int j=i+1;j<T.length;j++){
                if(T[i]<T[j]){
                    a[c]=j-i;
                    break;
                }
            }c++;
        }
        return a;
    }
}
