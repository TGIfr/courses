package kr_task2;


public class Main {
	public static void main(String[] args) {
		int test1[] = { 1 , 5 , 3};
		int test2[] = {1 , 3, 5};
		int test3[] = {1 , 3, 6};
		SLNode head1 = arrToList(test1);
		printList(head1);
		SLNode head2 = arrToList(test2);
		printList(head2);
		SLNode head3 = arrToList(test3);
		SLNode mergedList1 = mergeSLListSorted(null , head2);
		
		SLNode mergedList2 = mergeSLListSorted(head1 , head2);
		SLNode mergedList3 = mergeSLListSorted(head2 , head3);
		printList(mergedList3);
		
		
	}
	private static SLNode mergeSLListSorted(SLNode head1, SLNode head2){
		if(head1 == null || head2 == null){
			System.out.println("ERROR: EMPTY LIST");
			return null;
		}
		if(!isSorted(head1) || !isSorted(head2)){
			System.out.println("ERROR: LIST IS NOT SORTED");
			return null;
		}
		SLNode newList = null;
		while(head1 != null && head2 != null){
			if(head1.data < head2.data){
				newList = addNodeLast(newList, head1.data);
				head1 = head1.next;
			} else {
				newList = addNodeLast(newList, head2.data);
				head1 = head2.next;
			}
			if(head1 == null){
				newList = addTail(newList, head2);
				head2 = null;
			}
			if(head2 == null){
				newList = addTail(newList, head1);
			}
		}
		return newList;
	}
	private static SLNode addTail (SLNode headNew, SLNode headToAdd){
		SLNode cur = headNew;
		while (cur.next != null) {
			cur = cur.next;
		}
		cur.next = headToAdd;
		return headNew;
	}
	private static boolean isSorted (SLNode head){
		SLNode cur = head;
		while(cur.next != null){
			if(cur.data >= cur.next.data){
				return false;
			}
			cur = cur.next;
		}
		return true;
	}
	private static void printList(SLNode head){
		SLNode cur = head;
		if(cur == null){
			System.out.print("List is empty");
		}
		while(cur != null){
			System.out.print(cur.data + " ");
			cur = cur.next;
		}
		System.out.println();
		
	}
	private static SLNode arrToList(int arr[]){
		SLNode head = null;
		for(int i = 0; i < arr.length; i++){
			head  = addNodeLast( head, arr[i]);
		}
		return head;
	}
	private static SLNode createSLNode(int data) {
		SLNode newNode = new SLNode();
		newNode.data = data;
		newNode.next = null;
		return newNode;
	}
	private static SLNode addNodeLast(SLNode head, int data) {
		SLNode node = createSLNode (data);
		if(head == null){
			head = node;
		} else { 
			SLNode cur = head;
			while (cur.next != null) {
				cur = cur.next;
			}
			cur.next = node;
		}
		return head;
	}

}
