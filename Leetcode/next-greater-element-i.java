class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int a[] = new int[nums1.length];
        int c=0,j;
        for(int i=0;i<nums1.length;i++){
            for(j=0;j<nums2.length;j++){
                if(nums1[i]==nums2[j]){
                    j++;
                    if(j>=nums2.length)
                        a[c++]=-1;
                    else {
                    for(int k=j;k<nums2.length;k++){
                       if(nums2[k]>nums1[i]){
                            a[c]=nums2[k];
                           break;
                        }
                        else
                            a[c]=-1;
                }c++;}
            }
        }
       
    } return a;
}
}
