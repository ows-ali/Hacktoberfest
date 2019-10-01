import java.util.Scanner;

public class ADACRA {
	
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();				
		while(n-- > 0) {			
			String input = scan.next();
			String input_new = "";
			for(int i = 0; i < input.length() - 1; i++) {
				if(input.charAt(i) != input.charAt(i + 1)) {
					input_new += String.valueOf(input.charAt(i));
					if(i == input.length() - 2) input_new += String.valueOf(input.charAt(i + 1));
				} else 
					if(i == input.length() - 2) input_new += String.valueOf(input.charAt(i + 1));
			}
			int uCount = 0;
			int dCount = 0;
			for(int i = 0; i < input_new.length(); i++) {
				if(input_new.charAt(i) == 'D') 
					dCount++;
				else 
					uCount++;
			}			
			if(uCount > dCount) 
				System.out.println(dCount);
			else 
				System.out.println(uCount);
		}
		scan.close();
	}

}
