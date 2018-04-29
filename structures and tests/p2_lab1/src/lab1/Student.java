package lab1;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 1
 * 
 * @author Olena Khomenko
 * 
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
	public void copyStudent(Student toCopy){
		this.name = toCopy.name;
		this.surname = toCopy.surname;
		this.cityCode = toCopy.cityCode;
		this.phone = toCopy.phone;
	}
	/**
	 * name of this student
	 */
	String name;
	/**
	 * surname of this student
	 */
	String surname;

	/**
	 * number of group (3-digit number)
	 */
	String cityCode;
	/**
	 * student's phone number
	 */
	String phone;


	/**
	 * Sets the surname of a student
	 * 
	 * @param surname
	 *            string specified the surname
	 */
	public void setSurname(String surname) {
		this.surname = surname;
	}
	/**
	 * Sets the name of a student
	 * 
	 * @param name
	 *            string specified the name
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * Sets the city code of a student
	 * 
	 * @param cityCode
	 *            integer specified the number of student's group
	 */
	public void setCityCode(String cityCode) {
		this.cityCode = cityCode;
	}
	/**
	 * Sets the phone of a student
	 * 
	 * @param phone
	 *            integer specified the number of student's studPhone
	 */
	public void setPhone(String phone) {
		this.phone = phone;
	}

	/**
	 * Outputs formatted values of fields in standard output
	 * 
	 */
	public void print() {
		System.out.println(String.format("%-10s|  %-10s|  %-6s|  %-10s|", name, surname, cityCode, phone));
	}

	/**
	 * Determines if the specified string is a student's name. This string is
	 * valid if it contains all alphabet letters and begins from uppercase
	 * letter
	 * 
	 * @param name
	 *            the string to be tested
	 * @return true if the specified string is a name, false otherwise.
	 */
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
	/**
	 * Determines if the specified string is a student's surname. This string is
	 * valid if it contains all alphabet letters and begins from uppercase
	 * letter
	 * 
	 * @param surname
	 *            the string to be tested
	 * @return true if the specified string is a surname, false otherwise.
	 */
	public static boolean isValidSurname(String surname) {
		return isValidName(surname);
	}

	/**
	 * Determines if the specified string is number of cityCode. This string is
	 * valid if it represents 3-digit number
	 * 
	 * @param cityCodeStr
	 *            the string to be tested
	 * @return true if the specified string is a correct number of group, false
	 *         otherwise.
	 */
	public static boolean isValidCityCode(String cityCodeStr) {
		if (cityCodeStr.length() == 3) {
			for(int i = 0; i < 3; i++){
				char ch = cityCodeStr.charAt(i);
				if(!Character.isDigit(ch)){
					return false;
				}
			}
			return true;
		}
		return false;
	}
	/**
	 * Determines if the specified string is phone number . This string is
	 * valid if it is a 10-digit number
	 * 
	 * @param phoneStr
	 *            the string to be tested
	 * @return true if the specified string is a correct number of group, false
	 *         otherwise.
	 */
	public static boolean isValidPhone(String phoneStr) {
		if (phoneStr.length() == 10) {
			for(int i = 0; i < 10; i++){
				char ch = phoneStr.charAt(i);
				if(!Character.isDigit(ch)){
					return false;
				}
			}
			return true;
		}
		return false;
	}

}
