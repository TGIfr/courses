
import java.util.Arrays;
import java.util.Random;

public class RearrangementAlgo {

	public static void main(String[] args) {
		System.out.println("Swapping:");
		int[] numbers = { 29, 45, 68, 89, 90, 34, 17 };
		System.out.println("Before swapping: ");
		System.out.println("numbers :" + Arrays.toString(numbers));

		// swap
		int l = 2;
		int r = 5;
		swap(numbers, l, r);
		System.out.println("After sawapping elements with indices " + l + " and " + r);
		System.out.println("numbers :" + Arrays.toString(numbers));

		// shuffle
		System.out.println("\nShuffle:");
		int[] ten = new int[10];
		int size = ten.length;
		for (int i = 0; i < size; i++) {
			ten[i] = i + 1;
		}
		System.out.println("Initial ten numbers  :" + Arrays.toString(ten));

		Random rnd = new Random();
		for (int i = size; i > 1; i--) {
			swap(ten, i - 1, rnd.nextInt(i));
		}
		System.out.println("Shuffled ten numbers :" + Arrays.toString(ten));

		// reverse
		System.out.println("\nReverse:");
		System.out.println("1st approach:");
		int[] array = { 10, 20, 30, 40, 50, 60, 70 };
		System.out.println("array before reverse:" + Arrays.toString(array));
		size = array.length;
		// 1 approach
		for (int i = 0; i < size / 2; i++) {
			swap(array, i, size - 1 - i);
		}
		System.out.println("array after reverse: " + Arrays.toString(array));

		// 2 approach
		System.out.println("2nd approach:");
		System.out.println("array before reverse:" + Arrays.toString(array));
		for (int i = 0, mid = size >> 1, j = size - 1; i < mid; i++, j--) {
			swap(array, i, j);
		}
		System.out.println("array after reverse: " + Arrays.toString(array));

		// copy array
		System.out.println("\nCopy array:");
		// avoid
		System.out.println("array :" + Arrays.toString(array));
		int[] arrayCopy1 = array;
		System.out.println("copy  :" + Arrays.toString(arrayCopy1));

		// array[1] = -200;
		System.out.println("array :" + Arrays.toString(array));
		System.out.println("copy  :" + Arrays.toString(arrayCopy1));

		// recommended
		System.out.println("\narray :" + Arrays.toString(array));
		size = array.length;
		int[] arrayCopy2 = new int[size];
		for (int i = 0; i < size; i++) {
			arrayCopy2[i] = array[i];
		}
		System.out.println("copy  :" + Arrays.toString(arrayCopy2));

		array[1] = -200;
		System.out.println("array :" + Arrays.toString(array));
		System.out.println("copy  :" + Arrays.toString(arrayCopy2));
	}

	public static void swap(int[] ar, int i, int j) {
		int buf = ar[i];
		ar[i] = ar[j];
		ar[j] = buf;

	}

}
