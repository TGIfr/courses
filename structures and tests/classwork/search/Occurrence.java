package search;

import java.util.Random;

public class Occurrence {
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

		// random create the key to be searched for
		int el = new Random().nextInt(range);
		System.out.println("\nElement to be searched for = " + el);

		// find the first occurrence of the element in the array
		int index = indexOf(mas, el);
		if (index == -1) {
			System.out.println("Unsuccessful search. There are any element = " + el);
		} else {
			System.out.println("The first occurence of the element = " + el + "  index =  " + index);
		}

		// find the last occurrence of the element in the array
		index = lastIndexOf(mas, el);
		if (index == -1) {
			System.out.println("Unsuccessful search. There are any element = " + el);
		} else {
			System.out.println("The last occurence of the element = " + el + "  index =  " + index);
		}

	}

	/**
	 * Returns the index of the first occurrence of the specified element in
	 * this array, or -1 if this array does not contain the element
	 * 
	 * @param a
	 *            the array to be searched
	 * @param el
	 *            the element to be searched for
	 * @return the index of the first occurrence of the specified element in
	 *         this array, or -1 if this array does not contain the element
	 */
	private static int indexOf(int[] a, int el) {
		// move from the beginning of array to the ending until meet with the
		// specified element
		for (int i = 0; i < a.length; i++)
			if (el == a[i])
				return i;
		return -1;
	}

	/**
	 * Returns the index of the last occurrence of the specified element in this
	 * array, or -1 if this array does not contain the element.
	 * 
	 * @param a
	 *            the array to be searched
	 * @param key
	 *            the element to be searched for
	 * @return the index of the last occurrence of the specified element in this
	 *         array, or -1 if this array does not contain the element
	 */
	private static int lastIndexOf(int[] a, int key) {
		// move from the ending of array to the beginning until meet with the
		// specified element
		for (int i = a.length - 1; i >= 0; i--)
			if (key == a[i])
				return i;
		return -1;
	}
}
