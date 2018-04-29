package lab4_task2;

import common.FigureSet;
import common.GeomFigure;

import lab4_task1.Hashtable;
import java.util.Map;


/**
 * 
 * This class implements a set as a hash table. Hash table is an associative
 * array of entries. <br>
 * Each entry contains geometric figure or null. <br>
 * Hash table resolves collisions by open addressing
 *
 */
public class OAHashtable extends Hashtable {






	/**
	 * Constructs a new, empty hashtable with a default initial capacity (11)
	 * and load factor (0.75).
	 */
	private final static DelGeomFigure DELL = DelGeomFigure.getInstance();

	public OAHashtable() {

		// create an array of size equals to default initialCapacity
		super();

	}

	/**
	 * Constructs a new, empty hashtable with the specified initial capacity and
	 * default load factor (0.75).
	 * 
	 * @param initialCapacity
	 *            the initial capacity of the hashtable
	 */
	public OAHashtable(int initialCapacity) {

		// create an array of size equals to initialCapacity
		super(initialCapacity);
	}

	/**
	 * Constructs a new, empty hashtable with the specified initial capacity and
	 * the specified load factor.
	 * 
	 * @param initialCapacity
	 *            the initial capacity of the hashtable
	 * @param loadFactor
	 *            the load factor of the hashtable
	 */
	public OAHashtable(int initialCapacity, float loadFactor) {

		//  create an array of size equals to initialCapacity
		//  initialize field loadFactor
		super(initialCapacity, loadFactor);


	}



	private int calculateSlot(int hash, int probe) {
		return (hash + probe * probe) % table.length;
	}
	private int slotSearchExisting(int hash, GeomFigure gf) {
		int probe = 0;
		int index;
		do {
			index = calculateSlot(hash, probe);
			if (table[index] != null && table[index].equals(gf)) {
				return index;
			} else {
				probe ++;
			}
		} while (probe < table.length  && table[index] != null);

		return -1;
	}


	public boolean add(GeomFigure gf) {
		// if gf is not null and hashtable doesn't contain gf
		// -----calculate hashvalue
		// ------while slot is empty
		// ----------search next empty slot
		// ----------increase probe number
		if( size() / table.length > loadFactor){
			rehash();
		}
		if(gf != null && !contains(gf)){
			int hash = super.hash(gf);
			int probe = 0;
			while(probe < table.length ){
				int slot = calculateSlot(hash, probe);
				if(table[slot] == null || table[slot].equals(DELL)){
					table[slot] = gf;
					size++;
					return true;
				}
				probe ++;
			}
		}
		return false;
	}


	public boolean contains(GeomFigure gf) {
		// if gf is not null
		// ----calculate hashvalue of gf
		// ----search slot which object equals to gf
		if(gf != null){
			int hash = hash(gf);
			if(slotSearchExisting(hash, gf) != -1)
				return true;
		}
		return  false;
//		if(gf != null){
//			int hash = hash(gf);
//			int probe = 0;
//			int index;
//			do {
//				index = calculateSlot(hash, probe);
//				if (table[index] == gf) {
//					return true;
//				} else {
//					probe = probe + 1;
//				}
//			} while (probe != (table.length - 1) && table[index] != null);
//		}
//		return false;
	}


	public boolean remove(GeomFigure gf) {
		// if gf is not null and hashtable contains gf
		// ----calculate hashvalue of gf
		// ----search slot which object equals to gf
		// ----if such element has found
		// --------write to the slot DELL
		// --------decrease the size of hash table
		// --------return true
		if (gf != null && contains(gf)) {
			int hash = hash(gf);
			int slot = slotSearchExisting(hash, gf);
			if(slot != -1){
				table[slot] = DELL;
				size --;
				return true;
			}
		}
		//! old
//		if (gf != null && contains(gf)) {
//			int hash = hash(gf);
//			int slot = slotSearchExisting(hash, gf);
//			int probe = 0;
//			int index;
//			do {
//				index = calculateSlot(hash, probe);
//				if (table[index] == gf) {
//					table[slot] = DELL;
//					size --;
//					return true;
//				} else {
//					probe = probe + 1;
//				}
//			} while (probe != (table.length - 1) && table[index] != null);
//
//			return false;
//		}
		return false;

	}



	public void print() {
		// Output the table , where each row contains a number of the hash-table
		// slot, and the element itself.For example,

		// System.out.println(String.format(" %-6d|%s", index, table [index]));

		// If a slot is empty the row contains a number of the hash-table slot
		// and the message �The slot is empty�.
		for(int index = 0 ; index < table.length; index++ ){

			if( table[index] != null && !table[index].equals(DELL)){
				System.out.println(String.format(" %-6d|%s", index, table [index]));
			}
			else {
				System.out.println(String.format("the slot %-6d is empty", index ));
			}
		}
	}

}

/*
 * Represents object that was be deleted from a table
 */

class DelGeomFigure extends GeomFigure {

	private static DelGeomFigure delFigure = null;;

	private DelGeomFigure() {
		super(0, 0 , -1);
	}

	public static DelGeomFigure getInstance() {
		if (delFigure == null) {
			delFigure = new DelGeomFigure();
		}
		return delFigure;
	}

	@Override
	public String toString() {
		return "deleted element";
	}

}
