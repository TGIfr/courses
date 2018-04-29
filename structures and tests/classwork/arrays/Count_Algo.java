import java.util.Arrays;
import java.util.Random;

public class Count_Algo {
	final static int N = 10;

	public static void main(String[] args) {
		Random rand = new Random();
		int[] mas = new int[N];
		for (int i = 0; i < mas.length; i++) {
			mas[i] = rand.nextInt(100) - 50;
		}
		System.out.println("Array:  " + Arrays.toString(mas));

		int count = 0;
		for (int i = 0; i < mas.length; i++) {
			if (cond(mas[i]) == true) {
				count++;
			}
		}
		System.out.println("count = " + count);

		count = 0;
		for (int el : mas) {
			if (cond(el) == true) {
				count++;
			}
		}
		System.out.println("count = " + count);

	}

	private static boolean cond(int el) {
		return el % 2 == 0 && el > 0;
	}

}
