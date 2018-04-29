package sorting_manuals;

public class ShellSort {

	public static void main(String[] args) {
		int[] ar = new int[20];

		ArrayAssistant.fillRandom(ar, 100);
		ArrayAssistant.print(ar, "Array before sorting");

		// Shellsort, using a sequence suggested by Shell
		for (int gap = ar.length / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < ar.length; i++) {
				int tmp = ar[i];
				int j = i;

				for (; j >= gap && tmp < ar[j - gap]; j -= gap) {
					ar[j] = ar[j - gap];
				}
				ar[j] = tmp;
			}
		}

		ArrayAssistant.print(ar, "Array after sorting");
		System.out.println(System.getProperty("line.separator"));

		ArrayAssistant.fillRandom(ar, 100);
		ArrayAssistant.print(ar, "Array before sorting");

		// Shellsort, using a sequence suggested by Gonnet
		for (int gap = ar.length / 2; gap > 0; gap = gap == 2 ? 1
				: (int) (gap / 2.2))
			for (int i = gap; i < ar.length; i++) {
				int tmp = ar[i];
				int j = i;

				for (; j >= gap && tmp < ar[j - gap]; j -= gap)
					ar[j] = ar[j - gap];
				ar[j] = tmp;
			}

		ArrayAssistant.print(ar, "Array after sorting");

		System.out.println(System.getProperty("line.separator"));
		ArrayAssistant.fillRandom(ar, 100);
		ArrayAssistant.print(ar, "Array before sorting");

		// ShellSort, using a sequence suggested by Knuth
		int h = 1;
		while (h <= ar.length / 3) {
			h = h * 3 + 1;
		}
		while (h > 0) {
			for (int i = h; i < ar.length; i++) {
				int temp = ar[i];
				int j = i;

				while (j > h - 1 && ar[j - h] >= temp) {
					ar[j] = ar[j - h];
					j -= h;
				}
				ar[j] = temp;
			}
			h = h / 3;
		}
		ArrayAssistant.print(ar, "Array after sorting");

	}
}
