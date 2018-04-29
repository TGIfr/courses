package lab3;

import java.io.File;
/**
 * KPI- FPM - PZKS
 * Course: Algorithms and Data Structures (1)
 * Laboratory work 3
 * @author Olena Khomenko
 * This is a program skeleton for lab 3
 * Write your code in the places of the methods which are marked by TODO marker 
 * Write own methods that will be invoked from existing method 
 * 
 */

public class Main {
	private static String fileName = "input5.dat";
	private static String currenDir = System.getProperty("user.dir") + File.separatorChar + "data";

		public static void main(String[] args) {
			FileAssistant fa = new FileAssistant();

			fa.setFileName(currenDir, fileName);
			DLNode firstList = createDLNode(0);
			
			

			// Task 3.1: Create the first double-linked list

			if (fa.readFile()) {
				// Successful reading file

				System.out.println("Start reading a file: ");

				// read the first integer value from the text file
				int number = fa.readNextInt();

				while (number != FileAssistant.ERROR_CODE) {
					//Output integer from a file
					System.out.printf("%5d", number);

					//create new node of double-linked list
					DLNode node = createDLNode(number);
					
					//add new node to a double-linked list
					firstList = addNode(firstList, node);

					// read the next integer value from the text file
					number = fa.readNextInt();
				}
				
				System.out.println("\nStop reading a file: \n");

			} else {
				System.out.println("Error: file empty, or does't not found, or there are IO errors: \n");
			}

			System.out.println(System.lineSeparator());
			System.out.println("THE FIRST LIST:");
			System.out.printf("Size = %d\n", size(firstList));
			printList(firstList);

			// Task 3.2:Change the first double-linked list and create new single-linked list
			SLNode secondList = createSecondList(firstList);

			// print the second list
			System.out.println("THE SECOND LIST:");
			System.out.printf("Size = %d\n", size(secondList));
			printList(secondList);

			// check the content of the first list
			System.out.println("THE FIRST LIST:");
			System.out.printf("Size =   %d\n", size(firstList));
			printList(firstList);

		}
		
		/**
		 * creates new node of the single-linked list
		 * 
		 * @param data
		 *            integer number to be in the node
		 * @return new node
		 */
		private static SLNode createSLNode(int data) {
			SLNode newNode = new SLNode();
			newNode.data = data;
			newNode.next = null;
			return newNode;

		}

		/**
		 * creates new node of the double-linked list
		 * 
		 * @param data
		 *            integer number to be in the node
		 * @return new node
		 */
		private static DLNode createDLNode(int data) {
			DLNode newNode = new DLNode();
			newNode.data = data;
			newNode.next = null;
			newNode.prev = null;
			return newNode;

		}

		/**
		 * Adds new node to the double-linked list to the position defined in the
		 * variant. Head of list that passed as parameter can be differ from the
		 * head when it returns if the new node is inserted to the beginning of the
		 * list
		 * 
		 * @param head
		 *            the first node of the double-linked list
		 * @param node
		 *            new node to be added to the list
		 * @return head of double-linked list
		 */
		private static DLNode addNode(DLNode head, DLNode node) {
			
			// TODO
			// Add implementation
			// task 3.1
			// position where new node to be insert defines by the variant - the item (a)
			
			if(head.next == null){
				head.next = node;
				node.prev = head;
			} else { 
				node.next = head.next.next;
				node.prev = head.next;
				if(head.next.next != null){
					head.next.next.prev = node;
				}
				head.next.next = node;
			}
			return head;
		}
		
		
		/**
		 * adds new node to the single-linked list to the position defined in the
		 * variant. Head of list that passed as parameter can be differ from the
		 * head when it returns if the new node is inserted to the beginning of the
		 * list
		 * @param head 
		 * 			  the first node of the single-linked list
		 * 
		 * @param node 
		 * 			new node to be added to the list
		 * @return
		 * 			head of single-linked list
		 */
		private static SLNode addNode(SLNode head, SLNode node) {
			// TODO
			// Add implementation
			// task 3.2
			// position where new node to be insert defines by the variant - the item (c)
			if(head == null){
				head = node;
			} else {
				SLNode tail = head;
				while(tail.next != null){
					tail = tail.next;
				}
				tail.next = node;
			}
			return head;
		}
		
		/**
		 * prints values from nodes in the single-linked list if size of list equals
		 * 0, print message "The list is empty"
		 * 
		 * @param firstList
		 *            head of single-linked list
		 */
		private static void printList(SLNode list) {
			// TODO
			// Add implementation
			// if the list is empty, print a message
			// if the list is not empty, print all numbers one by one in the line   
			if (list == null) {
				System. out.println("\nThe list is empty!");
			} else {
				SLNode cur = list;
				while (cur != null) {
					System.out.print(cur.data + " ");
					cur = cur.next;
				}
			}
			System.out.println();
		}
		
		/**
		 * prints values from nodes in the double-linked list. If size of list equals
		 * 0, print message "The list is empty"
		 * 
		 * @param list
		 *            head of double-linked list
		 */

		private static void printList(DLNode list) {
			// TODO
			// Add implementation
			// if the list is empty, print a message
			// if the list is not empty, print all numbers one by one in the line   
			if (list == null) {
				System. out.println("\nThe list is empty!");
			} else {
				DLNode cur = list.next;
				while (cur != null) {
					System.out.print(cur.data + " ");
					cur = cur.next;
				}
			}
			System.out.println();
		}

		/**obtains the number of nodes in the list
		 * @param list
		 *            head of single-linked list
		 * @return number of nodes in the list or 0, if the list is empty
		 */
		private static int size(SLNode list) {
			// TODO
			// Add implementation
			int count = 0;
			SLNode cur = list;
			while (cur != null) {
				count++;
				cur = cur.next;
			}
			return count;
		}

		/**
		 * obtains the nodes of nodes in the list
		 * @param list
		 *            head of double-linked list
		 * @return number of nodes in the list or 0, if the list is empty
		 */
		private static int size(DLNode list) {
			// TODO
			// Add implementation
			int count = 0;
			if(list != null){
				DLNode cur = list.next;
				while (cur != null) {
					count++;
					cur = cur.next;
				}
			}
			return count;
		}

			/**
		 * finds nodes of double-linked list that satisfies given condition and
		 * delete theirs from list. create new single-linked list that contains
		 * nodes with values of such deleted nodes
		 * 
		 * @param dlHead
		 *            first node of double-linked list
		 * @return head of newly created single-linked list, or null, if any
		 *         elements of double-linked list can't be deleted
		 */
		private static SLNode createSecondList(DLNode dlHead) {
			// TODO
			// task 3.2
			// create head of single-linked list
			// go through double-linked list from the head to the tail
			// if the current node of double-linked list is such to be deleted (see variant item (b)),
			// save data from this node, delete node, create new single-linked list
			// node with saved data and add new node to the list in the given place
			// (see variant item (c))
			SLNode slHead = null;
			if( dlHead == null || dlHead.next == null){
				return slHead;
			}
			SLNode newSLNode = null;
			DLNode cur = dlHead.next;
			
			final int min = minDLNode(dlHead);
			final int max = maxDLNode(dlHead);
			
			while(cur != null){
				if(cur.data > min && cur.data < max){
					newSLNode = createSLNode(cur.data);
					slHead = addNode(slHead, newSLNode);
					deleteDLNode(cur);
				}
				cur = cur.next;
			}
			return slHead;
		}
		
		/**
		 * @param toDelete
		 * 				node, that will be deleted
		 * @param head
		 * 				head of list to shorten
		 * @return head of shorted DL list
		 */
		private static void deleteDLNode(DLNode toDelete){
			if(toDelete.next != null){
				toDelete.next.prev = toDelete.prev;
			}
			toDelete.prev.next = toDelete.next;
		}
		
		/**
		 * @param head
		 * 			head of DL list to find min
		 * @return minimal number
		 */
		private static int minDLNode(DLNode head ){
			int min = head.next.data;
			DLNode cur = head.next;
			while(cur != null){
				if(cur.data < min){
					min = cur.data;
				}
				cur = cur.next;
			}
			return min;
		}
		/**
		 * @param head
		 * 				head of DL list to find max
		 * @return maximal number
		 */
		private static int maxDLNode(DLNode head ){
			int max = head.next.data;
			DLNode cur = head.next;
			while(cur != null){
				if(cur.data > max){
					max = cur.data;
				}
				cur = cur.next;
			}
			return max;
		}

	}


