package Lab_6.min_priority_queue;

import Lab_6.MinPriorityQueue;
import Lab_6.Student;
import Lab_6.StudentComparator;
import Lab_6.array_linked_lists.StudentArrayList;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 6
 * 
 * @author Olena Khomenko
 * 
 *         Array implementation of min-priority queue. <br>
 *         Keeps elements of type Student.<br>
 *         Elements in list are not ordered. To find min-priority element in a
 *         priority queue compare priorities of elements.<br>
 *         Use StudentComparator to compare priorities of Students
 */
public class UnsortedArrayPriorityQueue implements MinPriorityQueue {

	private StudentArrayList array;
	private StudentComparator c;

	public UnsortedArrayPriorityQueue(StudentComparator c) {
		this.c = c;
		array = new StudentArrayList();
	}

	@Override
	public void insert(Student s) {
		array.add(s);
	}

	@Override
	public boolean isEmpty() {
		return array.isEmpty();
	}

	@Override
	public Student removeMin() {

		// finds, removes and returns from array the student with the smallest
		// priority
		// use StudentComparator to compare priorities of Students
		// returns null if this queue is empty

		int min = getMinIndex();

		return array.remove(min);
	}
	private int getMinIndex(){
		int index = 0;
		Student min = array.get(index);
		for (int i = 1; i < array.size(); ++i) {
			if (c.compare(min, array.get(i)) > 0) {
				index = i;
				min = array.get(index);
			}
		}
		return index;
	}
	@Override
	public Student min() {

		// finds, retrieves, but does not remove from list the student with the
		// smallest priority
		// use StudentComparator to compare priorities of Students
		// returns null if this queue is empty
		return array.get(getMinIndex());
	}

	@Override
	public int size() {
		return array.size();
	}

}
