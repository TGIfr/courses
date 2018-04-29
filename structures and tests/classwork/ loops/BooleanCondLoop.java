import java.util.Random;;

public class BooleanCondLoop {

	public static void main(String[] args) {
		/**
		Illustrates the use of a boolean variable to end loop iteration.
		*/
		
		int sum = 0;
		boolean areMore = true;
		Random rand = new Random ();
		while (areMore) {
		     int next = rand.nextInt(20)- 5;
		     System.out.println("next  = " + next);
		     if (next < 0){
		         areMore = false;
		     }else{
		         sum = sum + next;
		     }
		 }
		System.out.println("The sum of the numbers is " + sum);
		    }
		}

