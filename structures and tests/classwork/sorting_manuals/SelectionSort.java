package sorting_manuals;

public class SelectionSort {

	public static void main(String[] args) {
		int[] ar = new int[30];
		ArrayAssistant.fillRandom(ar, 100);
		ArrayAssistant.print(ar, "Array before sorting");

		// sorting
		for (int i = 0; i < ar.length - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < ar.length; j++) {
				if (ar[j] < ar[minIndex]) {
					minIndex = j;
				}
			}
			if (i != minIndex) {
				ArrayAssistant.swap(ar, i, minIndex);
			}
		}

		ArrayAssistant.print(ar, "Array after sorting");

	}

}
