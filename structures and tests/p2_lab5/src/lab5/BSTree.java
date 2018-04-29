package lab5;

import java.util.*;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 5
 * 
 * @author Olena Khomenko <br>
 * 
 *         Binary search tree based implementation StudentDictionary Keeps
 *         specified information about students
 * 
 *         each node contains id (number of student's card) and information
 *         about student (name, surname etc.)
 * 
 *         all search, delete and get operation use unique id as a key
 * 
 * @param <E>
 */

public class BSTree<E extends Student> implements StudentDictionary<E> {

	/**
	 * root of a tree
	 */
	private TreeNode<E> root;
	private int size = 0;
	public BSTree() {

	}

	/**
	 * Returns true if this dictionary (binary search tree) contains an student
	 * for the specified cardNumber
	 * 
	 * @param cardNumber
	 *            cardNumber whose presence in this tree is to be tested
	 * @return true if this tree contains an student record for the specified
	 *         cardNumber
	 */
	@Override
	public boolean containsKey(int cardNumber) {
		// Error: if a cardNumber <= 0 return false

		return cardNumber >= 0 && get(cardNumber) != null;
	}

	/**
	 * Returns the number of nodes in this tree.
	 * 
	 * @return he number of nodes in this tree
	 */
	@Override
	public int size() {
		return size;
	}

	/**
	 * Returns the student to which the specified cardNumber is associated, or
	 * null if this tree contains no student for the cardNumber.
	 * 
	 * @param cardNumber
	 *            the cardNumber whose associated student is to be returned
	 * @return the student with the specified cardNumber, or null if this tree
	 *         contains no student for the cardNumber or cardNumber is invalid
	 *         (negative or 0)
	 */
	@Override
	public E get(int cardNumber) {
		TreeNode<E> node =  get(root, cardNumber);
		if(node == null) return null;
		else return node.getValue();
	}

	/**
	 * Returns the value associated with the given key.
	 *
	 * @param  key the key
	 * @return the value associated with the given key if the key is in the symbol table
	 *         and {@code null} if the key is not in the symbol table
	 */
	private TreeNode<E> get(TreeNode<E> x, int key) {

		if (x == null) return null;
		int cmp = key - x.getKey();
		if      (cmp < 0) return get(x.left, key);
		else if (cmp > 0) return get(x.right, key);
		else              return x;
	}

	/**
	 * Removes the student for this cardNumber from this tree if present.
	 * 
	 * @param cardNumber
	 *            cardNumber for which student should be removed
	 * @return the previous student associated with cardNumber, or null if there
	 *         was no student for cardNumber.
	 */
	@Override
	@SuppressWarnings("unchecked")
	public E remove(int cardNumber) {
		TreeNode cur = get(root, cardNumber);
		return remove(cur);
	}

	@SuppressWarnings("unchecked")
	private E remove(TreeNode node){
		if(node == null) return null;
		Student temp = node.getValue();
		if (node.right == null) {
			replaceSubTree(node, node.left);
		} else {
			TreeNode leftMost = node.right.getMinimum();
			if (!node.isRightChild(leftMost)) {
				replaceSubTree(leftMost, leftMost.right);
			} else {
				replaceSubTree(node.right, leftMost.right);
			}
			leftMost.setRight(node.right);
			leftMost.setLeft(node.left);
			replaceSubTree(node, leftMost);
		}
		size --;
		return (E)temp;
	}

	// use this method when remove nodes
	private void replaceSubTree(TreeNode<E> u, TreeNode<E> v) {
		if (u == root) {
			root = v;
		} else {
			TreeNode<E> par = u.parent;
			if (par.isLeftChild(u)) {
				par.setLeft(v);
			} else {
				par.setRight(v);
			}
		}
	}

	/**
	 * Remove from a tree all students that satisfy specified criteria
	 *
	 * @return number of students was be removed
	 */
	@SuppressWarnings("unchecked")
	public int removeByVariant() {
		// 1) find all nodes witch students satisfy specified removeCriteria
		// save in a list nodes to be removed
		// 2) call method remove (node) for each node in a list
		// 3) call size method to check successful removing
		// 4) return difference between old size and new size
		String gender = "Female";
		float mark = 5;
		int course = 5;
		Stack<TreeNode> nodes = new Stack();
		findByCriteria( gender,  mark, nodes, root, course);

		int sizeBeforeDelete = size();
		int mustBeDeleted = nodes.size();
		while(nodes.size() > 0){
			TreeNode val =  nodes.pop();
			remove(val);
			//System.out.println();
			//printTree();

		}

		int actuallyDeleted = sizeBeforeDelete - size();
		if(actuallyDeleted !=  mustBeDeleted)
			System.out.println("Error: removing by criteria failed");

		return  actuallyDeleted;

	}
	@SuppressWarnings("unchecked")
	private void findByCriteria(String gender, float mark, Stack toFill, TreeNode x, int course){
		if(x == null) return;
		findByCriteria( gender,  mark, toFill, x.left, course);
		Student st = x.getValue();
		if(st.gender.equals(gender) && (Math.abs(mark - st.mark) < 0.00001) && st.course == course){
			toFill.push(x);
		}
		findByCriteria( gender,  mark, toFill, x.right, course);
	}

	public void printTree() {
		TreeNode tmpRoot = root;
		if(root == null) return;
		Queue<TreeNode> currentLevel = new LinkedList<TreeNode>();
		Queue<TreeNode> nextLevel = new LinkedList<TreeNode>();

		currentLevel.add(tmpRoot);

		while (!currentLevel.isEmpty()) {
			Iterator<TreeNode> iter = currentLevel.iterator();
			while (iter.hasNext()) {
				TreeNode currentNode = iter.next();
				if (currentNode.left != null) {
					nextLevel.add(currentNode.left);
				}
				if (currentNode.right != null) {
					nextLevel.add(currentNode.right);
				}
				System.out.print(currentNode.getKey() + " ");
			}
			System.out.println();
			currentLevel = nextLevel;
			nextLevel = new LinkedList<TreeNode>();

		}

	}

	/**
	 * Returns true if this dictionary contains no key-value mappings
	 * 
	 * @return true if this dictionary contains no key-value mappings
	 */
	@Override
	public boolean isEmpty() {
		return size == 0;
	}

	/**
	 * Associates the specified student with the specified cardNumber in this
	 * dictionary. If the dictionary previously contained a mapping for the
	 * cardNumber, the old student is replaced by the specified student.
	 * 
	 * @param num
	 *            cardNumber with which the specified student is to be
	 *            associated
	 * @param s
	 *            student to be associated with the specified cardNumber
	 * @return the previous student associated with cardNumber, or null if there
	 *         was no mapping for key
	 */
	@Override
	@SuppressWarnings("unchecked")
	public E put(int num, Student s) {
		TreeNode cur = root, par = null;
		while (cur != null) {
			int cmp = num - cur.getKey();
			if (cmp == 0) {
				Student temp = cur.getValue();
				cur.setValue(s);
				return (E)temp;
			} else {
				par = cur;
				if (cmp < 0) {
					cur = cur.left;
				} else {
					cur = cur.right;
				}
			}
		}
		TreeNode<E> newNode = new TreeNode(s, par);
		if (par == null) {
			root = newNode;
		} else {
			if (num - par.getKey() < 0) {
				par.addLeftChild(s);
			} else {
				par.addRightChild(s);
			}
		}
		size++;
		return null;
	}


	/**
	 * Outputs dictionary elements in table form
	 */

	@Override
	public void printDictionary() {

		// Invoke private recursive method for traversing a tree. Type of
		// traversing is defined in your variant
		// preorder: ������ �������
		// postorder: ��������� �������
		// inorder: ����������� �������

		printDictionary(root);

	}

	private void printDictionary(TreeNode node){
		if(node == null) return;
		printDictionary(node.left);
		System.out.println(node.getValue());
		printDictionary(node.right);
	}


	class TreeNode<E extends Student> {
		/**
		 * information about student. Instance of class Student
		 */
		private E st;

		/**
		 * reference to the right node
		 */
		private TreeNode<E> right;

		/**
		 * reference to the left node
		 */
		private TreeNode<E> left;
		/**
		 * reference to the parent node
		 */

		private TreeNode<E> parent;

		TreeNode(E e) {
			st = e;

		}

		TreeNode(E s, TreeNode<E> parent) {
			this(s);
			this.parent = parent;

		}

		int getKey() {
			return st.getkey();
		}

		E getValue() {
			return st;
		}

		@SuppressWarnings("unchecked")
		TreeNode<E> addLeftChild(E s) {
			TreeNode newNode = new TreeNode<>(s, this);
			setLeft(newNode);
			return newNode;
		}

		@SuppressWarnings("unchecked")
		TreeNode<E> addRightChild(E s) {
			TreeNode newNode = new TreeNode<>(s, this);
			setRight(newNode);
			return newNode;

		}

		void setValue(E st) {
			this.st = st;
		}
		void setLeft(TreeNode<E> left) {
			this.left = left;
			if (left != null) {
				left.parent = this;
			}
		}

		void setRight(TreeNode<E> right) {
			this.right = right;
			if (right != null) {
				right.parent = this;
			}
		}

		boolean isLeftChild(TreeNode<E> node) {
			return this.left == node;
		}

		boolean isRightChild(TreeNode<E> node) {
			return this.right == node;
		}

		@SuppressWarnings("unchecked")
		TreeNode<E> getMinimum() {
			TreeNode cur = this;
			while(cur.left != null){
				cur = cur.left;
			}
			return cur;
		}


		@Override
		public String toString() {
			return st.toString();
		}

	}

}
