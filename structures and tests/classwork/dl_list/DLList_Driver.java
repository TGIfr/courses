package dl_list;

public class DLList_Driver {

	public static void main(String[] args) {
		DLNode head = null; // head of the double-linked list
		String[] values = { "green", "blue", "gray" };

		// try to remove from empty list
		head = removeFirst(head);
		head = remove(head, "brown");

		head = addLast(head, "brown");
		for (String s : values) {
			head = addFirst(head, s);
		}
		printList(head); // gray blue green brown

		DLNode searchNode = search(head, "blue");
		if (searchNode != null) {
			System.out.println("Search node is \"" + searchNode.data + "\"");
		} else {
			System.out.println("Unsuccefull search");
		}

		addAfter(head, "blue", "white");
		printList(head); // gray blue white green brown

		addAfter(head, "green", "red");
		printList(head); // gray blue white green red brown

		addAfter(head, "yellow", "brown");
		printList(head); // gray blue white green red brown

		head = addLast(head, "yellow");
		printList(head); // gray blue white green red brown yellow

		head = remove(head, "white");
		printList(head);// gray blue green red brown yellow

		head = removeFirst(head);
		printList(head); // blue green red brown yellow

		head = remove(head, "blue");
		printList(head); // green red brown yellow

		head = removeLast(head);
		printList(head); // green red brown

		head = remove(head, "brown");
		printList(head); // green red
	}

	/**
	 * Returns the node as the first occurrence of the specified element in this
	 * list,if it is present
	 * 
	 * @param head
	 *            head of the double-linked list
	 * @param string
	 *            the element to search for
	 * @return node to search if it is present or null if it isn't
	 */
	public static DLNode search(DLNode head, String string) {
		DLNode x = head;
		while (x != null && x.data.equals(string) == false) {
			x = x.next;
		}
		return x;
	}

	/**
	 * Inserts the specified element at the beginning of this list.
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param value
	 *            the element to add
	 * @return new head head of the double-linked list
	 */
	public static DLNode addFirst(DLNode h, String value) {
		DLNode newNode = new DLNode();
		newNode.data = value;
		newNode.prev = null;
		newNode.next = h;
		if (h != null) {
			h.prev = newNode;
		}
		return newNode;
	}

	/**
	 * Appends the specified element to the end of this list.
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param value
	 *            the element to add
	 * @return head of the double-linked list
	 */
	public static DLNode addLast(DLNode h, String value) {
		if (h == null) {
			h = addFirst(h, value);
		} else {
			DLNode tail = h;
			while (tail.next != null) {
				tail = tail.next;
			}
			DLNode newNode = new DLNode();
			newNode.data = value;
			addAfter(tail, newNode);
		}
		return h;
	}

	/**
	 * Inserts the specified element after the given element of the list if it
	 * presents in the list. If this list does not contain the element, it is
	 * unchanged
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param key
	 *            the element to add new node after
	 * @param value
	 *            the element to add
	 */
	private static void addAfter(DLNode h, String key, String value) {
		DLNode y = search(h, key);
		if (y != null) {
			DLNode x = new DLNode();
			x.data = value;
			x.next = null;
			x.prev = null;
			addAfter(y, x);
		}
	}

	/**
	 * Inserts the newly created node after the specified node of the
	 * double-linked list
	 * 
	 * @param y
	 *            non-null node of the double-linked list after which new node
	 *            to be added
	 * @param x
	 *            non-null node to be add
	 */
	private static void addAfter(DLNode y, DLNode x) {
		x.next = y.next;
		x.prev = y;

		if (y.next != null) {
			y.next.prev = x;
		}
		y.next = x;
	}

	/**
	 * Removes the specified node from this list
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param x
	 *            node to be removed
	 * @return head head of the double-linked list
	 */
	private static DLNode remove(DLNode h, DLNode x) {
		// check if x is the head
		if (x.prev != null) {
			x.prev.next = x.next;
		} else {
			h = h.next;
		}
		// check if x is the tail
		if (x.next != null) {
			x.next.prev = x.prev;
		}
		return h;
	}

	/**
	 * Removes the first element from this list
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @return new head of the double-linked list
	 */
	public static DLNode removeFirst(DLNode h) {
		if (h != null) {
			return remove(h, h);
		} else {
			return h;
		}

	}

	/**
	 * Removes the last element from this list
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @return head of the double-linked list
	 */
	public static DLNode removeLast(DLNode h) {
		DLNode tail = h;
		while (tail.next != null) {
			tail = tail.next;
		}
		return remove(h, tail);
	}

	/**
	 * Removes the first occurrence of the specified element from this list, if
	 * it is present. If this list does not contain the element, it is unchanged
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param toRemove
	 *            element to be removed from this list, if present
	 * @return head of the double-linked list
	 */
	public static DLNode remove(DLNode h, String toRemove) {
		DLNode x = search(h, toRemove);

		// remove element if present
		if (x != null) {
			h = remove(h, x);
		}
		return h;
	}

	/**
	 * Output the list
	 * 
	 * @param h
	 *            head of the double-linked list
	 */
	public static void printList(DLNode h) {
		System.out.println("My list: ");
		if (h == null) {
			System.out.println("The list is empty!");
		} else {
			DLNode cur = h;
			while (cur != null) {
				cur.print();
				cur = cur.next;
			}
			System.out.println(System.lineSeparator());
		}
	}
}
