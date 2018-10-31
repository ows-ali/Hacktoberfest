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
			int countU = 0;
			int countD = 0;
			for(int i = 0; i < input_new.length(); i++) {
				if(input_new.charAt(i) == 'D') 
					countD++;
				else 
					countU++;
			}			
			if(countU > countD) 
				System.out.println(countD);
			else 
				System.out.println(countU);
		}
		scan.close();
	}

}
