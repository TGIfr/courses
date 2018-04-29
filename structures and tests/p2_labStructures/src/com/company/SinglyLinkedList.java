package com.company;



/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 3
 * 
 * @author Olena Khomenko <br>
 *         Singly-linked list. Implements List interface <br>
 *         This class skeleton contains methods with TODO <br>
 *         Implement methods with TODO and write addition methods to support
 *         class functionality.
 * 
 *         Operations that index into the list will traverse the list from the
 *         beginning or the end, whichever is closer to the specified index. <br>
 *
 */

public class SinglyLinkedList implements List {
	//tests
	public static void main(String[] args) {
		List list = new SinglyLinkedList();
		list.add(Integer.toBinaryString(4));
		list.add(Integer.toBinaryString(6));
		//size
		assert list.size() == 2;
		//set
		assert  list.set(2, "MUST RETURN NULL") == null;
		assert list.set(1, Integer.toBinaryString(6)).equals(Integer.toBinaryString(6)) ;
		//add
		assert !list.add("returns false");
		assert !list.add(1, "returns false");
		assert !list.add(3, "MUST RETURN FALSE");
		assert(!list.add(-1, "MUST RETURN FALSE"));
		assert list.add(2, Integer.toBinaryString(8));
		assert list.size() == 3;
		//remove by index
		assert list.remove(3) == null;
		assert list.remove(2).equals(Integer.toBinaryString(8));
		assert list.size() == 2;
		//remove by string
		assert !list.remove("THIS IS NOT IN LIST");
		assert list.remove(Integer.toBinaryString(4));
		assert list.size() == 1;
		//get
		assert list.get(1) == null;
		assert list.get(0).equals(Integer.toBinaryString(6));
		list.remove(0);
		//isEmpty
		assert list.isEmpty() ;
		System.out.println("ALL PASSED SUCCESSFULLY");
	}

	//!realization
	private boolean checkStr(String number){
		int lengthOfInt = 32;
		if(number.length() > lengthOfInt) return false;
		for(int	i = 0; i < number.length(); i++){
			char toTest = number.charAt(i);
			if(toTest != '0' && toTest != '1')
				return false;
			if(i == 0 && toTest == '1' && number.length() == 32) return false;
		}
		return true;
	}
	// Pointer to head node.
	private SLNode head;
	public void print(){
		SLNode cur = head;
		while(cur != null){
			System.out.println(cur.data);
			cur = cur.next;
		}
	}

	@Override
	public boolean add(String element) {
		if(!checkStr(element)) return false;
		SLNode temp = new SLNode(element);
		SLNode curr = head;

		if (head == null) {
			head = temp;
		} else {
			while (curr.next != null) {
				curr = curr.next;
			}

			curr.next = temp;
		}
		return true;
	}

	@Override
	public boolean add(int index, String element) {
		if(index > size() || index < 0 || !checkStr(element))
			return false;
		SLNode temp = new SLNode(element);
		SLNode curr = head;

		if (index == 0){
			temp.next = head;
			this.head = temp;
		} else{
			for(int i = 1; i < index; i++){
				curr = curr.next;
			}
			temp.next = curr.next;
			curr.next = temp;
		}
		return true;
	}

	@Override
	public String remove(int index) {
		if(index > size() - 1 || index < 0)
			return null;
		SLNode curr = head;
		SLNode temp = head;
		if (index == 0){
			head = head.next;
			curr.next = null;
		} else{
			for(int i = 0; i < index - 1; i++){
				curr = curr.next;
			}
			temp = curr.next;
			curr.next = curr.next.next;
		}
		return temp.data;
	}

	@Override
	public boolean remove(String element) {
		SLNode curr = head;
		if(head != null && head.data.equals(element)){
			head = head.next;
			return true;
		}
		while(curr.next != null && !curr.next.data.equals(element) ){
			curr = curr.next;
		}
		if(curr.next == null || !curr.next.data.equals(element))
			return false;
		curr.next = curr.next.next;
		return true;
	}

	@Override
	public String get(int index) {
		if(index > size() - 1 || index < 0)
			return null;
		SLNode curr = head;
		for (int i = 0; i < index; i++){
			curr = curr.next;
		}
		return curr.data;
	}

	@Override
	public String set(int index, String element) {
		SLNode curr = head;
		if(index > size() - 1 || index < 0)
			return null;
		String temp;
		if (index == 0){
			temp = curr.data;
			curr.data = element;
		} else{
			for(int i = 0; i < index; i++){
				curr = curr.next;
			}
			temp = curr.data;
			curr.data = element;
		}

		return temp;
	}

	@Override
	public int size() {
		SLNode temp = head;
		int i = 0;
		while(temp != null){
			temp = temp.next;
			i ++;
		}
		return i;
	}

	@Override
	public boolean isEmpty() {
		return head == null;
	}

}
