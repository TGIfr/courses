package test2;

public class Main {
	public static void main(String[] args) {
		long time1 = System.nanoTime();
		double product = 0.0;
		double semiRes = 0.0;
		int n = 1000;
		for(int i = 1; i <= n ; i ++){
			semiRes = 0;
			for(int j = 1; j <= i; j++){
				semiRes +=  (double)4 * j / 3  - 1;
			}
			if(i == 1){
				product  = semiRes / ( i + Math.sqrt(i));
			} else {
				product *= semiRes / ( i + Math.sqrt(i));
			}
		}
		long deltaT = System.nanoTime() - time1;
		System.out.printf("%n %d %n", deltaT);
	}
}
