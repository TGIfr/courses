public class QuadraticEq {

	public static void main(String[] args) {
		// 1 test
		 double a = 2.0;
		 double b = -4.0;
		 double c = -6.0;
		//
		// 2 test
		// double a = 2.0;
		// double b = 4.0;
		// double c = 7.0;

		// 3 test
//		double a = 1.0;
//		double b = 1.0;
//		double c = 1.0;

		double x1 = 0;
		double x2 = 0;
		double d = Math.pow(b, 2.0) - 4 * a * c;
		if (d > 0) {
			System.out.println("Discriminant is positive. Two roots");
			x1 = (-b + Math.sqrt(d)) / (2 * a);
			x2 = (-b - Math.sqrt(d)) / (2 * a);
			System.out.println("x1 = " + x1 + ",  x2 = " + x2);
		} else {
			if (d < 0) {
				System.out.println("Discriminant is negative. None roots");
			} else {
				System.out.println("Discriminant is zero. One roots");
				x1 = x2 = -b / 2 * a;
				System.out.println("x1 = " + x1);
			}
		}
	}
}
