package test3;



public class Main {

	public static void main(String[] args) {
		// there are only 2 situations: array has elements or it don't, so program check's only it
		//test 3.1
		int array1[] = { 0, 5 , 6, 7 ,8 };
		
		int product = 1;
		for(int i = 0; i < array1.length; i = i + 2){
			product *= array1[i];
		}
		if(array1.length == 0){
			System.out.printf("\nThere is no elements in array2\n");
		} else {
			System.out.printf("\nProduct of elements with even position in array1 is %d\n", product);
		}
		if( product == 0 * 5 * 6 * 7 * 8){
			System.out.printf("\n3.1 Passed \n");
		} else{
			System.out.printf("\n3.1 Not Passed \n");
		}
		
		//test 3.2
		int array2[] = {};
		
		product = 1;
		for(int i = 0; i < array2.length; i = i + 2){
			product *= array2[i];
		}
		if(array2.length == 0){
			System.out.printf("\nThere is no elements in array2\n");
		} else {
			System.out.printf("\nProduct of elements with even position in array2 is %d\n", product);
		}
		if( product == 1){
			System.out.printf("\n3.2 Passed \n");
		} else{
			System.out.printf("\n3.2 Not Passed \n");
		}
		

		
	}

}
