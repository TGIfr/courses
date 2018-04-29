public class Factorial {

	public static void main(String[] args) {
		long limit = 15; // to calculate factorial of integers up to this value
		long factorial = 1; // factorial will be calculated in this variable

		// Loop from 1 to the value of limit
		for (int f = 1; f <= limit; f++) {
			factorial *= f; // Initialize factorial
			System.out.println(f + "!" + " is " + factorial);
		}
	}
}
