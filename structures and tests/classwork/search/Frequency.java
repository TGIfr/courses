package search;

import java.util.Arrays;
import java.util.Random;

public class Frequency {
	private static int N = 20;
	private static int range = 10;

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
		int el = new Random().nextInt(range);
		System.out.println("\nel = " + el);

		// find the first occurrence of the element in the array
		int index = indexOf(mas, el);
		if (index == -1) {
			System.out.println("Unsuccessful search. There are any element  = " + el);
		} else {
			System.out.println("Successful search. Element = " + el + "  on the " + index + "  position");
		}
		// calculate the length of continuous block
		int count = 0;
		if (index != -1) {
			while (index < mas.length && mas[index++] == el)
				count++;
		}

		System.out.println("Number of occurrences  = " + count);
	}

	/**
	 * Returns the index of the first occurrence of the specified element in
	 * this array using binary search. The array must be sorted prior to making
	 * this call. If it is not sorted, the results are undefined.
	 * 
	 * @param a
	 *            the array to be searched
	 * @param el
	 *            the element to be searched for
	 * @return the index of the first occurrence of the specified element in
	 *         this array, or -1 if this array does not contain the element
	 */

	static int indexOf(int arr[], int el) {
		int low = 0;
		int high = arr.length - 1;
		while (high >= low) {
			int mid = (low + high) / 2;
			if ((mid == 0 || el > arr[mid - 1]) && arr[mid] == el)
				return mid;
			else if (el > arr[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return -1;
	}

}
