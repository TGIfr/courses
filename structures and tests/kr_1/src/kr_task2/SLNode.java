package kr_task2;
/**
 * KPI- FPM - PZKS
 * Course: Algorithms and Data Structures (1)
 * Laboratory work 3
 * @author Olena Khomenko
 * 
 * Node in a single-linked list. 
 *
 */
public class SLNode {	
	/**
	 * The data stored in this node.
	 */
	int data; 
	
	/**
	 * The node following this one. 
	 */
	SLNode next; 
	
	
	public static boolean isSorted (SLNode head){
		SLNode cur = head;
		while(cur.next != null){
			if(cur.data >= cur.next.data){
				return false;
			}
			cur = cur.next;
		}
		return true;
	}

}
