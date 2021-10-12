public class FLOW006 {
	public static int sumOfDigits(int n) {
		int num = n;
		int sum = 0; 
		while (num > 0) {
			sum = sum + num % 10; 
			num = num / 10; 
		}
		
		return sum; 
	}
	
}
//LMH - Basic method to solve said problem. 
