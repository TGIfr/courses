public class Primes {
	public static void main(String[] args) {

		int nValues = 50; // The maximum value to be checked

		// Check all values from 2 to nValues
		for (int i = 2; i <= nValues; ++i) {
			boolean isPrime = true; // Is true if we find a prime. Assume the
									// current i is prime

			// Try dividing by all integers from 2 to i-1
			for (int j = 2; j <= Math.sqrt(i) && isPrime == true; ++j) {
				if (i % j == 0) { // This is true if j divides exactly
					isPrime = false; // If we got here, it was an exact division
				}
			}
			// We can get here through the break, or through completing the loop
			if (isPrime) // So is it prime?
				System.out.print(i + "  "); // Yes, so output the value
		}
	}
}
