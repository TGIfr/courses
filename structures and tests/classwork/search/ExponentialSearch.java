package search;

import java.util.Arrays;
import java.util.Random;

public class ExponentialSearch {
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
		// int key = new Random().nextInt(range);
		int key = 29;
		System.out.println("\nkey = " + key);

		// random create the key to be searched for
		int index = exponentialSearch(mas, key);

		// output searching result
		if (index == -1) {
			System.out.println("Unsuccessful search. There are any element with key = " + key);
		} else {
			System.out.println("Successful search. Element with key = " + key + "  on the " + index + "  position");
		}

	}

	/**
	 * Searches a range of the specified array of ints for the specified value
	 * using the exponential search algorithm. The array must be sorted prior to
	 * making this call
	 * 
	 * @param mas
	 *            the array to be searched
	 * @param key
	 *            the value to be searched for
	 * @return index of the search key, if it is contained in the array; -1 if
	 *         this array does not contain the element
	 */
	private static int exponentialSearch(int[] mas, int key) {
		int bound = 1;
		int len = mas.length;

		// determines a range in which the search key would reside if it were in
		// the array
		while (bound < len && mas[bound] < key) {
			// bound is the next power of 2
			bound = bound << 1;
			if (bound < len && mas[bound] == key) {
				return bound; // found
			}
		}

		// 2^(j - 1) becomes the lower bound for the binary search
		// (key > mas[lowerBound])
		int lowerBound = bound >>> 1;

		// 2^j becomes the upper bound for the binary search
		// (key < mas[upperBound])
		int upperBound = Math.min(bound, len);

		// a binary search is performed on this range [lowerBound; upperBound]
		return binarySearch(mas, key, lowerBound, upperBound);
	}

	/**
	 * Searches a range of the specified array of ints for the specified value
	 * using the binary search algorithm. The range must be sorted prior to
	 * making this call
	 * 
	 * @param mas
	 *            the array to be searched
	 * @param key
	 *            the value to be searched for
	 * @param lo
	 *            the index of the first element (inclusive) to be searched
	 * @param hi
	 *            the index of the last element (inclusive) to be searched
	 * @return index of the search key, if it is contained in the array; -1 if
	 *         this array does not contain the element
	 */
	private static int binarySearch(int[] mas, int key, int lo, int hi) {
		while (lo <= hi) {
			int m = (lo + hi) >>> 1;
			if (key == mas[m]) {
				return m; // found
			} else {
				if (key < mas[m]) {
					hi = m - 1;
				} else {
					lo = m + 1;
				}
			}
		}
		return -1; // not found
	}

}
