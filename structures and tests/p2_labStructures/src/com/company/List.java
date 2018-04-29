package com.company;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 3
 * 
 * @author Olena Khomenko <br>
 *         This interface provides the methods for positional (indexed) access
 *         to list elements.
 */
public interface List {
	/**
	 *	prints the list
	 */
	public void print();

	/**
	 * Appends the specified element to the end of this list
	 * 
	 * @param e
	 *            element to be appended to this list
	 * @return true if this list changed as a result of the call
	 */
	boolean add(String e);

	/**
	 * Inserts the specified element at the specified position in this list
	 * 
	 * @param index
	 *            index at which the specified element is to be inserted
	 * @param e
	 *            element to be inserted
	 * @return true if this list changed as a result of the call
	 */
	boolean add(int index, String e);

	/**
	 * Removes the element at the specified position in this list. If the list
	 * is empty, returns empty String
	 * 
	 * @param index
	 *            the index of the element to be removed
	 * @return the element previously at the specified position, or empty String
	 */
	String remove(int index);

	/**
	 * Removes the first occurrence of the specified element from this list, if
	 * it is present
	 * 
	 * @param e
	 *            element to be removed from this list, if present
	 * @return true if this list contained the specified element
	 */
	boolean remove(String e);

	/**
	 * Returns the element at the specified position in this list
	 * 
	 * @param index
	 *            index of the element to return
	 * @return
	 */
	String get(int index);

	/**
	 * Replaces the element at the specified position in this list with the
	 * specified element
	 * 
	 * @param index
	 *            index of the element to replace
	 * @param e
	 *            element to be stored at the specified position
	 * @return the element at the specified position in this list
	 */
	String set(int index, String e);

	/**
	 * Returns the number of elements in this list
	 * 
	 * @return the number of elements in this list
	 */
	int size();

	/**
	 * Returns true if this list contains no elements
	 * 
	 * @return true if this list contains no elements
	 */
	boolean isEmpty();

}
