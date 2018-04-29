package task_3;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * KPI- FPM - PZKS Course:
 * <p>
 * Algorithms and Data Structures (1) Laboratory work 1
 * 
 * @author Olena Khomenko.
 *         <p>
 *         This is a program skeleton for part 3 of lab 1.
 *         <p>
 *         Write your code in the places of the program which are marked by TODO
 *         marker. Run program If all tests are passed, it's OK
 */

public class Main {
	static ConsoleOutputCapturer cocp = new ConsoleOutputCapturer();
	private static String currenDir = System.getProperty("user.dir") + File.separatorChar + "testData";
	private static String newLine = System.lineSeparator();
	private static List<String> contentsTest1 = readFile(currenDir, "test1.txt");
	private static List<String> contentsTest3 = readFile(currenDir, "test3.txt");
	private static List<String> contentsTest4 = readFile(currenDir, "test4.txt");
	final static int numLines = 5; // number of lines to output for test 4

	public static void main(String[] args) {

		// before testing task1
		// write the body of method printPowerOfTwo

		// task 1: test1
		// power = 5
		cocp.start();
		printPowerOfTwo(5);
		testTask1("1.1", cocp.stop());

		// task 1: test2
		// power = 0
		cocp.start();
		printPowerOfTwo(0);
		testTask1("1.2", cocp.stop());

		// task 1: test3
		// power = 1
		cocp.start();
		printPowerOfTwo(1);
		testTask1("1.3", cocp.stop());

		// task 1: test4
		// power = -5
		cocp.start();
		printPowerOfTwo(-5);
		testTask1("1.4", cocp.stop());

		// task 2: test1
		int n = 6;
		// TODO
		// calculate the nth harmonic number calculated
		// by formula 1/1 + 1/2 + 1/3 + ... + 1/n
		// keep harmonic number in the variable harmNumb
		double harmNumb = Double.MIN_VALUE;
		for(int i = 1; i <= n; i ++){
			harmNumb += 1.0 / i;
		}

		testWithDoubles("2.1", harmNumb, 2.4499999999999997, 1E-15);
		System.out.println();

		// task 3: test1
		cocp.start();
		// TODO
		// Print the integers from 100 to 199 with five integers per line
		// Separate each number in the line by blank
		// The output that evaluated to is in the file testData/test3.txt
		// Hint: use one for-loop, one if-else statement and the % operator
		for(int i = 100; i < 200; i++){
			System.out.print(i);
			if((i + 1)% 5 == 0){	
				System.out.println();
			} else {
				System.out.print(" ");
			}
		}
		System.out.println();
		

		testTask3("3.1", cocp.stop());
		System.out.println();
		

		// task 4:
		// Write nested for loop to print numbers and asterisks as the following
		// four samples
		// number of lines is 5 as declare before main() in variable numLines
		// File "test4.txt" contains expected output that are used to evaluate
		// your output

		cocp.start();
		// TODO: write loop that prints
		// *1
		// **2
		// ***3
		// ****4
		// *****5
		for(int i = 0; i < 5; i++){
			for(int a = 0; a <= i ; a ++){
				System.out.print("*");
			}
			System.out.print(i + 1);
			System.out.println();
		}

		testTask4("4.1", cocp.stop());

		cocp.start();
		// TODO: write loop that prints
		// ****1
		// ***2
		// **3
		// *4
		// 5
		for(int i = 0; i < 5; i++){
			for(int a = 0; a < 4 - i ; a ++){
				System.out.print("*");
			}
			System.out.print(i + 1);
			System.out.println();
		}

		testTask4("4.2", cocp.stop());

		cocp.start();
		// TODO: write loop that prints
		// ****1
		// ***22
		// **333
		// *4444
		// 55555
		for(int i = 0; i < 5; i++){
			for(int a = 0; a < 4 - i ; a ++){
				System.out.print("*");
			}
			for( int b = 0; b <= i; b++){
				System.out.print(i + 1);
			}
			System.out.println();
		}

		testTask4("4.3", cocp.stop());

		cocp.start();
		// TODO: write loop that prints
		// ****1
		// ***2*
		// **3**
		// *4***
		// 5****
		for(int i = 0; i < 5; i++){
			for(int a = 0; a < 5 ; a ++){
				if( a  == 4 - i ){
					System.out.print(i + 1);
				} else {
					System.out.print("*");
				}
			}
			System.out.println();
		}

		testTask4("4.4", cocp.stop());

		// task 5: test1

		int a1 = 4;
		int d = 3;
		n = 2;

		// TODO
		// calculate Sum of the first n terms of the arithmetic progression
		// starting from a1 using loop
		// keep the result in the variable s
		long s = Long.MIN_VALUE;
		
		for(int i = 0; i < n; i ++){
			if(i == 0){
				s = 0;
			}
			s += a1 + d*i;
		}

		// TODO
		// Calculate the expected result by formula from task1.5 (the first part
		// of lab 1)
		// keep the expected result in the variable expectedS
		long expectedS = Long.MAX_VALUE;
		
		expectedS = ((long)n*(2*a1 + (n-1)*d)) / 2;
		
		if (s == expectedS) {
			System.out.printf("%ntest 5.1 passed%n");
		} else {
			System.out.printf("%ntest 5.1 failed:  a1 = %-3d  d = %-3d  n = %-3d sum = %-5d  expected %-5d%n", a1, d, n,
					s, expectedS);
		}

		// task 5: test2

		a1 = 100;
		d = -1000;
		n = 10000;

		// TODO
		// calculate Sum of the first n terms of the arithmetic progression
		// starting from a1 using loop
		// keep the result in the variable s
		s = Long.MIN_VALUE;
		
		for(int i = 0; i < n; i ++){
			if(i == 0){
				s = 0;
			}
			s += a1 + d*i;
		}

		// TODO
		// Calculate the expected result by formula from task1.5 (the first part
		// of lab 1)
		// keep the expected result in the variable expectedS
		expectedS = Long.MAX_VALUE;
		
		expectedS = ((long)n*(2*a1 + (n-1)*d)) / 2;
		
		if (s == expectedS) {
			System.out.printf("%ntest 5.2 passed%n");
		} else {
			System.out.printf("%ntest 5.2 failed:  a1 = %-3d  d = %-3d  n = %-3d sum = %-5d  expected %-5d%n", a1, d, n,
					s, expectedS);
		}

		// task 6: test1
		n = 5;
		// TODO: Calculate the expression
		// P=П(from i = 1 to n) do ∑(from j = 1 to i) do (4/3 (j-1)) /(i + √i)
		// keep the result in the variable product

		double product = 0.0;
		double semiRes = 0.0;
		for(int i = 1; i <= n ; i ++){
			if( i == 1){
				semiRes = 0;
				product = 1;
			}
			semiRes +=  4.0 * i / 3  - 1;
			product *= semiRes / ( i + Math.sqrt(i));
		}

		testWithDoubles("6.1", product, 0.332646, 1E-06);

		// task6: test2
		n = 1;
		// TODO: Calculate the expression
		// P=П(from i = 1 to n) do ∑(from j = 1 to i) do (4/3 (j-1)) /(i + √i)
		// keep the result in the variable product

		product = 0.0;
		for(int i = 1; i <= n ; i ++){
			if( i == 1){
				semiRes = 0;
				product = 1;
			}
			semiRes +=  4.0 * i / 3  - 1;
			product *= semiRes / ( i + Math.sqrt(i));
		}

		testWithDoubles("6.2", product, 0.166667, 1E-06);

		// task7a: test1
		// TODO
		// Compute p-th root of nonnegative number a
		// using Newton's method
		double epsilon = 1E-06; // relative error tolerance
		double p = 3.0;
		double a = 47.0;
		double next = 0.0; // estimate of the p-th root of a
		double prev = a / 2;
		// initialize prev = a /2
		// replace next = (1 /p) * ((p - 1) * prev + a / prev ^ (p - 1))
		// repeat until desired accuracy reached
		next = (1 / p) * ((p - 1) * prev + a / Math.pow(prev, p - 1));
		do {
			prev = next;
			next = (1 / p) * ((p - 1) * prev + a / Math.pow(prev, p - 1));
		} while( Math.abs(next - prev) > epsilon );
		testWithDoubles("7.1", next, Math.pow(a, 1.0 / p), epsilon);

		// task7b: test2
		// TODO
		// Compute square root of nonnegative number a
		// using Geron's method
		epsilon = 1E-15; // relative error tolerance
		a = 217.456;
		double t = 0.0; // estimate of the square root of a

		// initialize t = a
		// replace t with the average of a/t and t
		// repeat until desired accuracy reached
		t = a  / 2;
		do {
			prev = t;
			t = (prev + a / prev) / 2;
		} while (Math.abs(t - prev) > epsilon );

		testWithDoubles("7.2", t, Math.sqrt(a), epsilon);

	}

	/**
	 * calculate and output the power of two from 0 to n; in the case of n < 0
	 * output message "ERROR: n < 0"
	 * 
	 * @param n
	 *            value of raising to power (n >= 0)
	 * 
	 */
	static void printPowerOfTwo(int n) {
		// TODO:
		// print out the power of two from 0 to n
		// each line contains two values: power and 2^power separated by blank
		// for example:
		// 2 4
		// java example for n = 2 and p = 4
		// System.out.print(n + " " + p);
		int p = 0;
		if(n < 0){
			System.out.print("ERROR: n < 0\n");
			
		} else{
			for(int i = 0; i < n + 1; i++){
				p = (int) Math.pow(2, i);
				System.out.print(i + " " + p);
				System.out.println();
			}
		}

	}

	private static List<String> readFile(String dirName, String fileName) {
		Path path = Paths.get(dirName, fileName);
		List<String> contents = new ArrayList<>();
		if (Files.exists(path) && Files.isReadable(path)) {
			try {
				contents = Files.readAllLines(path, StandardCharsets.UTF_8);
			} catch (IOException e) {
				System.err.println("ERROR:read " + fileName + "  error ");
			}
		} else {
			System.err.println("ERROR:open " + fileName + "  error ");
		}
		return contents;
	}

	/**
	 * check the task1 (raising to power) get the string from console and
	 * compare it to expected string expected string depends of number of test
	 * 
	 * @param testNumber
	 *            number of test in format "1.x"
	 * @param out
	 *            string to test
	 */
	private static void testTask1(String testNumber, String out) {
		// remove leading and trailing whitespace
		out = out.trim();

		String expected = "";
		switch (testNumber.substring(2)) {
		case "1":
			if (contentsTest1.size() == 0) {
				System.out.println("ERROR: cann't test task" + testNumber + ". Expected data not found!");
			} else {
				expected = contentsTest1.toString();
				expected = expected.substring(1, expected.length() - 1);
				out = out.replaceAll(newLine, ", ");
			}
			break;
		case "2":
			expected = "0 1";
			break;
		case "3":
			expected = "0 1" + newLine + "1 2";
			break;
		case "4":
			expected = "ERROR: n < 0";
			break;
		default:
			expected = "ERROR: Invalid test number";
		}

		if (out.equals(expected)) {
			System.out.printf("test %s passed%n%n", testNumber);
		} else {
			System.out.printf("test %s failed:%nexpected %n%s%n", testNumber, expected);
		}
	}

	private static void testWithDoubles(String testNumber, double evaluated, double expected, double tolerance) {
		if (Math.abs(evaluated - expected) < tolerance) {
			System.out.printf("%ntest %s passed%n", testNumber);
		} else {
			System.out.printf("%ntest %s failed:  evaluated = %f  expected = %f%n", testNumber, evaluated, expected);
		}
	}

	private static boolean compareListAndString(List<String> list, String str) {
		// remove leading and trailing whitespace
		str = str.trim();
		String[] strMas = str.split(newLine);
		String[] listMas = new String[list.size()];
		listMas = list.toArray(listMas);
		return Arrays.equals(strMas, listMas);
	}

	private static void testTask3(String testNumber, String out) {
		if (contentsTest3.size() == 0) {
			System.out.println("ERROR: cann't test task" + testNumber + ". Expected data not found!");
		} else {
			if (compareListAndString(contentsTest3, out) == true) {
				System.out.printf("test %s passed%n%n", testNumber);
			} else {
				System.out.printf("test %s failed:%nexpected output in the file: \"test%s.txt\"%n", testNumber,
						testNumber.substring(0, 1));
			}
		}
	}

	private static void testTask4(String testNumber, String out) {
		int testSubNumber = Integer.parseInt(testNumber.substring(2));
		if (contentsTest4.size() == 0) {
			System.out.println("ERROR: cann't test task" + testNumber + ". Expected data not found!");
		} else {
			List<String> expectedOut = contentsTest4.subList((testSubNumber - 1) * numLines, testSubNumber * numLines);
			if (compareListAndString(expectedOut, out) == true) {
				System.out.printf("test %s passed%n%n", testNumber);
			} else {
				System.out.printf("test %s failed:%nexpected output in the file: \"test%s.txt\"%n", testNumber,
						testNumber.substring(0, 1));
			}
		}
	}

}
