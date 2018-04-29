import java.util.Arrays;
import java.util.Random;

public class Max_Algo {
	final static int N = 10;

	public static void main(String[] args) {
		Random rand = new Random();
		int[] mas = new int[N];
		for (int i = 0; i < mas.length; i++) {
			mas[i] = rand.nextInt(100) - 50;
		}
		System.out.println("Array:  " + Arrays.toString(mas));
		// max
		int max = mas[0];
		for (int i = 1; i < mas.length; i++) {
			if (mas[i] > max) {
				max = mas[i];
			}
		}

		System.out.println("max = " + max);

		// index of max
		int maxIndex = 0;
		for (int i = 1; i < mas.length; i++) {
			if (mas[i] > mas[maxIndex]) {
				maxIndex = i;
			}
		}

		System.out.println("max = " + mas[maxIndex] + "  with index = " + maxIndex);

		max = Integer.MIN_VALUE;
		for (int i = 0; i < mas.length; i++) {
			if (mas[i] > max) {
				max = mas[i];
			}
		}
		System.out.println("max = " + max);

	}

}
