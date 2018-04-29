package Lab_6;


	/**KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 6
	 * 
	 * @author Olena Khomenko
	 * 
	 * Min-priority queue order elements in a FIFO (first-in-first-out)policy. <br>
	 * The head of the this queue is the least element with respect to the specified ordering. It would be removed by a call to removeMin(). 
	 * Every Queue implementation must specify its ordering properties
	 * 
	 * 
	 */

	public interface MinPriorityQueue {

		/**
		 * insert key into min-priority queue
		 * 
		 * @param s
		 *            the Student's object to insert
		 */
		public void insert(Student key);

		/**
		 * test the whether min-priority queue is empty
		 * 
		 * @return true if priority queue is empty
		 */
		public boolean isEmpty();

		/**
		 * remove from min-priority queue and return the element with the smallest priority
		 * 
		 * @return the smallest priority
		 */
		public Student removeMin();

		/**
		 * Retrieves, but does not remove, the element with the smallest priority of this
		 * queue
		 * 
		 * @return the smallest key, or null if this queue is empty
		 */
		public Student min();

		/**
		 * Returns the number of elements in this queue
		 * 
		 * @return the number of elements in this queue
		 */
		public int size();

	}


