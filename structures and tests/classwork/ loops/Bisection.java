public class Bisection {
	
	private static double f(double x) {
		return Math.pow(x, 3.0) + x - 6;
	}
	public static void main(String[] args) {
		double xa = 0.5;
		double xb = 2.0;
		double tol = 0.001;
		double xc = 0.0;
		if (f(xa) * f(xb) > 0) {
		     System.out.println("ERROR: Illegal boundaries");
		 }
		 if (f(xa) * f(xb) == 0) {
		       if (f(xa) == 0) {
		         xc = xa;
		       } else {
		         xc = xb;
		       }
		  } else {
			  do {
				  xc = (xa + xb) / 2;
				  if (f(xa) * f(xc) < 0) {  
					  xb = xc;
			      } else { xa = xc; }
		      } while (Math.abs(f(xc)) > tol);
		}
		 System.out.printf("root = %f y = %f",xc, f(xc));

	}

}
