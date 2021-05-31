// Working program with FastReader 
import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 

 class Main 
{ 
    
    
    
    public static void main(String[] args) 
	{ 
		FastReader sc=new FastReader(); 
		int test=sc.nextInt();
		while(test-->0)
		{
              int n=sc.nextInt();
              int m=sc.nextInt();
              int nums [] =new int[n+1];
              int last [] =new int[n+1];
              for(int i=0;i<m;i++)
              {
                    int a=sc.nextInt();
                    int b=sc.nextInt();
                    nums[a]++;
                    nums[b]++;
                    last[a]=b;
                    last[b]=a;
              }
              if(m%2==0)
              {
                  System.out.println("1");
                  for(int i=0;i<n;i++)
                  System.out.print("1 ");
              }//end of if
              else
              { 
                  boolean flag=true;
                  int result[]=new int[n+1];
                  for(int i=1;i<=n;i++)
                  {
                      if(nums[i]%2!=0)
                      {
                          result[i]=1;
                          flag=false;
                          System.out.println("2");
                          break;
                      }
                  }
                  if(flag)
                  {
                      for(int i=1;i<=n;i++)
                      {
                          if(nums[i]!=0)
                          {
                              result[i]=1;
                              result[last[i]]=2;
                              System.out.println("3");
                              break;
                          }
                      }
                  }
                  
                  for(int i=1;i<=n;i++)
                  System.out.print((result[i]+1)+" ");
              }//end of else of even odd
              System.out.println();
		}
		
	
	} 
	
	
	
	
	
	
	
	static class FastReader 
	{ 
		BufferedReader br; 
		StringTokenizer st; 

		public FastReader() 
		{ 
			br = new BufferedReader(new
					InputStreamReader(System.in)); 
		} 

		String next() 
		{ 
			while (st == null || !st.hasMoreElements()) 
			{ 
				try
				{ 
					st = new StringTokenizer(br.readLine()); 
				} 
				catch (IOException e) 
				{ 
					e.printStackTrace(); 
				} 
			} 
			return st.nextToken(); 
		} 

		int nextInt() 
		{ 
			return Integer.parseInt(next()); 
		} 

		long nextLong() 
		{ 
			return Long.parseLong(next()); 
		} 

		double nextDouble() 
		{ 
			return Double.parseDouble(next()); 
		} 

		String nextLine() 
		{ 
			String str = ""; 
			try
			{ 
				str = br.readLine(); 
			} 
			catch (IOException e) 
			{ 
				e.printStackTrace(); 
			} 
			return str; 
		} 
	} 


} 
