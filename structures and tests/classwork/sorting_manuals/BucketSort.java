package sorting_manuals;

import java.util.Arrays;

/* KPI- FPM - PZKS
 * Course: Algorithms and Data Structures (1)
 * @author Olena Khomenko
 * This is a program of generic bucket sort.
 * Bucket Sorting works as follows:
 * 1) Set up an array of initially empty "buckets"
 * 2) Go over the original array, putting each object in its bucket.  
 * 3) Sort each non-empty bucket.
 * 4) Visit the buckets in order and put all elements back into the original array
 */
public class BucketSort {
	private static int N = 20;

	public static void main(String[] args) {
		double[] arr = new double[N];
		// input doubles numbers are in the interval [0,1)
		ArrayAssistant.fillRandom(arr);

		// version1: bucket sort with sorting each bucket

		System.out.println("Bucket sort: version 1");
		double[] arr1 = Arrays.copyOf(arr, arr.length);
		ArrayAssistant.print(arr1, "Before sorting");

		int nBuckets = arr.length;

		// Step1: create an array of empty linked lists (buckets)
		DLNode[] buckets = new DLNode[nBuckets];
		for (int i = 0; i < buckets.length; i++) {
			buckets[i] = null;
		}

		// Step2: Distribute the n input numbers into the buckets
		for (int i = 0; i < arr1.length; i++) {
			int b = (int) (nBuckets * arr1[i]);
			DLNode newNode = new DLNode();
			newNode.data = arr1[i];
			buckets[b] = DLListOperations.addFirst(buckets[b], newNode);
		}

		// Step3: Sort each list B[i] individually by insertion sort
		for (int i = 0; i < buckets.length; i++) {
			buckets[i] = insertionSort(buckets[i]);
		}

		// Step4: Concatenate the lists B[0], B[1], . . B[n-1] together in order
		for (int i = 0, j = 0; i < buckets.length; i++) {
			while (buckets[i] != null) {
				arr1[j++] = buckets[i].data;
				buckets[i] = DLListOperations.removeFirst(buckets[i]);
			}
		}
		ArrayAssistant.print(arr1, "After sorting");

		System.out.println(System.lineSeparator());

		// version2: bucket sort with inserting number in each already sorted
		// bucket

		System.out.println("Bucket sort: version 2");
		double[] arr2 = Arrays.copyOf(arr, arr.length);
		ArrayAssistant.print(arr2, "Before sorting");

		// Step1: create an array of empty linked lists (buckets)
		buckets = new DLNode[nBuckets];
		for (int i = 0; i < buckets.length; i++) {
			buckets[i] = null;
		}

		// Step2: Distribute the n input numbers into the buckets.Insert each
		// number in a list keeping list sorted
		for (int i = 0; i < arr2.length; i++) {
			int b = (int) (nBuckets * arr2[i]);
			DLNode newNode = new DLNode();
			newNode.data = arr2[i];
			buckets[b] = insertToSortedList(buckets[b], newNode);
		}

		// Step3: Concatenate the lists B[0], B[1], . . B[n-1] together in order
		for (int i = 0, j = 0; i < buckets.length; i++) {
			while (buckets[i] != null) {
				arr2[j++] = buckets[i].data;
				buckets[i] = DLListOperations.removeFirst(buckets[i]);
			}
		}
		ArrayAssistant.print(arr2, "After sorting");

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
		DLNode node = h;
		h = h.next;
		node.clearLinks();
		DLNode sortedList = node;

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

}
