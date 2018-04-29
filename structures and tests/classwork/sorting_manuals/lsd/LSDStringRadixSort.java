package sorting_manuals.lsd;

import sorting_manuals.ArrayAssistant;

public class LSDStringRadixSort {

	public static void main(String[] args) {
		String[] math = { "pow", "abs", "log", "sin", "upl", "cos", "min",
				"tan", "max" };
		int w = math[0].length(); // the number of characters per string

		int r = 26; // English alphabet size
		int aCode = 97;

		int N = math.length;
		ArrayAssistant.print(math, "Before Sorting");

		for (int pos = w - 1; pos >= 0; pos--) {
			// sort by key-indexed counting on posth character

			String[] out = new String[math.length];
			int[] count = new int[r];

			// count frequencies
			for (int i = 0; i < N; i++) {
				int key = (int) math[i].toLowerCase().charAt(pos) - aCode;
				count[key]++;
			}
			// compute partial sums
			for (int i = 1; i < count.length; i++)
				count[i] += count[i - 1];

			// move strings
			for (int i = N - 1; i >= 0; i--) {
				int key = (int) math[i].toLowerCase().charAt(pos) - aCode;
				count[key]--;
				out[count[key]] = math[i];
			}
			// copy aux'elements back to math'elements
			for (int i = 0; i < N; i++) {
				math[i] = out[i];
			}
		}
		ArrayAssistant.print(math, "After Sorting");

	}
}
