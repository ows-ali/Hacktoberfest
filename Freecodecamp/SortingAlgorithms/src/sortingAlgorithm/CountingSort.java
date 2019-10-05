package sortingAlgorithm;

import java.util.Collections;
import java.util.List;
import java.util.StringJoiner;

public final class CountingSort implements Sort {

	int[] ints;

	public CountingSort(List<Integer> ints) {
		this.ints = toIntArray(ints);
	}

	public static int[] toIntArray(List<Integer> list) {
		int size = list.size();
		int[] temp = new int[size];

		for (int i = 0; i < size; i++) {
			temp[i] = list.get(i);
		}
		return temp;
	}

	@Override
	public void sort() {

		int size = ints.length;
		int count[] = new int[1000];
		int output[] = new int[size];

		// Initialize all values at 0
		for (int i = 0; i < 1000; i++) {
			count[i] = 0;
		}

		// Count the number of each integer
		for (int i = 0; i < size; ++i) {
			++count[ints[i]];
		}

		// Do the cumulative sum for each integer
		for (int i = 1; i < 1000; i++) {
			count[i] += count[i - 1];
		}

		for (int i = size - 1; i >= 0; --i) {
			output[count[ints[i]] - 1] = ints[i];
			--count[ints[i]];
		}

		for (int i = 0; i < size; ++i) {
			ints[i] = output[i];
		}

	}

	@Override
	public String toString() {
		StringJoiner sj = new StringJoiner(",", "[", "]");
		int size = ints.length;
		for (int i = 0; i < size; ++i) {
			sj.add(String.valueOf(ints[i]));
		}
		return sj.toString();
	}
}
