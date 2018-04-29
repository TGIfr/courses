package dl_list;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (1)
 *
 * @author Olena Khomenko
 * @version 2016-11-04
 * 
 *          Node in a double-linked list.
 *
 */
public class DLNode {
	String data; // each node keeps the string data
	DLNode next; // reference to the next node
	DLNode prev; // reference to the previous node

	/**
	 * output data from the node
	 */
	void print() {
		System.out.printf("%s ", data);
	}
}
