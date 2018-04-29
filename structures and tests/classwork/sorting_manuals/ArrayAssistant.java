package sorting_manuals;

import java.util.Random;

public class ArrayAssistant {
	public static void print(int[] a, String message) {
		System.out.println(message);
		for (int i = 0; i < a.length; i++) {
			System.out.printf("% -5d", a[i]);
		}
		System.out.println();
	}

	public static void print(double[] a, String message) {
		System.out.println(message);
		for (int i = 0; i < a.length; i++) {
			System.out.printf("% -5.3f", a[i]);
		}
		System.out.println();
	}

	public static void fillRandom(int[] a, int range) {
		fillRandom(a, 0, range);
	}

	public static void fillRandom(double[] a) {
		Random r = new Random();
		for (int i = 0; i < a.length; i++) {
			a[i] = r.nextDouble();
		}
	}

	public static void fillRandom(int[] a, int from, int to) {
		Random r = new Random();
		for (int i = 0; i < a.length; i++) {
			a[i] = r.nextInt(to - from + 1) + from;
		}
	}

	public static void shuffle(int[] ar) {
		Random rnd = new Random();
		for (int i = ar.length; i > 1; i--) {
			swap(ar, i - 1, rnd.nextInt(i));
		}
	}

	public static void swap(int[] ar, int i, int j) {
		int temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}

}
