package sorting_manuals;

public class BubbleSort {

	public static void main(String[] args) {
		int[] ar = new int[9];
		ArrayAssistant.fillRandom(ar, 100);
		System.out.println("Bubble sort basic ");
		ArrayAssistant.print(ar, "Array before sorting");

		// basic bubble sort
		int n = ar.length;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1 - i; j++) {
				if (ar[j + 1] < ar[j]) {
					ArrayAssistant.swap(ar, j, j + 1);
				}
			}
		}

		ArrayAssistant.print(ar, "Array after sorting");

		System.out.println("\nImproved bubble sort");
		ArrayAssistant.shuffle(ar);
		ArrayAssistant.print(ar, "Array before sorting");

		// improvement bubble sort
		n = ar.length;
		boolean swapped = true;
		for (int i = 0; i < n - 1 && swapped; i++) {
			swapped = false;
			for (int j = 0; j < n - 1 - i; j++) {
				if (ar[j + 1] < ar[j]) {
					ArrayAssistant.swap(ar, j, j + 1);
					swapped = true;
				}
			}
		}
		ArrayAssistant.print(ar, "Array after sorting");

		// Bidirectional (or shaker) bubble sort
		System.out.println("\nBidirectional bubble sort");
		ArrayAssistant.shuffle(ar);
		ArrayAssistant.print(ar, "Array before sorting");
		int l = 0;
		int r = ar.length - 1;

		do {
			swapped = false;
			for (int i = l; i < r; i++) {
				if (ar[i + 1] < ar[i]) {
					ArrayAssistant.swap(ar, i, i + 1);
					swapped = true;
				}
			}
			r--;
			for (int i = r; i > l; i--) {
				if (ar[i] < ar[i - 1]) {
					ArrayAssistant.swap(ar, i, i - 1);
					swapped = true;
				}
			}
			l++;

		} while (l < r && swapped);

		ArrayAssistant.print(ar, "Array after sorting");

	}

}
