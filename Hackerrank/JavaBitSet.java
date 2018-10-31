

import java.util.BitSet;
import java.util.Scanner;

public class JavaBitSet {
	
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		
		BitSet B1 = new BitSet(N);
		initBitSet(B1);
		
		BitSet B2 = new BitSet(N);
		initBitSet(B2);
		
		for (int i = 0; i < M; i++) {
			String operation = scanner.next();
			int left =  scanner.nextInt();
			int right = scanner.nextInt();
			
			if (left == 1) {
				bitSetResult(operation, B1, B2, right);
			} else {
				bitSetResult(operation, B2, B1, right);
			}
			
			System.out.print(B1.cardinality() + " " + B2.cardinality());
			System.out.println();
		}
		
		scanner.close();
	}
	
	private static void bitSetResult(String operation, BitSet leftOperand, BitSet rightOperand, int index) {
		switch (operation) {
		case "AND":
			leftOperand.and(rightOperand);
			break;
		case "OR":
			leftOperand.or(rightOperand);
			break;
		case "XOR":
			leftOperand.xor(rightOperand);
			break;
		case "FLIP":
			leftOperand.flip(index);
			break;
		case "SET":
			leftOperand.set(index);
			break;
		}
	}
	
	private static BitSet initBitSet(BitSet bitSet) {
		for (int i = 0; i < bitSet.length(); i++) {
			bitSet.set(0);
		}
		return bitSet;
	}

}
