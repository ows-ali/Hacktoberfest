package sortingAlgorithm;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {

	public static void main(String[] args) {

		Random rng = new Random();
		List<Integer> toSort = new ArrayList<>();

		for (int i = 0; i < 20_000_000; ++i) {
			toSort.add(rng.nextInt(1000));
		}

		Sort s = new RadixSort(toSort);
		Sort s1 = new CountingSort(toSort);

		
		
		double timeStart1 = System.currentTimeMillis();
		s.sort();
		double timeEnd1 = System.currentTimeMillis();
		double timeTaken1 = timeEnd1 - timeStart1;
		System.out.println(timeTaken1/1000);
		//System.out.println(s.toString());
		
		
		
		/*
		double timeStart2 = System.currentTimeMillis();
		s1.sort();
		double timeEnd2 = System.currentTimeMillis();
		double timeTaken2 = timeEnd2 - timeStart2;
		System.out.println(timeTaken2/1000);
		//System.out.println(s1.toString());
		*/
		

	}

}
