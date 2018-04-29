public class DLListOperations {

	/**
	 * Finds in the double-linked list the node contained max value
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @return node with maximum value
	 */
	public static DLNode maxNode(DLNode h) {
		if (h == null)
			return h;
		else {
			DLNode max = h;
			DLNode cur = h;
			while (cur != null) {
				if (cur.data > max.data) {
					max = cur;
				}
				cur = cur.next;
			}
			return max;
		}
	}

	public static DLNode search(DLNode head, int key) {
		DLNode x = head;
		while (x != null && x.data == key) {
			x = x.next;
		}
		return x;
	}

	/**
	 * Inserts the specified element at the beginning of this list.
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param newNode
	 *            the node to add
	 * @return new head head of the double-linked list
	 */
	public static DLNode addFirst(DLNode h, DLNode newNode) {
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
	public static DLNode addLast(DLNode h, int value) {
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
	 * Inserts the specified element at the beginning of this list.
	 * 
	 * @param h
	 *            head of the double-linked list
	 * @param value
	 *            the element to add
	 * @return new head head of the double-linked list
	 */
	public static DLNode addFirst(DLNode h, int value) {
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
	private static void addAfter(DLNode h, int key, int value) {
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
	 * Inserts the given node x after the specified node of the double-linked
	 * list
	 * 
	 * @param y
	 *            non-null node of the double-linked list after which new node
	 *            to be added
	 * @param x
	 *            non-null node to be add
	 */
	public static void addAfter(DLNode y, DLNode x) {
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
	public static DLNode remove(DLNode h, DLNode x) {
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
	public static DLNode remove(DLNode h, int toRemove) {
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

class DLNode {
	double data; // each node keeps the string data
	DLNode next; // reference to the next node
	DLNode prev; // reference to the previous node

	/**
	 * output data from the node
	 */
	void print() {
		System.out.printf("%s ", data);
	}

	void clearLinks() {
		this.next = null;
		this.prev = null;
	}
}
