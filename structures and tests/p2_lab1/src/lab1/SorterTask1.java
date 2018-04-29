package lab1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import com.opencsv.CSVReader;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 1
 * 
 * @author Olena Khomenko
 * 
 *         This is a program skeleton for lab 1 (task1): <br>
 *         1) Read a csv file <br>
 *         2) Create the array of students and check data from the file<br>
 *         3) Output the array in a table view <br>
 *         4) Sort the array of students <br>
 *         5) Output sorted array in a table view
 * 
 *         Write your code in the places of the methods which are marked by TODO
 *         marker
 * 
 */

public class SorterTask1 {
	// name of file which stores data about students
	private static String fileName = "students5.csv";

	// path to the current directory that contains directory "data"
	private static String currenDir = System.getProperty("user.dir")
			+ File.separatorChar + "data";

	public static void main(String[] args) {
		CSVReader reader = null;
		Student[] students = null;
		String path = Paths.get(currenDir, fileName).toString();

		// read data from a file "students.csv"
		try {

			reader = new CSVReader(new FileReader(path));
			System.out.println("File \"" + path + " \"  have been reading ");

			// 1) read all lines from a file
			List<String[]> list = reader.readAll();

			if (!list.isEmpty()) {
				int numLines = list.size();
				System.out.println("File contains " + numLines + "  lines");

				// 2) create the array of students and check data from the file
				students = createArrayOfStudents(list);

			} else {
				System.out.println("Error: file  " + path + "   is empty");
			}

			reader.close();

		} catch (FileNotFoundException e) {
			System.out.println("Error: file  " + path + "   not found");
		} catch (IOException e) {
			System.err.println("Error:read file " + path + "   error");
		} catch (SecurityException e) {
			System.err.println(e.getMessage());
		}

		// 3) Output the array in a table view
		System.out.println("\nBefore sorting\n");
		printStudents(students);

		// 4) Sort the array of students
		sort(students);

		// 5) Output sorted array in a table view
		System.out.println("\nAfter sorting\n");
		printStudents(students);
	}

	/**
	 * Checks validity data in the specified list of string array, creates array
	 * and fill the array by object of class Student using only valid data
	 * 
	 * @param list
	 *            the list of array of strings
	 * @return array of students or empty array if all items in the list are not
	 *         valid
	 */
	public static Student[] createArrayOfStudents(List<String[]> list) {
		// number of students with valid data
		int numStudents = 0;

		// create empty array of students with the length = list.size()
		Student[] students = new Student[list.size()];

		// start reading and analyzing each line from this list
		for (Iterator<String[]> it = list.iterator(); it.hasNext();) {

			// line contains data about one student
			String[] line = it.next();

			students[numStudents] = new Student();

			// check correctness information about student and fill
			// fields of Student object
			numStudents += writeStudInfo(students[numStudents], line);
		}
		// check if all data in a file are valid
		if (numStudents != list.size()) {

			// if not, create new array with smaller length
			students = copyOf(students, numStudents);
		}
		return students;

	}

	/**
	 * Copies the specified array, the copy has the specified length. For all
	 * indices that are valid in both the original array and the copy, the two
	 * arrays will contain identical values. For any indices that are valid in
	 * the copy but not the original, the copy will contain null. Such indices
	 * will exist if and only if the specified length is greater than that of
	 * the original array.
	 * 
	 * @param students
	 *            the array of Student class objects to be copied
	 * @param numStudents
	 *            the length of the copy to be returned
	 * @return a copy of the original array, truncated or padded with null to
	 *         obtain the specified length
	 */
	private static Student[] copyOf(Student[] students, int numStudents) {
		// Create new array of students of size numStudents
		// Copy numStudents first elements from array students to the new array
		// Return new array
		Student[] copy = new Student[numStudents];
		for(int i = 0; i < numStudents; i++){
			copy[i] = new Student();
			copy[i].copyStudent(students[i]);
		}
		
		return copy;
	}

	/**
	 * Checks correctness the information about student in this line. If checks
	 * for all elements in this line are successful, fills fields of the object
	 * s and return 1.
	 * 
	 * @param s
	 *            the instance of Student with empty fields. If s is null,
	 *            return 0
	 * @param line
	 *            array of Strings represented data about student. If line is
	 *            null, return 0
	 * @return 1 if all data about student are correct, 0 - otherwise
	 */
	public static int writeStudInfo(Student s, String[] line) {

		// return 0 if number of string in a line don't equals to number of
		// fields of class Student
		if (line.length != s.getClass().getDeclaredFields().length) {
			System.err.println("Error: the line  \"" + Arrays.toString(line)
					+ "\" not completed");
			throw new Exception();
			return 0;

		}


		// for check each string in a line:
		// 1)invoking methods isValidXXX from class Student
		// Hint: before you pass string isValidXXX method, use String.trim to
		// omit leading and trailing whitespace
		
		// 2) if string contains valid information, set the field of student
		// Hint: use methods Integer.parseInt/Double.parseDouble to convert from
		// String to int/double

		// if string contains invalid information don't set field and
		// immediately return 0

		// if all fields in a line contains valid information return 1
		
		String nameStr = line[0].trim();
		String surnameStr = line[1].trim();
		String cityCodeStr = line[2].trim();
		String phoneStr = line[3].trim();
		if(s.isValidName(nameStr) && s.isValidSurname(surnameStr)
				&& s.isValidCityCode(cityCodeStr) && s.isValidPhone(phoneStr)){
			s.setCityCode(cityCodeStr);
			s.setPhone(phoneStr);
			s.setName(nameStr);
			s.setSurname(surnameStr);
		} else {
			return 0;
		}

		return 1;

	}

	/**
	 * Outputs the table output array of student in table form: each element is
	 * on a separate row. Each row begins with a field by which sorting was
	 * performed Table should have a header with field's names.
	 * 
	 * @param studs
	 *            array of students to be output
	 */
	public static void printStudents(Student[] studs) {
		// check is the studs is null reference
		// check if the length of array is 0
		// output array of students invoking method print from class Student
		if(studs == null || studs.length == 0){
			System.out.println("Error: empty list");
		} else{
			System.out.println("----------------------------------------------");
			System.out.println("name      |surname     |city_code|    phone  |");
			System.out.println("----------------------------------------------");
			for (Student stud : studs) {
				stud.print();
			}
			System.out.println("----------------------------------------------");
		}
	}

	/**
	 * Sorts the specified array of objects into order specified in the variant.
	 * To compare two elements method compare must be invoked.
	 * 
	 * @param studs
	 *            the array to be sorted
	 */
	public static void sort(Student[] studs) {
		if(studs != null && studs.length != 0){
			int h = 1;
			while (h < studs.length / 3) {
				h = h * 3 + 1;
			}
			while (h > 0) {
				for (int i = h; i < studs.length; i++) {
					Student temp = studs[i];
					int j = i;
					while (j > h - 1 && compare(studs[j - h], temp) != -1) {
						studs[j] = studs[j - h];
						j -= h;
					}
					studs[j] = temp;
				}
				h = h / 3;
			}

		}
	}

	/**
	 * Compares its two cityCode for order. Returns a -1, 0, or 1 as the first
	 * argument is less than, equal to, or greater than the second.
	 *
	 * @param s1
	 *            the first object of class Student to be compared
	 * @param s2
	 *            the second object of class Student to be compared
	 * @return -1, 0, or 1 as the first argument is less than, equal to, or
	 *         greater than the second
	 */
	private static int compare(Student s1, Student s2) {
		if(Integer.parseInt(s1.cityCode) < Integer.parseInt(s2.cityCode)){
			return - 1;
		} else if (Integer.parseInt(s1.cityCode) == Integer.parseInt(s2.cityCode)){
			return 0;
		} else {
			return 1;
		}
	}
}
