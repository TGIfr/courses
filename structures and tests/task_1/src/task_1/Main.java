package task_1;

/**
 * KPI- FPM - PZKS
 * Course: Algorithms and Data Structures (1)
 * Laboratory work 1
 * @author Olena Khomenko
 * This is a program skeleton for part 1 of lab
 * Write your code in the places of the program which are marked by TODO marker 
 * Run program
 * If all tests are passed, it's OK
 */
public class Main {

	public static void main(String[] args) {
		
			
		//task 1: test1 
		
		int valA = 1;
		int valB = 0;
		
		//TODO
		// calculate the arithmetic mean of two values: (a + b) / 2 
		// keep the result in the variable arithmMean
		double arithmMean = (double)(valA+valB)/2;
		double expectedValue = 0.5;
		if (arithmMean == expectedValue){
			System.out.printf("%ntest 1.1 passed%n");
		} else {
			System.out.printf("%ntest 1.1 failed:  valA = %-7d  valB = %-10d  arithmMean = %-7.2f  expectedValue %-7.2f%n", valA, valB, arithmMean, expectedValue);
		}
	
		//task 1: test2 
		
		valA = 32_656;
		valB = Integer.MAX_VALUE;
		
		//TODO
		// calculate the arithmetic mean of two values: (a + b) / 2 
		// keep the result in the variable arithmMean  
		long valALong = valA;
		arithmMean = (double)(valALong+valB)/2;
		
		expectedValue = 1073758151.50;
		if (arithmMean == expectedValue){
			System.out.printf("%ntest 1.2 passed%n");
		} else {
			System.out.printf("%ntest 1.2 failed:  valA = %-7d  valB = %-10d  arithmMean = %-7.2f  expectedValue %-7.2f%n", valA, valB, arithmMean, expectedValue);
		}
		
		System.out.println(System.lineSeparator());

		// task2: test1
		
		int a = 678;
		int b = -3;
		System.out.printf("%ntest 2.1 before swap:  a = %3d, b = %3d", a, b);
		
		// TODO
		// swap a and b
		int swapValue = a;
		a = b;
		b = swapValue;
				
		int expectedA = -3;
		int expectedB = 678;
		
		if (a ==expectedA && b == expectedB){
			System.out.printf("%ntest 2.1 passed%n");
		} else{
			System.out.printf("%ntest 2.1 failed:  a = %3d, b = %3d; expected => a = %3d, b = %3d%n", a, b, expectedA, expectedB);
		}
		 
		// task2: test2
		
		a = 678;
		byte c = -3;
		System.out.printf("%ntest 2.2 before swap:  a = %3d, c = %3d", a, c);
				
		// TODO
		// swap a and c
		
		swapValue = a;
		a = c;
		c = (byte)swapValue;
			
		expectedA = -3;
		byte expectedC = -90;
				
		if (a == expectedA && c == expectedC){
			System.out.printf("%ntest 2.2 passed%n");
		} else{
			System.out.printf("%ntest 2.2 failed:  a = %d, c = %d; expected => a = %d, c = %d%n", a, c, expectedA, expectedC);
		}
		
		System.out.println(System.lineSeparator());
		
		
		//task3: test1
		
		valA = 345;
		valB = -1;
		int valC = -20633;
		
		//TODO
		//calculate the product of value valC and sum of two values valA and valB: C * (A + B) 
		// keep the result in the variable product  
		long product = valC*(valA+valB);
		
		long expectedProduct = -7097752;
		if (product == expectedProduct){
			System.out.printf("%ntest 3.1 passed%n");
		} else {
			System.out.printf("%ntest 3.1 failed:  valA = %-7d  valB = %-7d  valC = %-7d product = %-10d  expected %-10d%n", valA, valB, valC, product, expectedProduct);
		}
		
		//task3: test2
		
		valA = 2147483647;
		valB = 2;
		valC = -1;

		//TODO
		//calculate the product of value valC and sum of two values valA and valB: C * (A + B) 
		// keep the result in the variable product    
		product = valC*(valA+valB);
		
		expectedProduct = valA;
		if (product == expectedProduct){
			System.out.printf("%ntest 3.2 passed%n");
		} else {
			System.out.printf("%ntest 3.2 failed:  valA = %-7d  valB = %-7d  valC = %-7d product = %-10d  expected %-10d%n", valA, valB, valC, product, expectedProduct);
		}
		System.out.println(System.lineSeparator());
		
		
		//task4: test1
		
		int weight = 86;
		int height = 170;
		
		//TODO
		//calculate Body Mass Index by formula weight / height^2
		// keep the result in the variable bodyMassIndex  
		double heightInM = (double) height / 100; 
		double bodyMassIndex =  (double) weight  / (heightInM*heightInM);
		
		bodyMassIndex = Math.round(bodyMassIndex*100);
		bodyMassIndex /= 100;
				
		double expectedIndex = 29.76;
		
		if (Double.compare(bodyMassIndex, expectedIndex) == 0){
			System.out.printf("%ntest 4.1 passed%n");
		} else {
			System.out.printf("%ntest 4.1 failed:  weight = %-3d (kg) height = %-3d (cm)  index = %.2f  expected %.2f%n", weight, height, bodyMassIndex, expectedIndex);
		}
        System.out.println(System.lineSeparator());
		
		
		//task5: test1
        
		int a1 = 4; 
		int d = 3;
		int n = 2;
		
		//TODO
		// calculate Sum of the first n terms of the arithmetic progression starting from a1
		// Do not use loop! Use arithmetic Series Formula for sum
		// keep the result in the variable s  
		long s = n/2*(2*a1 + (n-1)*d);
		
		long expectedS = 11;
		if (s == expectedS){
			System.out.printf("%ntest 5.1 passed%n");
		} else {
			System.out.printf("%ntest 5.1 failed:  a = %-3d  d = %-3d  n = %-3d sum = %-5d  expected %-5d%n", a, d, n, s, expectedS);
		}
		
		//task5: test2
		
		a1 = 100;
		d = -1000;
		n = 10000;
		
		//TODO
		// calculate Sum of the first n terms of the arithmetic progression starting from a1
		// Do not use loop! Use arithmetic Series Formula for
		s = (long)n/2*(2*a1 + (n-1)*d);
		
		expectedS = -49_994_000_000L;
		if (s == expectedS){
			System.out.printf("%ntest 5.2 passed%n");
		} else {
			System.out.printf("%ntest 5.2 failed:  a = %-3d  d = %-3d  n = %-3d sum = %-10d  expected %-10d%n", a, d, n, s, expectedS);
		}
		
		//task6: test1
        
		int x1 = 1; 
		int y1 = 1;
		int x2 = -5;
		int y2 = 5;
		
				
		//TODO
		// calculate distance between (x1,y1) and (x2, y2)
		// keep the result in the variable dist  
		double dist =  length(x2, x1, y2, y1);
		dist = Math.round(dist*1E6);
		dist /= 1E6;
		
				
		double expectedDist = 7.211103;
		if (Double.compare(dist, expectedDist) == 0){
			System.out.printf("%ntest 6.1 passed%n");
		} else {
			System.out.printf("%ntest 6.1 failed:  A (%d, %d)  B(%d, %d) AB = %f  expectedAB =  %f%n", x1, y1, x2, y2, dist, expectedDist);
		}
		
		//task6: test2

		x1 = 10; 
		y1 = 10;
		x2 = 10;
		y2 = 10;
				
		//TODO
		// calculate distance between (x1,y1) and (x2, y2)
		// keep the result in the variable dist  
		dist = length(x2, x1, y2, y1);
				
		expectedDist = 0.0;
		if (Double.compare(dist, expectedDist) == 0){
			System.out.printf("%ntest 6.2 passed%n");
		} else {
			System.out.printf("%ntest 6.2 failed:  A (%d, %d)  B(%d, %d) AB = %f  expectedAB =  %f%n", x1, y1, x2, y2, dist, expectedDist);
		}
		
	}
	 private static double length(int x2, int x1, int y2, int y1){
		return  Math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	 }
	
	
}
