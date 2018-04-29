package test1;



public class Main {
	public static void main(String[] args) {
		//test 1.1
		int N1 = 46;
		int[] array1 = new int[N1];
		int P = 44;
		for(int i = 0; i < N1; i ++){
			array1[i] = i;
		}
		if( findPosMin(array1, P) == 45){
			System.out.printf("\n1.1 Passed \n");
		} else{
			System.out.printf("\n1.1 Not Passed \n");
		}
		// test 1.2
		int N2 = 46;
		int[] array2 = new int[N2];
		P = 4;
		for(int i = 0; i < N2; i ++){
			array2[i] = 5;
		}
		if( findPosMin(array2, P) == 0){
			System.out.printf("\n1.2 Passed \n");
		} else{
			System.out.printf("\n1.3 Not Passed \n");
		}
		// test 1.3
		int N3 = 0;
		int[] array3 = new int[N3];
		P = 4;
		for(int i = 0; i < N3; i ++){
			array3[i] = 5;
		}
		if( findPosMin(array3, P) == array3.length){
			System.out.printf("\n1.3 Passed \n");
		} else{
			System.out.printf("\n1.3 Not Passed \n");
		}
		
		// test 1.4
		int N4 = 2;
		int[] array4 = new int[N4];
		P = 4;
		for(int i = 0; i < N4; i ++){
			array4[i] = i * 5;
		}
		if( findPosMin(array4, P) == 1){
			System.out.printf("\n1.4 Passed \n");
		} else{
			System.out.printf("\n1.4 Not Passed \n");
		}
		// test 1.5
		int N5 = 3;
		int[] array5 = new int[N5];
		P = 4;
		for(int i = 0; i < N5; i ++){
			array5[i] = i * 3;
		}
		if( findPosMin(array5, P) == 2){
			System.out.printf("\n1.5 Passed \n");
		} else{
			System.out.printf("\n1.5 Not Passed \n");
		}
	}
	static private int findPosMin(int [] array, int P){
		int posMin = array.length;
		//search for needed position
		for(int i = 0; i < array.length; i ++){
			// search of first correct element
			if(array[i] > P && posMin == array.length){
				posMin = i;
			}
			//works only if there are at least one correct element
			if(posMin != array.length && array[i] < array[posMin] && array[i] > P){
				posMin = i;
			}
		}
		return posMin;
	}

}
