
// This is the Java solution for Buy and Sell Stock Problem
class Solution {
    public int maxProfit(int[] prices) {
        
        
        ArrayList<Integer> list = new ArrayList<>();
        int n=prices.length;
        for(int i=0;i<n;i++)
        {
            list.add(prices[i]);
        }
         int ans=Stock(list , n);
        return ans;
    }
    public  class Interval
	{
		int buy;
		int sell;
	}
	public  int Stock(ArrayList<Integer> sol , int n)
	{
		ArrayList<Interval> answer= new ArrayList<>();
		if(n==1)
		{
			return 0 ;
		}
		int count=0;
		//ArrayList<Integer> sol= new ArrayList<>();
		int i=0;
		while(i<n-1)
		{
			while((i<n-1)&&sol.get(i+1)<=sol.get(i))
			{
				i++;
			}
			if(i==n-1)
			{
				break;
			}
			Interval e = new Interval();
			e.buy=i++;
			while((i<n)&& sol.get(i)>=sol.get(i-1))
			{
				i++;
			}
			e.sell=i-1;
			answer.add(e);
			count++;
			
		}
		if(count==0)
		{
			//System.out.println("No way");
            return 0;
		}
		else
		{
			int sum=0;
			for(int j=0;j<answer.size();j++)
			{
				Interval curr= answer.get(j);
				//System.out.println("But"+curr.buy);
				//System.out.println("Sell"+curr.sell);
				sum+=sol.get(curr.sell)-sol.get(curr.buy);
				//sum-=2;
				
			}
			//System.out.println(sum);
            return sum;
		}
    }
}