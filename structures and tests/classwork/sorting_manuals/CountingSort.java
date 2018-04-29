package sorting_manuals;

import java.util.Random;

public class CountingSort {

	public static void main(String[] args) {
		final int N = 15;
		final int range = 6;

		// non-stable counting sort
		int[] input = new int[N];
		// input array: keys are between 0 and range
		ArrayAssistant.fillRandom(input, range);
		System.out.println("Non-stable counting sort");
		ArrayAssistant.print(input, "Array before sorting");

		int[] count = new int[range + 1]; // provides temporary working storage

		// step1 : Count the number of keys of each value
		for (int i = 0; i < input.length; i++) {
			count[input[i]]++; // Use key as index in temporary array

		}
		// 2 step: copy of the number of each key to the initial array
		for (int j = 0, i = 0; j < count.length; j++) {
			for (int k = 0; k < count[j]; k++, i++) {
				input[i] = j;
			}
		}

		ArrayAssistant.print(input, "Array before sorting");
		System.out.println(System.lineSeparator());

		// stable counting sort
		MathFunction[] a = new MathFunction[N];
		System.out.println("Array before sorting");
		for (int i = 0; i < a.length; i++) {
			a[i] = MathFunction.create(range); // keys are between 0 and range

			System.out.print(a[i] + "  ");
		}

		int[] c = new int[range + 1]; // provides temporary working storage
		MathFunction[] b = new MathFunction[a.length]; // sorted output array

		// step1 : Count the number of keys of each value
		for (int i = 0; i < a.length; i++) {
			c[a[i].key]++; // Use key as index in temporary array

		}

		// Step2: compute partial sums
		for (int i = 1; i < c.length; i++) {
			c[i] += c[i - 1];
		}
		// Step3: calculate the index of each key in the sorted array
		for (int i = a.length - 1; i >= 0; i--) {
			c[a[i].key]--;
			b[c[a[i].key]] = a[i];
		}
		System.out.println("\nArray after sorting");
		for (int i = 0; i < b.length; i++) {
			System.out.print(b[i] + "  ");
		}

	}

}

class MathFunction {
	int key;
	String name;
	private static Random r = new Random();
	private static String[] names = { "sin", "tan", "pow", "abs", "hypot",
			"asin", "acos", "log", "log10", "min", "floor", "upl", "atan",
			"rint", "min", "max" };

	private MathFunction(int key, String name) {
		this.key = key;
		this.name = name;
	}

	/**
	 * Create and return the object of MathFunction class. Field <Key> of that
	 * object is generated randomly in the interval [0;range]. Field <name> of
	 * that object is chosen from array names by index. Index is generated
	 * randomly
	 * 
	 * @param range
	 *            upper bound for key value
	 * @return the object of MathFunction class
	 */
	public static MathFunction create(int range) {
		int key = r.nextInt(range + 1);
		String name = names[r.nextInt(names.length)];

		return new MathFunction(key, name);

	}

	@Override
	public String toString() {
		return "[" + key + ", " + name + "]";
	}

}
