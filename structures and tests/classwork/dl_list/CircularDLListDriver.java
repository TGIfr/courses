package dl_list;

public class CircularDLListDriver {

	public static void main(String[] args) {
		DLNode nil = new DLNode();
		nil.data = "";
		nil.next = nil;
		nil.prev = nil;

		// output empty list
		printList(nil);

		// try to remove from empty list
		delete(nil, "brown");

		// try to search in the empty list
		DLNode searchNode = search(nil, "blue");
		System.out.println("Search node = " + searchNode.data);

		String[] values = { "green", "blue", "gray" };
		for (String s : values) {
			insert(nil, s);
		}
		printList(nil); // gray blue green

		searchNode = search(nil, "green");
		System.out.println("Search node = " + searchNode.data);

		searchNode = search(nil, "white");
		System.out.println("Search node = " + searchNode.data);

		delete(nil, "green");
		printList(nil); // gray blue

		delete(nil, "blue");
		printList(nil); // gray

		delete(nil, "gray");
		printList(nil);

		searchNode = search(nil, "green");
		System.out.println("Search node = " + searchNode.data);

	}

	/**
	 * Returns the node as the first occurrence of the specified element in this
	 * list,if it is present
	 * 
	 * @param nil
	 *            sentinel node of the circular list
	 * @param string
	 *            the element to search for
	 * @return node to search if it is present or null if it isn't
	 */
	private static DLNode search(DLNode nil, String string) {
		DLNode x = nil.next;
		while (x != nil && x.data.equals(string) == false) {
			x = x.next;
		}
		return x;
	}

	/**
	 * Removes the first occurrence of the specified element from this list, if
	 * it is present. Returns true if this list contained the specified element
	 * (or equivalently, if this list changed as a result of the call)
	 * 
	 * @param nil
	 *            sentinel node of the circular list
	 * @param string
	 *            element to be removed from this list, if present
	 * @return true if this list contained the specified element
	 */
	public static boolean delete(DLNode nil, String string) {
		DLNode x = search(nil, string);
		if (x != nil) {
			x.prev.next = x.next;
			x.next.prev = x.prev;
			return true;
		}
		return false;
	}

	/**
	 * Inserts the specified element at the beginning of this list
	 * 
	 * @param nil
	 *            sentinel node of the circular list
	 * @param value
	 *            the element to add
	 */
	public static void insert(DLNode nil, String value) {
		DLNode newNode = new DLNode();
		newNode.data = value;
		newNode.prev = null;
		newNode.next = null;
		insert(nil, newNode);
	}

	/**
	 * Inserts the specified node at the beginning of this list
	 * 
	 * @param nil
	 *            sentinel node of the circular list
	 * @param x
	 *            the node to add
	 */
	private static void insert(DLNode nil, DLNode x) {
		x.next = nil.next;
		nil.next.prev = x;
		nil.next = x;
		x.prev = nil;
	}

	/**
	 * outputs the list
	 * 
	 * @param nil
	 *            sentinel node of the circular list
	 */
	public static void printList(DLNode nil) {
		System.out.println("My list: ");
		if (nil.next == nil && nil.prev == nil) {
			System.out.println("The list is empty!");
		} else {
			DLNode cur = nil.next;
			while (cur != nil) {
				cur.print();
				cur = cur.next;
			}
			System.out.println(System.lineSeparator());
		}
	}

}
