
public class NEW_YEAR_CHAOS {
	public static void main(String[]args) {
		int[] arr = {2, 5, 1 ,3, 4};
		minimumBribes(arr);
	}
    // Complete the minimumBribes function below.
    static void minimumBribes(int[] q) {
    //array to keep track of bribes
        int[] bribeKeeper=new int[q.length];
        int totalBribes=0;
        int temp;
        boolean ordered=true;
        //first try
        do{
        for(int c =0; c<q.length-1; c++){
            //if not in correct position
            if(q[c]!=c+1){
                if(q[c+1]<q[c]){
                    totalBribes++;
                    temp=q[c];
                    q[c]=q[c+1];
                    q[c+1]=temp;
                    bribeKeeper[temp-1]++;
                }
            }
}//end for
            for(int c=0; c< q.length; c++){
                if( q[c]!=c+1){
                    ordered=false;
                    break;
                    
}
                else {
                	ordered=true;
                }
}
        }while(ordered == false);//end do
        
     //if required more than 2 vibes
        for(int place: bribeKeeper){
            if(place>2){
              System.out.println("Too Chaotic");
        return;  
            }
        }
        
        
        System.out.println(totalBribes);
    }

}
