package Lab_6;

import java.util.Comparator;

public class StudentComparator implements Comparator<Student> {

	@Override
	public int compare(Student s1, Student s2) {
		int compMark = Double.compare(s1.mark, s2.mark);
		if(compMark == 0)
			return Integer.compare(s1.course, s2.course);
		else return compMark;
	}

}
