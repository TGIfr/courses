package sl_list;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (1)
 * 
 * @author Olena Khomenko
 * @version 2016-11-04
 * 
 */
public class SLListDriver {

	public static void main(String[] args) {
		SLNode head = null; // head (the first node) of the list

		// print empty list
		printList(head);

		// add to the empty list one element and remove it
		head = addAfter(head, "black", "orange"); // empty
		head = addLast(head, "blue"); // "blue"
		head = addAfter(head, "blue", "yellow"); // "blue" -> "yellow"
		head = removeFirst(head); // "yellow"
		printList(head);

		head = addFirst(head, "black"); // "black" -> "yellow"
		head = addFirst(head, "white");// "white"-> "black" -> "yellow"
		head = addLast(head, "blue"); // "white"-> "black" -> "yellow" -> "blue"
		printList(head);

		head = addLast(head, "orange");
		// "white"-> "black" -> "yellow" -> "blue" -> "orange"
		printList(head);

		head = addAfter(head, "red", "green");
		head = addAfter(head, "black", "green");
		// "white"-> "black" -> "green" -> "yellow" -> "blue" -> "orange"
		printList(head);

		// output list
		head = removeFirst(head);
		// "black" -> "green" -> "yellow" -> "blue" -> "orange"
		head = remove(head, "orange");
		// "black" -> "green" -> "yellow" -> "blue"
		head = remove(head, "white"); // not found "white"
		head = remove(head, "yellow");
		// "black" -> "green" -> "blue"
		printList(head);

		head = removeFirst(head);
		// "green" -> "blue"
		head = remove(head, "green");
		// "green" -> "blue"
		printList(head);
		// "blue"
	}

	/**
	 * Inserts the specified element at the beginning of this list.
	 * 
	 * @param h
	 *            head of the list
	 * @param value
	 *            the element to add
	 * @return head of the list
	 */
	public static SLNode addFirst(SLNode h, String value) {
		// create new Node
		SLNode newNode = new SLNode();
		newNode.data = value;

		// new node refers to the head
		newNode.next = h;
		return newNode; // returns new head
	}

	/**
	 * Appends the specified element to the end of this list.
	 * 
	 * @param h
	 *            head of the list
	 * @param value
	 *            the element to add
	 * @return head of the list
	 */
	public static SLNode addLast(SLNode h, String value) {
		// create new Node and fill all fields
		SLNode newNode = new SLNode();
		newNode.data = value;
		newNode.next = null;

		if (h == null) {
			h = newNode;
		} else {

			// search the tail of list
			SLNode cur = h;
			while (cur.next != null) {
				cur = cur.next;
			}
			// newNode follows after cur (cur.next = null)
			cur.next = newNode;
		}
		return h;
	}

	/**
	 * Inserts the specified element after the given element of the list
	 * 
	 * @param h
	 *            head of the list
	 * @param key
	 *            the element to add new node after
	 * @param value
	 *            the element to add
	 * @return head of the list
	 */
	public static SLNode addAfter(SLNode h, String key, String value) {
		if (h != null) {

			// search the node with key
			SLNode cur = h;
			while (cur != null && cur.data.equals(key) == false) {
				cur = cur.next;
			}

			// if the node with key was found
			if (cur != null) {
				SLNode newNode = new SLNode();
				newNode.data = value;
				addAfter(cur, newNode);
			}
		}
		return h;
	}

	/**
	 * Inserts the newly created node after the specified node of the list
	 * 
	 * @param x
	 *            non-null node of the list
	 * @param y
	 *            non-null node to be add
	 */
	private static void addAfter(SLNode x, SLNode y) {
		y.next = x.next;
		x.next = y;
	}

	/**
	 * Removes the first element from this list
	 * 
	 * @param h
	 *            head of the list
	 * @return new head of the list
	 */
	public static SLNode removeFirst(SLNode h) {
		if (h != null) {
			h = h.next;
		}
		return h;
	}

	/**
	 * Removes the first occurrence of the specified element from this list, if
	 * it is present. If this list does not contain the element, it is unchanged
	 * 
	 * @param h
	 *            head of the list
	 * @param key
	 *            element to be removed from this list, if present
	 * @return head of the list
	 */
	public static SLNode remove(SLNode h, String key) {
		if (h != null) {
			// del - the node with key; must be deleted
			SLNode del = h;
			// prev - the node before node to be deleted
			SLNode prev = null;

			// search the node with key
			while (del != null && del.data.equals(key) == false) {
				prev = del;
				del = del.next;
			}
			// if the node with key was found
			if (del != null) {
				if (prev == null) {
					h = removeFirst(h);
				} else {
					removeAfter(prev);
				}
			}
		}
		return h;
	}

	/**
	 * Removes node after the specified node
	 * 
	 * @param x
	 *            non-null node after which is the node to be removed
	 * @return the node that was removed from the list.
	 */
	private static void removeAfter(SLNode x) {
		SLNode del = x.next;
		x.next = del.next;
	}

	/**
	 * outputs the list
	 * 
	 * @param h
	 *            head of the list
	 */
	public static void printList(SLNode h) {
		System.out.println("My list: ");
		if (h == null) {
			System.out.println("The list is empty!");
		} else {
			SLNode cur = h;
			while (cur != null) {
				cur.print();
				cur = cur.next;
			}

		}
		System.out.println(System.lineSeparator());
	}
}
