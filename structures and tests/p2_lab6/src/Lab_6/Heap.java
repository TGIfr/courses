package Lab_6;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 6
 * 
 * @author Olena Khomenko
 * 
 *         Interface represents a balanced binary heap. The heap is ordered by
 *         comparator: For each node n in the heap and each descendant d of n, n
 *         <= d. The element with the lowest value is in queue[1], assuming the
 *         queue is nonempty queue[0] is not used
 */

public interface Heap {

	/**
	 * Maintains heap invariant by promoting item at position i up the tree
	 * until it is greater (less) than or equal to its parent, or is the root.
	 * 
	 * @param index
	 *            the position of element
	 */
	void swim(int index);

	/**
	 * Maintains heap invariant by demoting item at position i down the tree
	 * repeatedly until it is less ( greater) than or equal to its children or
	 * is a leaf.
	 * 
	 * @param index
	 *            the position of element
	 */
	void sink(int index);

	/**
	 * Calculates the index of the parent of the item at index i
	 * 
	 * @param index
	 *            position of item
	 * @return the index of the parent
	 */
	int getParent(int index);

	/**
	 * Calculates the index of the left child of the item at index i
	 * 
	 * @param index
	 *            position of item
	 * @return the index of the left child
	 */
	int getLeft(int i);

	/**
	 * Calculates the index of the right child of the item at index i
	 * 
	 * @param index
	 *            position of item
	 * @return the index of the right child
	 */
	int getRight(int i);
}
