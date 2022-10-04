// import java.util.*;
// public class selectionshort{
//     public static void printarray(int arr[]){
//         for(int i=0;i<arr.length;i++){
//             System.out.print(arr[i]+" ");
//         }
//         System.out.println();
//     }
//     public static void main(String b[]){
//         int arr[]={7,8,2,3,1};
//         for(int i=0;i<arr.length-1;i++){
//             int smallest=i;
//             for(int j=i+1;j<arr.length;j++){
//                 if(arr[smallest]>arr[j]){
//                     smallest=j;
//                 }
//             }
//             int temp=arr[smallest];//using swap condition
//             arr[smallest]=arr[i];
//             arr[i]=temp;
//         }
//         printarray(arr);

//     }
// }
import java.util.*;
public class selectionshort{
    public static void printarray(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
public static void main(String b[]){
    int arr[]={7,86,4,3,1};
    for(int i=0;i<arr.length;i++){
        int  smallest=i;
        for(int j=i+1;j<arr.length;j++){
            if(arr[smallest]>arr[j]){
                smallest=j;
            }
        }
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
    }
    printarray(arr);
}
}