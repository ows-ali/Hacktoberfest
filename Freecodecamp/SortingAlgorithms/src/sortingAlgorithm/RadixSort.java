package sortingAlgorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringJoiner;

public final class RadixSort implements Sort {

	private List<Integer> ints;

	public RadixSort(List<Integer> l) {
		List<Integer> temp = Collections.unmodifiableList(l);
		ints = new ArrayList<>(temp);
	}

	public void sort() {
		for (int i = 1; i < 1000000000; i = i * 10) {
			List<List<Integer>> sortedList = new ArrayList<>();

			for (int u = 0; u < 10; ++u) {
				sortedList.add(new ArrayList<>());
			}

			for (int intTemp : ints) {
				int digit = (intTemp / i) % 10;
				sortedList.get(digit).add(intTemp);
			}

			ints.clear();
			for (List<Integer> temp : sortedList) {
				ints.addAll(temp);
			}
		}
	}

	@Override
	public String toString() {
		StringJoiner sj = new StringJoiner(",", "[", "]");
		for (Integer l : ints) {
			sj.add(String.valueOf(l));
		}
		return sj.toString();
	}

}
