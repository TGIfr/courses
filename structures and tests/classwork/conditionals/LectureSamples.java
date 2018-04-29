import java.util.Random;

public class LectureSamples {

	public static void main(String[] args) {
		int a = 678;
		int b = -34;
		int c = -105;
		if (a > b) {
			System.out.println("a > b");
		}
		System.out.println("Bye!");

		
		int number = 0;
		number = (int)(100*Math.random()); 
		if(number%2 == 0) {
			System.out.println("You have got an even number, " + number);    
		} else {
		    System.out.println("You have got an odd number, " + number); 
		}

		int min = 0;
		if (a > b){
			if (b > c){
				min = c;
			} else {
				min = b;
			}
		} else {
			if (a > c){
				min = c;
			} else {
				min = a;
			}
		}
		System.out.println("min = " + min);
		

	}

}
