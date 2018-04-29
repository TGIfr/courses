package lab5;

import java.io.File;
import java.util.List;

public class Task1Main {
	// name of file which stores data about students
	private static String fileName = "students.csv";

	// path to the current directory that contains directory "data"
	private static String currenDir = System.getProperty("user.dir")
			+ File.separatorChar + "data";

	public static void main(String[] args) {
		// create object of class StudentReader and invoke method read
		StudentReader reader = new StudentReader(fileName, currenDir);

		List<Student> studs = reader.read();
		StudentDictionary<Student> dict = new BSTree<>();

		// TEST dict.put
		// fill dictionary:insert students to the dictionary
		Student stud0 = studs.get(0);
		Student stud1 = studs.get(1);
		Student stud4 = studs.get(4);

		assert dict.size() == 0;
		assert dict.isEmpty();

		dict.put(stud0.getkey(), stud0);
		dict.put(stud1.getkey(), stud1);

		assert dict.size() == 2;
		assert !dict.isEmpty();

		dict.put(stud4.getkey(), stud4);
		assert dict.size() == 3;
		assert !dict.isEmpty();

		// TEST dict.print dictionary
		// output the content of a dictionary
		dict.printDictionary();

		// TEST dict.put
		// insert students with non-unique key
		Student stud7 = studs.get(7);
		Student studReturned = dict.put(stud7.getkey(), stud7);

		assert dict.size() == 3;
		assert !dict.isEmpty();
		assert studReturned.equals(stud0);
		System.out.println(" add non unique\n\n");
		dict.printDictionary();

		// TEST: dict.contains
		assert dict.containsKey(stud7.getkey());
		assert dict.containsKey(stud0.getkey());
		assert dict.containsKey(stud1.getkey());
		assert dict.containsKey(stud4.getkey());
		assert !dict.containsKey(1615);


		// TEST: dict.get

		studReturned = dict.get(stud1.getkey());
		assert studReturned.equals(stud1);
		assert dict.size() == 3;
		assert !dict.isEmpty();

		studReturned = dict.get(1000);
		assert studReturned == null;
		assert dict.size() == 3;
		assert !dict.isEmpty();

		// TEST: dict.remove
		for( Student st : studs){
			dict.put(st.getkey(), st);
		}
		System.out.println("add all\n\n");
		dict.printDictionary();

		studReturned = dict.remove(1000);
		assert studReturned == null;

		//leaf
		studReturned = dict.remove(6296);
		assert studReturned.equals(studs.get(5));
		assert dict.size() == 6;
		assert !dict.isEmpty();
		System.out.println(" remove 6296\n\n");
		dict.printDictionary();

		//mid
		studReturned = dict.remove(4298);
		assert studReturned.equals(stud1);
		assert dict.size() == 5;
		assert !dict.isEmpty();
		System.out.println(" remove 4298\n\n");
		dict.printDictionary();

		//root
		studReturned = dict.remove(4256);
		assert studReturned.equals(stud7);
		assert dict.size() == 4;
		assert !dict.isEmpty();
		System.out.println(" remove 4256\n\n");
		dict.printDictionary();

		//leftMost par is to delete
		//root
		studReturned = dict.remove(5256);
		assert studReturned.equals(studs.get(3));
		assert dict.size() == 3;
		assert !dict.isEmpty();
		System.out.println(" remove 5256\n\n");
		dict.printDictionary();


	}

}
