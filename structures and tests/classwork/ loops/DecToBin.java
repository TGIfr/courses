package operators.loops.whiles;

public class DecToBin {

	public static void main(String[] args) {
		int number = 1500;
		int radix = 2;
		int tempNumber = number;
		String radixStr = "";
		System.out.printf("number %d in radix %d = ", number, radix);
		while (tempNumber != 0) {
			int remainder = tempNumber % radix;
			radixStr = remainder + radixStr;
			tempNumber = tempNumber / radix;
		}
		System.out.println(radixStr);
		System.out.println("Test result: " + Integer.toBinaryString(number).toUpperCase());
	}
}
