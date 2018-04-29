package sorting_manuals;

public class InsertionSort {

	public static void main(String[] args) {
		int[] ar = new int[10];
		ArrayAssistant.fillRandom(ar, 50);
		ArrayAssistant.print(ar, "Array before sorting");

		// sorting by MIT
		int N = ar.length;
		for (int i = 1; i < N; i++) {
			int j = i - 1;
			int key = ar[i];
			while (j >= 0 && ar[j] > key) {
				ar[j + 1] = ar[j];
				j--;
			}
			ar[j + 1] = key;
		}

		ArrayAssistant.print(ar, "Array after sorting");

		System.out.println(System.getProperty("line.separator"));
		ArrayAssistant.shuffle(ar);
		ArrayAssistant.print(ar, "Array before sorting");

		// sorting by Sedgewick
		for (int i = 1; i < N; i++) {
			for (int j = i; j > 0 && ar[j] < ar[j - 1]; j--) {
				ArrayAssistant.swap(ar, j, j - 1);
			}
		}
		ArrayAssistant.print(ar, "Array after sorting");
	}
}
