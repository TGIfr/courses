package com.company;

import java.util.NoSuchElementException;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 3
 * 
 * @author Olena Khomenko <br>
 *         Resizable-array queue. Implements Queue interface <br>
 *         This class skeleton contains methods with TODO <br>
 *         Implement methods with TODO and write addition methods to support
 *         class functionality.
 * 
 */

public class ArrayQueue implements Queue {
	//tests
	public static void main(String[] args){
		//constructor exception
		try {
			Queue q = new ArrayQueue(-1);
		} catch (IllegalArgumentException e){
			System.out.println("Constructor minus number test passed");
		}
		Queue q = new ArrayQueue(2);
		//isEmpty exception
		assert (q.isEmpty());
		//deque exception
		try{
			q.dequeue();
		} catch (NoSuchElementException e){
			System.out.println("Deque test passed");
		}
		//head exception
		try{
			q.head();
		} catch (NoSuchElementException e){
			System.out.println("Head test passed");
		}
		//size
		assert(q.size() == 0);
		q.enqueue(10);
		assert(q.size() == 1);
		//over adding test
		q.enqueue(20);
		q.enqueue(30);
		q.print();
		assert(q.size() == 3);
		//deque

		assert q.dequeue() == 10;
		q.print();
		assert q.size() == 2;
		assert !q.isEmpty();


		System.out.println("ALL TESTS PASSED");
	}

	//! realization
	// The array in which the elements of the queue are stored
	int[] queue;

	// The index of the element at the head of the queue
	private int head;

	private int n;          // number of elements on queue

	// The index at which the next element would be added to the tail of the
	// queue
	private int tail;

	// The minimum capacity that we'll use for a newly created queue
	private final int defaultCapacity = 8;

	public ArrayQueue() {
		queue =  new int[defaultCapacity];
		head = 0;
		tail = 0;
		n = 0;
	}

	public ArrayQueue(int initialCapacity) {
		if(initialCapacity <= 0){
			throw new IllegalArgumentException("Size cannot be less than or equal to zero");
		}
		queue =  new int[initialCapacity];
		head = 0;
		tail = 0;
		n = 0;
	}

	public void print(){
		if(!isEmpty()){
			for (int cur = head; cur !=  tail; cur++){
				System.out.println(queue[cur]);
			}
		}
	}

	// resize the underlying array
	private void resize(int capacity) {
		assert capacity >= n;
		int[] temp =  new int[capacity];
		for (int i = 0; i < n; i++) {
			temp[i] = queue[(head + i) % queue.length];
		}
		queue = temp;
		head = 0;
		tail  = n;
	}
	@Override
	public boolean enqueue(int e) {
		// double size of array if necessary and recopy to front of array
		if (n == queue.length) resize(2*queue.length);   // double size of array if necessary
		queue[tail++] = e;                        // add item
		if (tail == queue.length) tail = 0;          // wrap-around
		n++;
		return true;
	}

	@Override
	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public int dequeue() {
		if (isEmpty()) throw new NoSuchElementException("Queue underflow");
		int item = queue[head];
		queue[head] = 0;                            // to avoid loitering
		n--;
		head++;
		if (head == queue.length) head = 0;           // wrap-around
		// shrink size of array if necessary
		if (n > 0 && n == queue.length/4) resize(queue.length/2);
		return item;
	}

	@Override
	public int head() {
		if (isEmpty()) {
			throw new NoSuchElementException("Queue is empty, cant return head");
		} else {
			return queue[head];
		}
	}

	@Override
	public int size() {
		return n;
	}

}
