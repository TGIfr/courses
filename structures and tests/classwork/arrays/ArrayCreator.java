import java.util.Arrays;
import java.util.Random;

public class ArrayCreator {

	public static void main(String[] args) {

		// An array of ten integers. All elements are initialized with zero.
		int[] numbers = new int[10];
		System.out.println("numbers :" + Arrays.toString(numbers));

		// It is a good idea to use a named constant instead of a �magic
		// number�.
		final int LENGTH = 10;
		int[] numbers2 = new int[LENGTH];
		System.out.println("\nnumbers :" + Arrays.toString(numbers2));

		// create and explicitly initialize an array
		int[] squares = { 0, 1, 4, 9, 16 };
		System.out.println("\nsquares :" + Arrays.toString(squares));

		String[] colors = { "red", "blue", "yellow" };
		System.out.println("\ncolors :" + Arrays.toString(colors));

		// create an array of integers
		int[] anArray;
		anArray = new int[10];

		// assign values to each element of the array
		anArray[0] = 100;
		anArray[1] = 200;
		anArray[2] = 300;
		anArray[3] = 400;
		anArray[4] = 500;
		anArray[5] = 600;
		anArray[6] = 700;
		anArray[7] = 800;
		anArray[8] = 900;
		anArray[9] = 1000;

		System.out.println("\nanArray -> " + Arrays.toString(anArray));

		// Declaring a Variable to Refer to an Array
		char[] s = new char[26];
		String str = "\nAlphabet array ";
		for (int i = 0; i < 26; i++) {
			s[i] = (char) ('A' + i);
			str = str + s[i];
		}
		System.out.println(str);

		// define array
		int[] randArray = new int[LENGTH];

		// fill the array by random values in range [0;49]
		Random rand = new Random();
		for (int i = 0; i < randArray.length; i++) {
			randArray[i] = rand.nextInt(50);
		}

		// output randArray in the for loop
		System.out.println("\nRandomly initialized array: output in the for loop:");
		for (int i = 0; i < randArray.length; i++) {
			System.out.printf("%-3d", randArray[i]);
		}

		// output randArray in the for loop
		System.out.println("\nRandomly initialized array: output in the foreach loop:");
		for (int el : randArray) {
			System.out.print(el + " ");
		}

	}

}
