package lab2;

import java.util.Random;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (1) Laboratory work 2
 * 
 * @author Olena Khomenko
 * 
 *         This is a program skeleton for lab 2 Write your code in the places of
 *         the program which are marked by TODO marker
 * 
 *         The size of array1 is 5 elements In order to test a program on
 *         different sizes you need to change N
 * 
 *         Test cases are: <br>
 *         array1.lenght >= 20 - Elements are unique. Searching is successful
 *         <br>
 *         array1.lenght >= 20 - Elements are not unique. Searching is
 *         successful<br>
 *         array1.lenght = 0 <br>
 *         array1.lenght = 2 - Searching is successful/non-successful <br>
 *         array1.lenght = 3 - Searching is successful/non-successful <br>
 *         Generate specific test data to test your program
 */

public class Main {
	private static final int N1 = 5; // amount of elements in the array1

	public static void main(String[] args) {

		// define array1
		int[] array1 = new int[N1];

		// fill the array1 by random values in range [0;49]
		Random rand = new Random();
		for (int i = 0; i < array1.length; i++) {
			array1[i] = rand.nextInt(50);
		}

		// output array1
		System.out.println("Array1:");
		for (int i = 0; i < array1.length; i++) {
			System.out.printf("%-3d", array1[i]);
		}
		System.out.println();

		// TODO
		// task 2.1
		// see the task from table, column 2

		
		int P = 45;
		int posMin = array1.length;
		
		//search for needed position
		for(int i = 0; i < array1.length; i ++){
			// search of first correct element
			if(array1[i] > P && posMin == array1.length){
				posMin = i;
			}
			//works only if there are at least one correct element
			if(posMin != array1.length && array1[i] < array1[posMin] && array1[i] > P){
				posMin = i;
			}
		}

		// TODO
		// print the results of task 2.1
		
		// if there was no correct elements, posMin is still == N1
		if(posMin != array1.length){
			System.out.printf("\nPosition of minimal element, that is larger than %d is: %d\n", P, posMin);
		} else {
			System.out.printf("\nThere is no elements,that are larger than %d\n", P);
		}
		// TODO
		// task 2.2
		// see the task from table, column 3

		// calculate the size of array2
		// sample: range from pos up to N-1
		
		//if there was no correct elements, size of array2 = 0
		// posMin is from 0 to N1 (array1.length). It is guaranteed by the previous part of code
		int N2 = array1.length - posMin;

		// create an array2 by size N2
		int[] array2 = new int[N2];

		// copy elements from array1 to array2
		
		// if there was no correct elements, it do nothing
		for (int i = posMin, j = 0; i < array1.length; i++, j++) {
			array2[j] = array1[i];
		}

		// TODO
		// output the array2
		// checks array2
		if (array2.length != 0) {
			System.out.println("\nArray2:");
			for (int i = 0; i < array2.length; i++) {
				System.out.printf("%-3d", array2[i]);
			}
		}
		System.out.println();
		// task 2.3
		// see the task from table, column 4
		
		int product = 1;
		for(int i = 0; i < array2.length; i = i + 2){
			product *= array2[i];
		}
		// TODO
		// print the results of task 2.3
		
		//check size of array2
		if(array2.length == 0){
			System.out.printf("\nThere is no elements in array2\n");
		} else {
			System.out.printf("\nProduct of elements with even position in array2 is %d\n", product);
		}
	}

}

/*
int n;
boolean[] primes=new boolean[n+1];
public void fillSieve() {
    Arrays.fill(primes,true);
    primes[0]=primes[1]=false;
    for (int i=2;i<primes.length;i++) {
        if(primes[i]) {
            for (int j=2;i*j<primes.length;j++) {
                primes[i*j]=false;
            }
        }
    }
}

    public static int gcd(int a,int b) {
        while (b !=0) {
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }
    
    
    
    public static int factorial(int n)
    {
        if (n == 0) return 1;
        return n * factorial(n-1);
    }


	public static int factorial(int n)
    {
        int ret = 1;
        for (int i = 1; i <= n; ++i) ret *= i;
        return ret;
    }
 
 
 // fibonacci 
     int a = 1;
     int b = 1;
     int n;
     int sum_fib;
     Scanner s = new Scanner(System.in);
     n = s.nextInt();
     for(int i = 0; i < n; i++){
         sum_fib = a + b;
         a = b;
         b = sum_fib;
         System.out.print(sum_fib + " ");
     }
 
 //numbers 
int number = 22;
int radix = 8;
int tempNumber = number;
String radixStr = "";
System.out.printf("number %d in radix %d = ", number, radix);
while (tempNumber != 0){
	int remainder = tempNumber % radix;
	radixStr = remainder + radixStr;
	tempNumber = tempNumber / radix;
}
System.out.println (radixStr);
System.out.println ("Test result: " + Integer.toOctalString(number));
 
 */
