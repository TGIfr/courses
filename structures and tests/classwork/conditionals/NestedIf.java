public class NestedIf {

	public static void main(String[] args) {
		int number = 49;
	
		if(number%2 == 0) {                 // Test if it is even
			  if(number < 50) {                 // Output a message if number is < 50
			    System.out.println("You have got an even number < 50, " + number);
			  }

		} else {
			  System.out.println("You have got an odd number, " + number); // It is odd
			}
		
		
		if(number%2 == 0)                   // Test if it is even
			  if(number < 50 )                  // Output a message if number is < 50
			    System.out.println("You have got an even number < 50, " + number);
			  else
				  System.out.println("You have got an odd number, " + number); // It is odd



	}

}
