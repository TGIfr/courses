package search;

import java.util.Arrays;
import java.util.Random;

public class BinarySearch {
	private static int N = 20;
	private static int range = 30;

	public static void main(String[] args) {
		int[] mas = new int[N];
		// fill array by random integers in the interval [0;range -1]
		Random r = new Random();
		for (int i = 0; i < N; i++) {
			mas[i] = r.nextInt(range);
		}
		// output the array filled by random values
		System.out.println("Unsorted array:  ");
		for (int i = 0; i < N; i++) {
			System.out.printf("% -5d", mas[i]);
		}
		System.out.println();

		// sort the array
		Arrays.sort(mas);

		// output sorted array
		System.out.println("Sorted array:  ");
		for (int i = 0; i < N; i++) {
			System.out.printf("% -5d", mas[i]);
		}
		System.out.println();

		// random create the key to be searched for
		int key = new Random().nextInt(range);
		System.out.println("\nkey = " + key);

		// search the element with given key
		int index = binarySearch(mas, key);

		// output searching result
		if (index == -1) {
			System.out.println("Unsuccessful search. There are any element with key = " + key);
		} else {
			System.out.println("Successful search. Element with key = " + key + "  on the " + index + "  position");
		}

		// Test with java SDK
		index = Arrays.binarySearch(mas, key);
		// output searching result
		System.out.println("Results of Arrays.binarySearch");
		if (index < 0) {
			System.out.println("Unsuccessful search. There are any element with key = " + key + "   index = " + index);
		} else {
			System.out.println("Successful search. Element with key = " + key + "  on the " + index + "  position");
		}

	}

	/**
	 * Searches the specified array of ints for the specified value using the
	 * binary search algorithm.The array must be sorted prior to making this
	 * call. If it is not sorted, the results are undefined. If the array
	 * contains multiple elements with the specified value, there is no
	 * guarantee which one will be found
	 * 
	 * @param a
	 *            the array to be searched
	 * @param key
	 *            the value to be searched for
	 * @return index of the search key, if it is contained in the array; -1 if
	 *         this array does not contain the element
	 */

	private static int binarySearch(int[] mas, int key) {
		int lo = 0;
		int hi = mas.length - 1;
		while (lo <= hi) {
			int m = (lo + hi) / 2;
			if (key == mas[m]) {
				return m;
			} else {
				if (key < mas[m]) {
					hi = m - 1;
				} else {
					lo = m + 1;
				}
			}
		}
		return -1;
	}

}
