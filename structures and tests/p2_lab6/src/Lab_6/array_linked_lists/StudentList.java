package Lab_6.array_linked_lists;
import Lab_6.Student;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 6
 * 
 * @author Olena Khomenko <br>
 *         This interface provides the methods for positional (indexed) access
 *         to list elements.
 */
public interface StudentList {

	/**
	 * Appends the specified element to the end of this list
	 * 
	 * @param s
	 *            element to be appended to this list
	 * @return true if this list changed as a result of the call
	 */
	boolean add(Student e);

	/**
	 * Inserts the specified element at the specified position in this list
	 * 
	 * @param index
	 *            index at which the specified element is to be inserted
	 * @param e
	 *            element to be inserted
	 * @return true if this list changed as a result of the call
	 */
	boolean add(int index, Student s);

	/**
	 * Removes the element at the specified position in this list. If the list
	 * is empty, returns empty String
	 * 
	 * @param index
	 *            the index of the element to be removed
	 * @return the element previously at the specified position, or empty String
	 */
	Student remove(int index);

	/**
	 * Removes the first occurrence of the specified element from this list, if
	 * it is present
	 * 
	 * @param e
	 *            element to be removed from this list, if present
	 * @return true if this list contained the specified element
	 */
	boolean remove(Student e);

	/**
	 * Returns the element at the specified position in this list
	 * 
	 * @param index
	 *            index of the element to return
	 * @return
	 */
	Student get(int index);

	/**
	 * Replaces the element at the specified position in this list with the
	 * specified element
	 * 
	 * @param index
	 *            index of the element to replace
	 * @param e
	 *            element to be stored at the specified position
	 * @return the element at the specified position in this list
	 */
	Student set(int index, Student e);

	/**
	 * Returns the number of elements in this list
	 * 
	 * @return the number of elements in this list
	 */
	int size();

	/**
	 * Returns true if this list contains no elements
	 * 
	 * @return true if this list contains no elements
	 */
	boolean isEmpty();

}
