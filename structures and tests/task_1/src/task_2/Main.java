package task_2;
/**
 * KPI- FPM - PZKS
 * Course: Algorithms and Data Structures (1)
 * Laboratory work 1
 * @author Olena Khomenko
 * This is a program skeleton for part 2 of lab 1
 * Write your code in the places of the program which are marked by TODO marker 
 * Run program
 * If all tests are passed, it's OK
 */

public class Main {

	public static void main(String[] args) {
		
		//task 1: test1 
		
		int valA = 15;
		int valB = 0;
		int valC = 15;
						
		//TODO
		// isEqial is true, if valA, valB and valC are equals, otherwise false  
		// keep the result in the variable isEqial
		
		 
		
		boolean isEqual = equalTest( valA,  valB,  valC);
		
		
		//TODO
		// Output message "equals", if values are equals, otherwise "not equals"
		
		
		
		testTask1("1.1", valA, valB, valC, isEqual, false);
		
		//task 1: test2 
				
		valA = -500;
		valB = -500;
		valC = -500;
				
		//TODO
		// isEqial is true, if valA, valB and valC are equals, otherwise false  
		// keep the result in the variable isEqial
		
		isEqual =  equalTest( valA,  valB,  valC);
		//TODO
		// Output message "equals", if values are equals, otherwise "not equals"
		
		
		
		testTask1("1.2", valA, valB, valC, isEqual, true);
		
		//task 1: test3 
		
		valA = -5;
		valB = 5;
		valC = 325698;
					
		//TODO
		// isEqial is true, if valA, valB and valC are equals, otherwise false  
		// keep the result in the variable isEqial
		
		
		isEqual = equalTest( valA,  valB,  valC);
		
		
				
		//TODO
		// Output message "equals", if values are equals, otherwise "not equals"
		
		
				 
		testTask1("1.3", valA, valB, valC, isEqual, false);
		
		
		//task 2: test1 
		//TODO
		// find the minimum value among valA, valB and valC 
		// keep the result in the variable min
		int min = compare(valA, valB, valC);
		
		// version 1
		/*if (valA == valB && valA == valB){
			min = valA;
			}
	   
		else {
			if(valA<valB){
				if(valA<valC){
					min = valA;
				}
				else{
					min = valC;
				}
				
			} else {
				if(valB<valC){
					min = valB;
				} else min = valC;
			}
		}*/
		
		testTask2("2.1", valA, valB, valC, min, -5);
		
		//task 2: test2
		
		valA = -5000;
		valB = -3500;
		valC = Integer.MIN_VALUE;
		//TODO
		// find the minimum value among valA, valB and valC 
		// keep the result in the variable min
		
		min = compare(valA, valB, valC);
		
		
		testTask2("2.2", valA, valB, valC, min, Integer.MIN_VALUE);
		
		//task 2: test3
		
		valA = 56;
		valB = 56;
		valC = 56;
		//TODO
		// find the minimum value among valA, valB and valC 
		// keep the result in the variable min
		min = compare(valA, valB, valC);
		testTask2("2.3", valA, valB, valC, min, 56);
		
		
		//task 3: test1
		
		int weight = 86;
		int height = 170;
		
		//TODO
		//define Body Mass Index (BMI) category 
		//hint: use solution of task4 (lab1, part1)
		//BMI <= 18.5 			"Underweight"
		//BMI = 18.5 - 24.9		"Normal weight"	
		//BMI = 25-29.9			"Overweight"
		//BMI >= 30.0			"Obesity"
		// keep the result in the variable category
		
		String category = checkBodyMass( height, weight);
		
		
		//version 1
		/*double heightInM = (double) height / 100; 
		double bodyMassIndex =  (double) weight  / (heightInM*heightInM);
		
		bodyMassIndex = Math.round(bodyMassIndex*100);
		bodyMassIndex /= 100;
		
		
		if(bodyMassIndex <= 18.5){
			category = "Underweight";
		} else if(bodyMassIndex <= 24.9){
			category = "Normal weight";
		} else if (bodyMassIndex <= 29.9){
			category = "Overweight";
		} else category = "Obesity";*/
			
		
		
		testTask3 ("3.1", weight, height, category, "Overweight");
		
		//task 3: test2
		
		// TODO
		//define Body Mass Index (BMI) category 
		// keep the result in the variable category
		weight = 50;
		
		category = checkBodyMass( height, weight);
		
		testTask3 ("3.2", weight, height, category, "Underweight");
		
		//task 3: test3
		
		// TODO
		//define Body Mass Index (BMI) category 
		// keep the result in the variable category
		weight = 100;
		category = checkBodyMass( height, weight);
				
		testTask3 ("3.3", weight, height, category, "Obesity");
	
	
		//task 4: test1
		double x = 12.54;
		//TODO calculate y by formula (see manuals to lab1)
		double y = calculate(x);
		
		testTask4 ("4.1", x, y, -0.00209602209462795);
		
		//task 4: test2
		x = -12.54;
		
		//TODO calculate y by formula (see manuals to lab1)
		y = calculate(x);
				
		testTask4 ("4.2", x, y, 0.03200085289221526);
		
			
		//task 5: test1
		
		valA = 90;
		valB = 105;
		valC = 110;
		int valD = 110;
		// TODO
		//check the condition valA <= valB <= valC <= valD 
		// keep the result of comparison in the variable isSorted
		boolean isSorted = sortTest(valA, valB, valC, valD);
		
		//version 1
		/*if(valA<= valB){
			if(valB<=valC){
				if(valC<=valD){
					isSorted = true;
				} else isSorted = false;
			} else isSorted = false;
		} else isSorted = false;*/
		
		testTask5("5.1", valA, valB, valC, valD, isSorted, true);
		
		//task 5: test2
		valD = -valD;
		// TODO
		//check the condition valA <= valB <= valC <= valD 
		// keep the result of comparison in the variable isSorted
		isSorted = sortTest( valA,  valB,  valC,  valD);
		
		
		testTask5("5.2", valA, valB, valC, valD, isSorted, false);
		
		//task 6: test1
		
		// TODO
		//calculate the arithmetic mean of only positive values valA, valB, valC, valD
		// keep the result in the variable arithmMeanPositive
		double arithmMeanPositive = aritmMeanPos(valA, valB, valC, valD);
		
		
		//version 1
		/*int summOfPositive = 0;
		int numberOfPositive = 0;
		
		if (valA >0){
			summOfPositive += valA;
			numberOfPositive++;
		}
		if (valB >0){
			summOfPositive += valB;
			numberOfPositive++;
		}
		if (valC >0){
			summOfPositive += valC;
			numberOfPositive++;
		}
		if (valD >0){
			summOfPositive += valD;
			numberOfPositive++;
		}
		if(numberOfPositive>0){
			arithmMeanPositive = (double) summOfPositive/numberOfPositive;
		}
		*/
		
				
		testTask6("6.1", valA, valB, valC, valD, arithmMeanPositive, 101.66666667 );
		
		//task 6: test2
		// TODO
		//calculate the arithmetic mean of only positive values valA, valB, valC, valD
		// keep the result in the variable arithmMeanPositive
		
		valA = -90;
		valB = -105;
		valC = -110;
		valD = -200;
		
		arithmMeanPositive = aritmMeanPos(valA, valB, valC, valD);
		
		
		testTask6("6.2", valA, valB, valC, valD, arithmMeanPositive, 0.0 );
		
	}

	private static void testTask1(String message, int a, int b, int c, boolean answer, boolean expected) {
		if (answer == expected){
			System.out.printf("%ntest %s passed%n", message);
		} else {
			System.out.printf("%ntest %s failed:  valA = %d, valB = %d, valC = %d answer: %s  expected: %s%n", message, a, b, c, answer? "equals": "not equals", expected? "equals": "not equals");
		}
	}
	
	private static void testTask2(String message, int a, int b, int c, int rez, int expected) {
		if (rez == expected){
			System.out.printf("%ntest %s passed%n", message);
		} else {
			System.out.printf("%ntest %s failed:  valA = %d, valB = %d, valC = %d answer: %d  expected: %d%n", message, a, b, c, rez, expected);
		}
	}
	
	private static void testTask3(String message, int weight, int height, String category, String expected) {
		if (category.equals(expected)){
			System.out.printf("%ntest %s passed%n", message);
		} else {
			System.out.printf("%ntest %s failed:  weight = %d, height = %d, answer: %s  expected: %s%n", message, weight, height, category, expected);
		}
	}
	
	private static void testTask4(String message, double x, double y, double expected) {
		if (Double.compare(y, expected) == 0){
			System.out.printf("%ntest %s passed%n", message);
		} else {
			System.out.printf("%ntest %s failed:  x = %f, y = %f  expected: %f%n", message, x, y, expected);
		}
	}
	
	private static void testTask5(String message, int a, int b, int c, int d, boolean answer, boolean expected) {
		if (answer == expected){
			System.out.printf("%ntest %s passed%n", message);
		} else {
			System.out.printf("%ntest %s failed:  valA = %d, valB = %d, valC = %d, valD = %d   answer: %s  expected: %s%n", message, a, b, c, d, answer, expected);
		}
	}
	
	private static void testTask6(String message, int a, int b, int c, int d, double answer, double expected) {
		if (Math.abs(answer - expected) <= 0.1E-7){
			System.out.printf("%ntest %s passed%n", message);
		} else {
			System.out.printf("%ntest %s failed:  valA = %d, valB = %d, valC = %d, valD = %d   answer: %f  expected: %f%n", message, a, b, c, d, answer, expected);
		}
	}
	
	// task 1
	private static boolean equalTest(int valA, int valB, int valC){
		if( valA == valB && valA == valC){
			System.out.printf ("equals");
			return true;
		}
		else {
			System.out.printf("not equals");
			return false; 
		}
	}
	
	//task 2 
	private static int compare( int valA, int valB, int valC){
		
		if(valA<valB){
			if(valA<valC){
				return  valA;
			}
			else{
				return  valC;
			}
			
		} else {
			if(valB<valC){
				return valB;
			} return  valC;
		}
		
		
	}
		
	//task 3 
	private static String checkBodyMass(int height, int weight){
		double heightInM = (double) height / 100; 
		double bodyMassIndex =  (double) weight  / (heightInM*heightInM);
		
		bodyMassIndex = Math.round(bodyMassIndex*100);
		bodyMassIndex /= 100;
		
		
		if(bodyMassIndex <= 18.5){
			return "Underweight";
		} else if(bodyMassIndex <= 24.9){
			return "Normal weight";
		} else if (bodyMassIndex <= 29.9){
			return  "Overweight";
		} else return "Obesity";
	}
	
	//task 4
	private static double calculate(double x){
		double result = 0;
		if(x>3){
			result = (Math.sin(x)) / (Math.sqrt(x*x +1));
			return result;
		} else {
			result = (Math.log(1 +x*x)) / (1 + x*x);
			return result;
		}
		
	}
	
	//task 5 
	private static boolean sortTest(int valA, int valB, int valC, int valD){
		if(valA<= valB){
			if(valB<=valC){
				if(valC<=valD){
					return true;
				} else {
					return false;				
				}
			} else {
				return false;			
			}
		} else {
			return false;
		}
		
	}
	
	//task 6 
	private static double aritmMeanPos(int valA, int valB, int valC, int valD){
		int summOfPositive = 0;
		int numberOfPositive = 0;
		double arithmMeanPositive = 0.0;		
		if (valA >0){
			summOfPositive += valA;
			numberOfPositive++;
		}
		if (valB >0){
			summOfPositive += valB;
			numberOfPositive++;
		}
		if (valC >0){
			summOfPositive += valC;
			numberOfPositive++;
		}
		if (valD >0){
			summOfPositive += valD;
			numberOfPositive++;
		}
		if(numberOfPositive>0){
			arithmMeanPositive =  (double) summOfPositive/numberOfPositive;
		}
		return arithmMeanPositive;
		
	}
	
}
