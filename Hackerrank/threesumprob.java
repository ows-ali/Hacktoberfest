package strivercourse.arrays;
import java.util.*;
import java.util.ArrayList;
import java.util.HashSet;

public class threesum {
    public static void main(String[] args) {

        int arr[]=new int[]{-1,0,1,2,-1,-4};

        List<List<Integer>> ans=threesum(arr);

        for (List<Integer> i: ans) {
            for (Integer it:i
                 ) {
                System.out.printf(" %d ",it);

            }
            System.out.printf("\n");
        }

    }



    // noobie methoddd // O(n3)+log(nlogn)
//   static ArrayList<Integer> sum_3(int arr[]){
//        ArrayList<Integer> ans=new ArrayList<>();
//       HashSet<ArrayList<Integer>> set=new HashSet<>();
//       for (int i = 0; i <arr.length ; i++) {
//           for (int j = i+1; j < arr.length ; j++) {
//               for (int k = j+1; k < arr.length; k++) {
//                   if(arr[i]+arr[j]+arr[k]==0){
//                       ArrayList<Integer> temp=new ArrayList<>(Arrays.asList(arr[i],arr[j],arr[k]));
//                       Collections.sort(temp);
//                       set.add(temp);
//                       }
//
//                   }
//               }
//           }
//       ans=new ArrayList<>(ans.stream().toList());
//
//       return ans;
//       }


       //better methodddddd


//we will get rid of third loop
    // arr[k]=-(arr[i]+arr[k]);
    // It will use Hashingggggg
    // u have to be careful that the value of k should be different
    // if u r between
static List<List<Integer>> sum_3_1(int arr[]){
        Arrays.sort(arr);
        Set<List<Integer>> set=new HashSet<>();

    for (int i = 0; i <arr.length ; i++) {
        Set<Integer> hashset=new HashSet<>();
        for (int j = i+1; j < arr.length ; j++) {
            //calculate the third element
            int third=-(arr[j]+arr[i]);


            if(hashset.contains(third)){
                List<Integer>temp=Arrays.asList(arr[i],arr[j],third);
                temp.sort(null);
                set.add(temp);
            }
            hashset.add(arr[j]);
        }
    }
    List<List<Integer>> ans=new ArrayList<>(set);
return ans;

}



// optimal 2 pointer approach

    static List<List<Integer>> threesum(int arr[]){

        List<List<Integer>> ans=new ArrayList<>();
        for (int i = 0; i <arr.length ; i++) {
             if(i!=0&& arr[i]==arr[i-1]){ continue;}
             int j=i+1;
             int k= arr.length-1;
             while(j<k){
                 int sum=arr[i]+arr[j]+arr[k];
                 if(sum<0){
                     j++;
                 }
                 else if (sum>0){
                     k--;
                 }
                 else{
                     List<Integer> temp=Arrays.asList(arr[i]+arr[j]+arr[k]);
                     ans.add(temp);
                     j++;
                     k--;
                     while(j<k && arr[j]==arr[j-1]){ j++;}
                     while(j<k && arr[k]==arr[k+1]){ k--;}
                 }
             }
        }
        return ans;}
    }











