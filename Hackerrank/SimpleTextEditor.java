

import java.util.Scanner;
import java.util.Stack;

public class SimpleTextEditor {
	
	public static void main(String...strings) {
		// Input
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int count = 0;
		String inputString = "";
		Stack<String> stack = new Stack<>();
		stack.push(inputString);
		
		while(count < N) {
			int input = scanner.nextInt();
			switch(input) {
				case 1:
					// Append string
					inputString += scanner.next();
					stack.push(inputString);
					break;
				case 2:
					// Delete the last kth character
					int len = inputString.length();
					inputString = inputString.substring(0, len - scanner.nextInt());
					stack.push(inputString);
					break;
				case 3:
					// Print the kth character
					System.out.println(inputString.charAt(scanner.nextInt() - 1));
					break;
				case 4:
					// Undo
					stack.pop();
					inputString = stack.peek();
					break;
			}
			
			++count;
		}
		
		scanner.close();
	}

}
