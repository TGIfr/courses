package lab5;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 5
 * 
 * @author Olena Khomenko <br>
 * 
 *         Interface StudentMap maps key (student's card number) to the
 *         information about student. <br>
 *         StudentDictionary cannot contain duplicate key.
 *
 * @param <E>
 */
public interface StudentDictionary<E extends Student> {

	/**
	 * @param cardNumber
	 * @return true if this StudentDictionary contains a mapping for the
	 *         specified cardNumber
	 */
	boolean containsKey(int cardNumber);

	/**
	 * @return the number of key-value mappings in this StudentDictionary
	 */
	int size();

	/**
	 * Returns true if this dictionary contains no key-value mappings
	 * 
	 * @return true if this dictionary contains no key-value mappings
	 */
	boolean isEmpty();

	void printTreeLevel(int LevelNumber);

	void printTree();
	/**
	 * Associates the specified student with the specified cardNumber in this
	 * dictionary. If the dictionary previously contained a mapping for the
	 * cardNumber, the old student is replaced by the specified student.
	 * 
	 * @param num
	 *            cardNumber with which the specified student is to be
	 *            associated
	 * @param e
	 *            student to be associated with the specified cardNumber
	 * @return the previous student associated with cardNumber, or null if there
	 *         was no mapping for key
	 */
	E put(int num, E e);

	/**
	 * Returns the student to which the specified cardNumber is mapped, or null
	 * if this dictionary contains no mapping for the cardNumber
	 * 
	 * @param num
	 *            the cardNumber whose associated student is to be returned
	 * @return the student to which the specified num is mapped, or null if this
	 *         dictionary contains no mapping for the num
	 */
	E get(int num);

	/**
	 * Removes the mapping for a num from this dictionary if it is present
	 * 
	 * @param num
	 *            cardNumber whose mapping is to be removed from the dictionary
	 * @return previous student associated with cardNumber, or null if there was
	 *         no mapping for cardNumber
	 */
	E remove(int num);

	/**
	 * Remove from a tree all students that satisfy specified criteria
	 *
	 * @return number of students was be removed
	 */
	public int removeByVariant();

	/**
	 * Outputs the dictionary in table form according to given way of traversal
	 */
	void printDictionary();

}
