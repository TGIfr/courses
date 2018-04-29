package cw1;

public class Main {
	public static void main(String[] args) {
			int n = 1000000;
			int summ = 0;
			int a1 = 5;
			int d = 3;
			for(int i = 0; i < n; i ++){
				if(i == 0){
					summ = 0;
				}
				summ += a1 + d*i;
			}
			System.out.printf("%n %d %n", summ);
	}
}
