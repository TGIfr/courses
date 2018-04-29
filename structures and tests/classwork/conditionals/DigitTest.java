import java.util.Random;

public class DigitTest {

	public static void main(String[] args) {
		Random r = new Random();
		char ch = (char) (r.nextInt(94) + 33);
		System.out.println("Code of character '" + ch + "'   is  " + (int) ch);

		if (ch >= '0' && ch <= '9') {
			System.out.println("its a digit character");
		} else {
			System.out.println("its non-digit character");
		}

		System.out.println("Test with Character class : "
				+ Character.isDigit(ch));

	}

}
