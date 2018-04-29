public class Scope {
	public static void main(String[] args) {
		int outer = 1; // Exists throughout the method

		{

			// System.out.println("inner = " + inner);

			int inner = 2;
			System.out.println("inner = " + inner); // Now it is OK
			System.out.println("outer = " + outer); // and outer is still here

			// int outer = 5;
		}

		// System.out.println("inner = " + inner);

		int inner = 3;
		System.out.println("inner = " + inner); // ... and output its value
		System.out.println("outer = " + outer); // outer is still around
	}
}
