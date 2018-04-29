package com.company;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 3
 * 
 * @author Olena Khomenko <br>
 *         Queue order elements in a FIFO (first-in-first-out)policy. <br>
 *         In a FIFO queue,all new elements are inserted at the tail of the
 *         queue. The head of the queue is that element which would be removed
 *         by a call to dequeue(). Other kinds of queues may use different
 *         placement rules. Every Queue implementation must specify its ordering
 *         properties
 * 
 */

public interface Queue {
	/**
	 *	prints the queue
	 */
	public void print();
	/**
	 * Insert element e at the tail of the queue
	 * 
	 * @param e
	 *            the element to add
	 * @return true if this queue changed as a result of the call
	 */
	public boolean enqueue(int e);

	/**
	 * Retrieves and removes the head of this queue
	 * 
	 * @return the head of this queue or exception
	 */
	public int dequeue();

	/**
	 * Retrieves, but does not remove, the head of this queue
	 * 
	 * @return the head of this queue, or exception if this queue is empty
	 */
	public int head();

	/**
	 * Returns the number of elements in this queue
	 * 
	 * @return the number of elements in this queue
	 */
	public int size();

	/**
	 * Returns true if this queue contains no elements.
	 * 
	 * @return true if this queue contains no elements
	 */
	public boolean isEmpty();

}
