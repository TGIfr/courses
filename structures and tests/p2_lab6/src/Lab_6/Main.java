package Lab_6;

import Lab_6.min_priority_queue.HeapPriorityQueue;
import Lab_6.min_priority_queue.UnsortedArrayPriorityQueue;

import java.io.File;
import java.util.Arrays;
import java.util.List;

public class Main {
	static final int N = 10;

	private static String fileName = "students2.csv";

	// path to the current directory that contains directory "data"
	private static String currenDir = System.getProperty("user.dir")
			+ File.separatorChar + "data";

	public static void main(String[] args) {
		StudentReader reader = new StudentReader(fileName, currenDir);

		List<Student> studs = reader.read();
		// create priority queue based on linear data structure
		// For example,

		MinPriorityQueue pq1 = new UnsortedArrayPriorityQueue(new StudentComparator());

		// create priority queue based on linear data structure
		// For example,
		MinPriorityQueue pq2 = new HeapPriorityQueue(new StudentComparator());

		for( Student st : studs){
			pq1.insert(st);
			pq2.insert(st);
		}

		// fill pq1 and pq2

		Student[] s1 = new Student[N];
		for(int i = 0; i < N; i ++){
			s1[i] = pq1.removeMin();
		}
		outputStudents(s1);


		Student[] s2 = new Student[N];
		for(int i = 0; i < N; i ++){
			s2[i] = pq2.removeMin();
		}
		outputStudents(s2);

		if (equals(s1, s2)) {
			System.out.println("Work is done!");
		}

	}

	private static void outputStudents(Student[] s1) {
		for (Student student : s1) {
			System.out.println(student);
		}
		System.out.println();
	}

	private static boolean equals(Student[] s1, Student[] s2) {
		if(s1 == null || s2 == null || s1.length != s2.length)
			return false;
//		Arrays.sort(s1);
//		Arrays.sort(s2);
//
//
//		outputStudents(s1);
//		outputStudents(s2);
//		for (int i = 0; i < s1.length; i ++) {
//			if(!s1[i].equals(s2[i]))
//				return false;
//		}
		StudentComparator c = new StudentComparator();
		for(int i = 0; i < s1.length; i++){
			if(c.compare(s1[i], s2[i]) != 0)
				return false;
		}
//		boolean [] found = new boolean [s1.length];
//		for(int i = 0; i < s2.length; i ++){
//			for(int j = 0; j < s1.length; j++){
//				if(s1[i].equals(s2[j])){
//					found[j] = true;
//					break;
//				}
//			}
//		}
//		for(int i = 0; i < s1.length; i++){
//			if(!found[i]) return false;
//		}

		return true;
	}

}
