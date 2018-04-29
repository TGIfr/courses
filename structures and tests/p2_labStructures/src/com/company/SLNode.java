package com.company;

/**
 * KPI- FPM - PZKS <br>
 * Course: Algorithms and Data Structures (2) Laboratory work 3
 * 
 * @author Olena Khomenko
 *
 *         Node in a singly-linked list.
 */

public class SLNode {
	String data; // the data stored in this node.
	SLNode next; // pointer to the next node

	/**
	 * Construct the node of singly-linked list with data and null pointer to
	 * the next node
	 * 
	 * @param data
	 *            the data to stored in this node
	 */
	public SLNode(String data) {
		this.data = data;
		next = null;
	}

	/**
	 * Construct the node of singly-linked list with data and pointer to the
	 * next node
	 * 
	 * @param data
	 *            the data to stored in this node
	 * @param next
	 *            pointer to the next node
	 */
	public SLNode(String data, SLNode next) {
		this.data = data;
		this.next = next;
	}
}
