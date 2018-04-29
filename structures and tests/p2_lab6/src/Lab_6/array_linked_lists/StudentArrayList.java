package Lab_6.array_linked_lists;
import Lab_6.Student;

import java.util.Arrays;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 6
 * 
 * @author Olena Khomenko <br>
 * 
 *         Resizable-array. Implements List interface <br>
 *         This class skeleton contains methods with  <br>
 *         Implement methods with  and write addition methods to support
 *         class functionality.
 * 
 *         Methods isEmpty, get, set operations run in constant time. <br>
 *         The add operation runs in amortized constant time. <br>
 *         All of the other operations run in linear time (roughly speaking).
 */

public class StudentArrayList implements StudentList {
	// The array buffer into which the elements of the ArrayList are stored. The
	// capacity of the ArrayList is the length of this array buffer

	private Student[] list;

	// Default initial capacity
	private final int defaultCapacity = 10;

	// the size of the array used to store the elements in the list
	private int capacity;

	// The size of the ArrayList (the number of elements it contains)
	private int size;

	/**
	 * Constructs an empty list with an initial capacity of ten
	 * 
	 */
	public StudentArrayList() {
		this.capacity = defaultCapacity;
		list = new Student[capacity];

	}

	/**
	 * Constructs an empty list with the specified initial capacity
	 * 
	 * @param initialCapacity
	 *            the initial capacity of the list
	 */
	public StudentArrayList(int initialCapacity) {
		this.capacity = initialCapacity;
		list = new Student[capacity];
	}

	@Override
	public boolean add(Student element) {
		ensureCapacity(size + 1);
		list[size++] = element;
		return true;
	}

	@Override
	public boolean add(int index, Student e) {

		if (index > size || index < 0)
		return false;

		ensureCapacity(size+1);
		System.arraycopy(list, index, list, index + 1, size - index);
		list[index] = e;
		size++;
		return true;
	}

	@Override
	public Student remove(int index) {
		if(!rangeCheck(index)) return null;
		Student oldValue = list[index];
		int numMoved = size - index - 1;
		if (numMoved > 0)
			System.arraycopy(list, index+1, list, index, numMoved);
		list[--size] = null;

		return oldValue;
	}

	@Override
	public boolean remove(Student element) {
		if (element == null) return false;

		for (int index = 0; index < size; index++) {
			if (element.equals(list[index])) {
				remove(index);
				return true;
			}
		}
		return false;
	}


	@Override
	public Student get(int index) {
		if(!rangeCheck(index)) return null;

        return list[index];
	}

	@Override
	public Student set(int index, Student element) {
		if(!rangeCheck(index)) return null;
		Student oldValue = list[index];
		list[index] = element;
		return oldValue;
	}

	private boolean rangeCheck(int index) {
		if (index >= size || index < 0)
			return false;
		else return true;

	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public boolean isEmpty() {
		return size == 0;
	}

	private void ensureCapacity(int minCapacity) {
		int oldCapacity = list.length;
		if (minCapacity > oldCapacity) {
			Student oldData[] = list;
			int newCapacity = (oldCapacity * 3)/2 + 1;
			if (newCapacity < minCapacity)
				newCapacity = minCapacity;
			// minCapacity is usually close to size, so this is a win:
			list = Arrays.copyOf(list, newCapacity);
		}
	}
}
