package test1;

public class Main {
	public static void main(String[] args) {
		long time1 = System.nanoTime();
		double product = 0.0;
		double semiRes = 0.0;
		int n = 1000;
		for(int i = 1; i <= n ; i ++){
			if( i == 1){
				semiRes = 0;
			}
			semiRes +=  (double)4 * i / 3  - 1;
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
