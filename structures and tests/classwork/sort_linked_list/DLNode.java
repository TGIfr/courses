package sort_linked_list;

/**
 * KPI- FPM - PZKS <br>
 * Course: Algorithms and Data Structures (1)
 *
 * @author Olena Khomenko
 * @version 2016-12-11
 * 
 *          This class represents node in a double-linked list.
 *
 */
public class DLNode {
	int data; // each node keeps the integer data
	DLNode next; // reference to the next node
	DLNode prev; // reference to the previous node

	/**
	 * output data from the node
	 */
	void print() {
		System.out.printf("%d ", data);
	}

	/**
	 * sets to null links to the next and previous nodes
	 */
	void clearLinks() {
		this.next = null;
		this.prev = null;
	}
}
