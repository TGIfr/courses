package sl_list;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (1)
 * 
 * @author Olena Khomenko
 * @version 2016-11-04
 * 
 *          Node in a single-linked list.
 *
 */
public class SLNode {
	String data; // each node keeps the string data
	SLNode next; // reference to the next node

	/**
	 * output data from the node
	 */
	void print() {
		System.out.printf("%s ", data);
	}
}
