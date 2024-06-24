import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
static Map<Long,Long> maxMap;


	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String val="";
		List<Long> coins = new ArrayList<>();
		maxMap = new HashMap<>();
		while((val= br.readLine()) != null){
		    Long coin = Long.parseLong(val);
		    Long max = getMaxVal(coin);

		    System.out.println(max);
		}
		
	}

	
	public static long getMaxVal(long coin){
	    if(maxMap.containsKey(coin)){
	        return maxMap.get(coin);
	    }
	    long sumOrig = coin;
	    if(coin <= 11){
	        return coin;
	    }
	    long nb2 = sumOrig/2;
	    long nb3 = sumOrig/3;
	    long nb4 = sumOrig/4;
	    long currentSum = nb2+nb3+nb4;
	    long max=coin;    
	    if(currentSum > coin){
	        max = getMaxVal(nb2)+getMaxVal(nb3)+getMaxVal(nb4);
	    }
	    maxMap.put(coin,max);
	    return max;	    
	}
}
