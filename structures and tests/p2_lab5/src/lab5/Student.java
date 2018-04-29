package lab5;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 5
 * 
 * @author Olena Khomenko <br>
 *         Represents information about student: its name and number of course <br>
 *         This class is a sample how to define class, fields and methods
 * 
 *         Rewrite this class and its methods <br>
 *         Choose information to be saved in a class from lab manuals (table 1,
 *         col.2).<br>
 * 
 *         Write methods setXXX to set specified value to the field XXX. <br>
 * 
 *         Write method print to output information about student (values of the
 *         fields) in formatted string. <br>
 * 
 *         Write static methods boolean isValidXXX to check whether specified
 *         string could set (or convert and set) to the field XXX
 *
 */

public class Student {

	private int cardNumber;


	String name;

	String surname;

	String gender;

	float mark;

	int course;

	public Student(int cardNumber) {
		this.cardNumber = cardNumber;
	}

	public int getkey() {
		return cardNumber;
	}

	Student(String name, String surname, String gender, float mark, int cardNumber, int course){
		this.name = name;
		this.surname = surname;
		this.gender = gender;
		this.mark = mark;
		this.cardNumber = cardNumber;
		this.course = course;
	}

	@Override
	public String toString() {
		return String.format("Card: %-10d|  Mark: %.2f|  N: %s|  S: %s|  G: %s|  Course: %-1d",
				cardNumber, mark, name, surname, gender, course);
	}

	/**
	 * Determines if the specified string is valid card number: contains only
	 * one digit character
	 * 
	 * @param number
	 *            the string to be tested
	 * @return true if the specified string is a valid card number, false
	 *         otherwise.
	 */
	public static boolean isValidCardNumber(String number) {
		char[] chArray = number.toCharArray();
		for (char ch : chArray) {
			if (!Character.isDigit(ch)) {
				return false;
			}
		}
		return true;

	}

	public static boolean isValidMark(String mark){
		char[] chArray = mark.toCharArray();
		for (char ch : chArray) {
			if (!Character.isDigit(ch) && ch != '.') {
				return false;
			}
		}
		return true;
	}

	public static boolean isValidCourse(String course){
		return isValidCardNumber(course);
	}

	public static boolean isValidName(String name) {
		if (!Character.isUpperCase(name.charAt(0))) {
			return false;
		}
		for (int i = 1; i < name.length(); i++) {
			if (!Character.isAlphabetic(name.charAt(i)))
				return false;
		}
		return true;
	}

	public static boolean isValidGender(String gender) {
		return isValidName(gender);
	}

	public boolean equal(Student st) {
		if(this.name.equals(st.name) &&
				this.surname.equals(st.surname)&&
				this.gender.equals(st.gender) &&
				this.course == st.course &&
				this.cardNumber == st.cardNumber &&
				Math.abs(this.mark - st.mark) < 0.00001)
			return true;
		return false;
	}
	public static boolean isValidSurname(String surname) {
		return isValidName(surname);
	}

}
