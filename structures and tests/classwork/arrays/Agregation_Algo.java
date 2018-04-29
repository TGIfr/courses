import java.util.Arrays;
import java.util.Random;

public class Agregation_Algo {
	final static int N = 10;

	public static void main(String[] args) {
		Random rand = new Random();
		int[] mas = new int[N];
		for (int i = 0; i < mas.length; i++) {
			mas[i] = rand.nextInt(100) - 50;
		}
		System.out.println("Array:  " + Arrays.toString(mas));

		// sum elements
		long sum = 0;
		for (int i = 0; i < mas.length; i++) {
			sum += mas[i];
		}

		System.out.println("Sum =   " + sum);

		// average of elements
		double srArithm = (double) sum / mas.length;
		System.out.println("Average =   " + srArithm);

		int[] emptyMas = {};
		System.out.println("Array:  " + Arrays.toString(emptyMas));
		if (emptyMas.length != 0) {
			long emptySum = 0;
			for (int i = 0; i < emptyMas.length; i++) {
				emptySum += emptyMas[i];
			}

			System.out.println("Sum =   " + emptySum);
			double emptySrArithm = (double) emptySum / emptyMas.length;
			System.out.println("Average =   " + emptySrArithm);
		} else {
			System.out.println("ERROR: Can't calculate arithmetic average -> array is empty");
		}

		// product of elements
		long product = 1;
		for (int i = 0; i < mas.length; i++) {
			product *= mas[i];
		}
		System.out.println("Product =   " + product);

	}

}
