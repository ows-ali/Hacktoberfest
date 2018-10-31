public class Birthday_Cake_Candles {
  static int birthdayCakeCandles(int[] ar) {
    if(ar!=null && ar.length>0) {
      int maxHeight=0, numMaxHeight=1;
      for(int i=0; i<ar.length; i++) {
        if(maxHeight<ar[i]) {
          maxHeight=ar[i];
          numMaxHeight=1;
        }else if(maxHeight==ar[i]) {
          numMaxHeight++;
        }
      }
      return numMaxHeight;
    }
    return 0;
  }
}
