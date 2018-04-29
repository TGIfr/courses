package sort_linked_list;

import java.util.Random;

/**
 * KPI- FPM - PZKS <br>
 * Course: Algorithms and Data Structures (1) <br>
 * Lecture "Sorting of Linked Lists"
 * 
 * @author Olena Khomenko
 * @version 2016-12-11
 * 
 *          This programs demonstrate how to implement sorting algorithms to
 *          sort double-linked list. There are three algorithms are used: <br>
 *          1) selection sort<br>
 *          2) insertion sort <br>
 *          3) pointer sort
 *
 */
public class Sorter {

	public static void main(String[] args) {

		int[] numbers = new int[15];

		Random r = new Random();
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = r.nextInt(50);
		}
		// create three linked lists from the same array
		DLNode headS = createListFromArray(numbers);
		DLNode headI = createListFromArray(numbers);
		DLNode headP = createListFromArray(numbers);

		// sort headS list with selection sort
		System.out.println("List before sorting:");
		DLListOperations.printList(headS);
		headS = selectionSort(headS);
		System.out.println("List after selection sort:");
		DLListOperations.printList(headS);

		// sort headI list with insertion sort
		System.out.println("List before sorting:");
		DLListOperations.printList(headI);
		System.out.println("List after insertion sort:");
		headI = insertionSort(headI);
		DLListOperations.printList(headI);

		// sort headI list with pointer sort
		System.out.println("List before sorting:");
		DLListOperations.printList(headP);
		System.out.println("List after pointer sort:");
		headP = pointerSort(headP);
		DLListOperations.printList(headP);

	}

	/**
	 * construct a new double-linked list containing the elements of the array
	 * 
	 * @param a
	 *            array of integer values
	 * @return head of the double-linked list
	 */
	private static DLNode createListFromArray(int[] a) {
		DLNode h = null;
		// traverse thought array, take a value of each element, create a node
		// this value, and insert node to the end of linked list
		for (int n : a)
			h = DLListOperations.addLast(h, n);
		return h;
	}

	/**
	 * sort the double-linked list using selection sort
	 * 
	 * @param h
	 *            head of unsorted double-linked list
	 * @return head of sorted double-linked list
	 */
	private static DLNode selectionSort(DLNode h) {

		DLNode s = null; // head of sorted list

		while (h != null) {
			// find the node with maximum value in the unsorted list
			DLNode max = DLListOperations.maxNode(h);
			// remove the node with maximum value from unsorted list
			h = DLListOperations.remove(h, max);
			// insert the node with maximum value at the front of sorted list
			s = DLListOperations.addFirst(s, max);
		}
		return s;
	}

	/**
	 * sort the double-linked list using insertion sort
	 * 
	 * @param h
	 *            head of unsorted double-linked list
	 * @return head of sorted double-linked list
	 */
	private static DLNode insertionSort(DLNode h) {

		if (h == null) {
			return null;
		}

		// Make the first node the head of the sorted list.
		DLNode sortedList = h;
		h = h.next;
		sortedList.clearLinks();

		// Traverse the given linked list and insert every
		// node to sorted list
		while (h != null) {
			DLNode insertedEl = h;
			h = h.next;
			insertedEl.clearLinks();
			sortedList = insertToSortedList(sortedList, insertedEl);
		}
		return sortedList;
	}

	/**
	 * insert a given node in sorted double-linked list to the correct position
	 * 
	 * @param h
	 *            head of sorted double-linked list
	 * @param n
	 *            node to be inserted
	 * @return head of sorted double-linked list with new node
	 */
	private static DLNode insertToSortedList(DLNode h, DLNode n) {
		if (h == null) {
			return n;
		}
		// Special case if node should be inserted at the beginning of the list
		if (n.data < h.data) {
			return DLListOperations.addFirst(h, n);
		}
		// Search list for correct position of n node.
		DLNode search = h;
		while (search.next != null && n.data > search.next.data) {
			search = search.next;
		}
		// n node goes after search.
		DLListOperations.addAfter(search, n);

		return h;

	}

	/**
	 * sort the double-linked list using auxiliary array which keeps nodes of
	 * unsorted list. Then array is sorted with insertion sort algorithm
	 * comparing data in the elements of array.
	 * 
	 * @param h
	 *            head of unsorted double-linked list
	 * @return head of sorted double-linked list
	 */
	private static DLNode pointerSort(DLNode h) {
		// create an array of links
		DLNode[] a = new DLNode[DLListOperations.size(h)];
		// copy nodes from list to an array
		for (int i = 0; i < a.length; i++, h = h.next) {
			a[i] = h;
		}
		// sort an array of links
		insertionSort(a);
		// create a list from array
		h = null;
		for (DLNode n : a) {
			h = DLListOperations.addLast(h, n.data);
		}
		return h;

	}

	/**
	 * sort an array of links (nodes) comparing data by links
	 * 
	 * @param ar
	 *            unsorted array of links
	 */
	private static void insertionSort(DLNode[] ar) {
		int N = ar.length;
		for (int i = 1; i < N; i++) {
			int j = i - 1;
			DLNode key = ar[i];
			while (j >= 0 && ar[j].data > key.data) {
				ar[j + 1] = ar[j];
				j--;
			}
			ar[j + 1] = key;
		}
	}
}
