package test2;



public class Main {

	public static void main(String[] args) {
		// posMin is always from 0 to N(it is provided by the previous part), so there are only 2 situations to check 
		int N1 = 5;
		int posMin = 0;
		//test 2.1
		// array1.length = N1
		int array1[] = { 0, 5 , 6, 7 ,8 };
		
		int N2 = array1.length - posMin;
		int[] array2 = new int[N2];
		for (int i = posMin, j = 0; i < array1.length; i++, j++) {
			array2[j] = array1[i];
		}
		if( array2.length == N1 - posMin){
			System.out.printf("\n2.1 Passed \n");
		} else{
			System.out.printf("\n2.1 Not Passed \n");
		}
		//test 2.2
		// array2.length = N3
		int N3 = 5;
		posMin = 5;
		int array3[] = { 0, 5 , 6, 7 ,8 };
		
		int N4 = array3.length - posMin;
		int[] array4 = new int[N4];
		for (int i = posMin, j = 0; i < array3.length; i++, j++) {
			array4[j] = array3[i];
		}
		if( array4.length == N3 - posMin){
			System.out.printf("\n2.1 Passed \n");
		} else{
			System.out.printf("\n2.1 Not Passed \n");
		}

		
	}

}
