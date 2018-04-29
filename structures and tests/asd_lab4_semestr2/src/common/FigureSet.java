package common;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 4
 * 
 * @author Olena Khomenko <br>
 * 
 *         Interface Set collects geometric figures. It contains no duplicate
 *         elements. More formally, sets contain no pair of elements e1 and e2
 *         such that e1.equals(e2), and at most one null element. As implied by
 *         its name, this interface models the mathematical set abstraction.
 * 
 * */

public interface FigureSet {

	/**
	 * Adds the specified element to this set if it is not already present. If
	 * this set already contains the element, the call leaves the set unchanged
	 * and returns false
	 * 
	 * @param gf
	 *            figure to be added to this set
	 * @return true if this set did not already contain the specified element
	 */
	boolean add(GeomFigure gf);

	/**
	 * Returns true if this set contains the specified element
	 * 
	 * @param gf
	 *            element whose presence in this set is to be tested
	 * @return true if this set contains the specified element gf or gf == null
	 */
	boolean contains(GeomFigure gf);

	/**
	 * Returns true if this set contains no elements.
	 * 
	 * @return if this set contains no elements
	 */
	boolean isEmpty();

	/**
	 * Removes the specified element from this set if it is present
	 * 
	 * @param gf
	 *            element to be removed from this set, if present
	 * @return if this set contained the specified element
	 */
	boolean remove(GeomFigure gf);

	/**
	 * Output the content of set
	 */
	void print();

	/**
	 * Returns the size of set
	 * 
	 * @return the number of elements in the set
	 */
	int size();

}
