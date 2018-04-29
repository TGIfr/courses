package Lab_6.min_priority_queue;

import Lab_6.Heap;
import Lab_6.MinPriorityQueue;
import Lab_6.Student;
import Lab_6.StudentComparator;
import Lab_6.array_linked_lists.StudentArrayList;

/**
 * KPI- FPM - PZKS Course: Algorithms and Data Structures (2) Laboratory work 6
 * 
 * @author Olena Khomenko
 * 
 *         An unbounded min-priority queue based on a priority heap. The
 *         elements of the min-priority queue are ordered by a
 *         StudentComparator. The head of this queue is the least element with
 *         respect to the specified ordering. <br>
 *         A priority queue does not permit null elements. <br>
 *         Keeps elements of type Student.<br>
 */
public class HeapPriorityQueue implements MinPriorityQueue, Heap {
	private StudentArrayList heap;
	private StudentComparator c;

	public HeapPriorityQueue(StudentComparator c) {
		heap = new StudentArrayList();
		this.c = c;
		heap.add(null); //element for the 0 place
	}

	@Override
	public void insert(Student s) {
		heap.add(s);
		swim(size());
	}

	@Override
	public boolean isEmpty() {

		return heap.size() == 1;
	}

	@Override
	public Student removeMin() {
		if(isEmpty())
			return null;
		else{
//			Student min = min();
//			swap(1, size());
//			heap.remove(size());
			Student min = heap.set(1, heap.get( size() ));
			heap.remove(size());

			sink(1);
			return min;
		}
	}

	private void swap(int s1Index, int s2Index){
		if(		s2Index == s1Index ||
				s1Index < 1 || s1Index > heap.size() ||
				s2Index < 1 || s2Index > heap.size() )
			return;

		Student s1 = heap.get(s1Index);
		Student s2 = heap.set(s2Index, s1);
		heap.set(s1Index, s2);
	}

	@Override
	public Student min() {
		if(isEmpty())
			return null;
		else
			return heap.get(1);
	}

	@Override
	public int size() {

		return heap.size() - 1;
	}

	@Override
	public void swim(int index) {
		if(index == 1) return;

		int p = getParent(index);
		if(c.compare( heap.get(p) , heap.get(index)) > 0){
			swap( p, index);
			swim(p);
		}
	}

	@Override
	public void sink(int index) {
		int l = getLeft(index);
		int r = getRight(index);
		int min = index;

		if(l < heap.size() && c.compare( heap.get(l) , heap.get(index)) < 0)
			min = l;

		if(r < heap.size() && c.compare( heap.get(r) , heap.get(min)) < 0)
			min = r;

		if(index != min){
			swap(min, index);
			sink(min);
		}



	}

	@Override
	public int getParent(int index) {
		return index / 2;
	}

	@Override
	public int getLeft(int i) {
		return i * 2;
	}

	@Override
	public int getRight(int i) {
		return i * 2  + 1;
	}


}
