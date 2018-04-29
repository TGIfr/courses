package operators.loops;

public class SelfTestTask {

	public static void main(String[] args) {
		System.out.println("Try 1");
		for (int n = 1; n <= 4; n++)
			System.out.println(n);

		System.out.println("\nTry 2");
		int n;
		for (n = 1; n > 4; n++)
			System.out.println(n);

		System.out.println("\nTry 3");
		int k;
		for (k = 4; k > 0; k--)
			;
		System.out.println(k);

		System.out.println("\nTry 4");
		for (double test = 0; test < 3; test = test + 0.5)
			System.out.println(test);

		System.out.println("\nTry 5");
		for (int count = 0; count <= 3; count++)
			for (int count2 = 0; count2 < count; count2++)
				System.out.println(count2);

	}

}
