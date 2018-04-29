package search;

import java.util.Random;

public class LinearSearch {
	private static int N = 20;
	private static int range = 30;

	public static void main(String[] args) {
		int[] mas = new int[N];

		// fill array by random integers in the interval [0;range -1]
		Random r = new Random();
		for (int i = 0; i < N; i++) {
			mas[i] = r.nextInt(range);
		}

		// output an array
		System.out.println("Array:  ");
		for (int i = 0; i < N; i++) {
			System.out.printf("% -5d", mas[i]);
		}
		System.out.println();

		// search the element with given key
		int key = r.nextInt(range);
		int index = sequentialSearch(mas, key);

		// output searching result
		if (index == -1) {
			System.out.println("Unsuccessful search. There are any element with key = " + key);
		} else {
			System.out.println("Successful search. Element with key = " + key + "  on the " + index + "  position");
		}

	}

	/**
	 * Searches the specified array of ints for the specified value using the
	 * linear search algorithm
	 * 
	 * @param a
	 *            the array to be searched
	 * @param key
	 *            the value to be searched for
	 * @return index of the search key, if it is contained in the array; -1 if
	 *         this array does not contain the element
	 */
	static int sequentialSearch(int[] a, int key) {
		int i = 0;
		int len = a.length;
		while (i < len && a[i] != key)
			i++;
		if (i == len) {
			return -1;
		} else {
			return i;
		}
	}
}
