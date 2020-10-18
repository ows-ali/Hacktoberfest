public class MeadianOfArray {
    public static double findMedianOfSortedArray(int[] nums1, int[] nums2){
        int size = nums1.length + nums2.length;
        if (size % 2 == 0) {
            return  (getKth(nums1, 0, nums1.length-1, nums2, 0, nums2.length-1, size/2)
                    + getKth(nums1, 0, nums1.length-1, nums2, 0, nums2.length-1, size/2-1)) / 2.0;
        }else {
            return getKth(nums1,0, nums1.length-1, nums2, 0, nums2.length-1, size/2);
        }
    }

    private static int getKth (int[] nums1, int i1, int j1, int[] nums2, int i2, int j2, int k){
        if (j1 < i1){
            return nums2[i2 + k];
        }
        if (j2 < i2){
            return  nums1[i1 + k];
        }
        if (k == 0){
            return Math.min(nums1[i1], nums2[i2]);
        }
        int len1 = j1 - i1 + 1;
        int len2 = j2 - i2 + 1;
        int m1 = k * len1 / (len1 + len2);
        int m2 = k - m1 -1;
        m1 += i1;
        m2 += i2;
        if (nums1[m1] < nums2[m2]){
            k = k - (m1 - i1 + 1);
            j2 = m2;
            i1 = m1 +1;
        }else {
            k = k - (m2 - i2 + 1);
            j1 = m1;
            i2 = m2+1;
        }
        return  getKth(nums1, i1, j1, nums2, i2, j2, k);
    }

    public static void main(String[] args) {
        int[] nums1 = new int[] {1,2};
        int[] nums2 = new int[] {3 ,4};
        System.out.println(findMedianOfSortedArray(nums1, nums2));
    }
}