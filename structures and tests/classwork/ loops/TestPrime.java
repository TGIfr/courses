public class TestPrime {

	public static void main(String[] args) {
		int value = 9;
		boolean isPrime = true;
		for (int j = 2; j <= Math.sqrt(value) && isPrime == true; ++j) {
			if (value % j == 0) {
				isPrime = false;
			}
		}
		if (isPrime) {
			System.out.println("value " + value + " is a prime");
		} else {
			System.out.println("value " + value + " is not prime");
		}

	}

}
