package sorting_manuals.lsd;

import java.util.Random;

import sorting_manuals.ArrayAssistant;

public class LSDBitRadixSort {
	private static int N = 20;
	private static int base = 2;

	public static void main(String[] args) {
		byte[] numbers = new byte[N];
		new Random().nextBytes(numbers);
		int bits = Byte.SIZE;
		int mask = 1;

		ArrayAssistant.print(numbers, "After Sorting");

		for (int d = 0; d < bits; d++) {
			byte[] out = new byte[N];
			int[] count = new int[base];

			// compute frequency counts
			for (int i = 0; i < N; i++) {
				int bit = (numbers[i] >> d) & mask;
				if (d == bits - 1) {
					bit ^= mask;
				}
				count[bit]++;
			}
			if (count[0] != 0 && count[1] != 0) {

				for (int i = 1; i < count.length; i++)
					count[i] += count[i - 1];

				for (int i = numbers.length - 1; i >= 0; i--) {
					int bit = (numbers[i] >> d) & mask;
					if (d == bits - 1) {
						bit ^= mask;
					}
					count[bit]--;
					out[count[bit]] = numbers[i];
				}
				// copy aux'elements back to numbers'elements
				for (int i = 0; i < N; i++) {
					numbers[i] = out[i];
				}
			}
		}

		ArrayAssistant.print(numbers, "Before Sorting");
		for (int i = 0; i < numbers.length; i++) {
			System.out.println(String.format("%s",
					Integer.toBinaryString((int) numbers[i])));

		}

	}
}
