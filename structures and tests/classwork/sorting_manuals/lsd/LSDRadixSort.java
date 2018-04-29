package sorting_manuals.lsd;

import sorting_manuals.ArrayAssistant;

public class LSDRadixSort {
	private static int N = 20;
	private static int d = 3;
	private static int base = 10;

	public static void main(String[] args) {
		int[] intArray = new int[N];
		int from = 100;
		int to = 999;
		ArrayAssistant.fillRandom(intArray, from, to);

		ArrayAssistant.print(intArray, "Before Sorting");
		// Sort the numbers beginning with least-significant digit
		// pos = 1, 10, 100, 1000, ...
		for (int pos = 1; pos <= (int) Math.pow(base, d); pos *= base) {

			int[] out = new int[N];
			int[] count = new int[base];

			for (int i = 0; i < N; i++) {
				int digit = (intArray[i] / pos) % base;
				count[digit]++;
			}

			for (int i = 1; i < count.length; i++)
				count[i] += count[i - 1];

			for (int i = N - 1; i >= 0; i--) {
				int digit = (intArray[i] / pos) % base;
				count[digit]--;
				out[count[digit]] = intArray[i];
			}
			// copy aux'elements back to intArray'elements
			for (int i = 0; i < N; i++) {
				intArray[i] = out[i];
			}
		}
		ArrayAssistant.print(intArray, "After Sorting");

	}

}
