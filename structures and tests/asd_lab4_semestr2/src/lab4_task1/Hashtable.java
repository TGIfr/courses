package lab4_task1;

import common.FigureSet;
import common.GeomFigure;

/**
 * 
 * This class implements a set as a hash table. Hash table is an associative
 * array of entries. <br>
 * Each entry contains geometric figure or null. <br>
 * Hash table does not resolve any collisions
 *
 */
public class Hashtable implements FigureSet {

	protected GeomFigure[] table;

	/**
	 * the number of non-null entries in the hashtable
	 */
	protected int size;

	/**
	 * default size of the hashtable
	 */
	private final int initialCapacity = 11;

	/**
	 * The load factor is a measure of how full the hash table is allowed to get
	 * / before its capacity is automatically increased
	 */
	protected double loadFactor = 0.75;

	/**
	 * It is used in multiplication hash function
	 */
	private final double A = (Math.sqrt(5) - 1) / 2;

	/**
	 * Constructs a new, empty hashtable with a default initial capacity (11)
	 * and load factor (0.75).
	 */
	public Hashtable() {


		// create an array of size equals to default initialCapacity
		table = new GeomFigure[initialCapacity];

	}

	/**
	 * Constructs a new, empty hashtable with the specified initial capacity and
	 * default load factor (0.75).
	 * 
	 * @param initialCapacity
	 *            the initial capacity of the hashtable
	 */
	public Hashtable(int initialCapacity) {

		// create an array of size equals to initialCapacity
		table = new GeomFigure[initialCapacity];
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
	public Hashtable(int initialCapacity, double loadFactor) {

		//  create an array of size equals to initialCapacity
		//  initialize field loadFactor
		table = new GeomFigure[initialCapacity];
		this.loadFactor = loadFactor;

	}

	/**
	 * Returns the number of entries in the hashtable
	 * 
	 * @return the number of entries in the hashtable
	 */
	public int size() {

		return size;
	}

	/**
	 * Increases the capacity of and internally reorganizes this hashtable, in
	 * order to accommodate and access its entries more efficiently. This method
	 * is called when the number of elements in the hashtable exceeds this
	 * hashtable's capacity and load factor
	 */
	protected void rehash() {
//		GeomFigure tempArray[] = new GeomFigure[table.length];
//		System.arraycopy(table, 0, tempArray, 0, table.length);
//		table = new GeomFigure[table.length * 2];
		GeomFigure tempArray[] = table;
		table = new GeomFigure[table.length * 2];
		size = 0;
		for(GeomFigure gf : tempArray){
			this.add(gf);
		}
	}

	/**
	 * The hash function is used to calculate the hasvalue of the object gf.
	 * Choose hashing method from your variant (table 1): deletion or
	 * multiplication
	 * 
	 * @param gf
	 *            some geometric figure
	 * @return hash value - index in table
	 */
	protected int hash(GeomFigure gf) {

		//
		return (int)(table.length *((gf.hashCode() * A) % 1));
	}

	@Override
	public boolean add(GeomFigure gf) {
		// if gf is not null
		// ---calculate number of slot where should be object gf
		// ------if slot is empty
		// ----------write gf to the slot and rehash if need
		// ----------increase the size of hash table
		if(size / (double)table.length  >= loadFactor ){
			rehash();
		}
		if(gf != null){
			int slot = hash(gf);
			if(table[slot] == null){
				table[slot] = gf;
				size++;
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean contains(GeomFigure gf) {
		// if gf is not null
		// ----Calculate hashvalue of gf
		// ------if slot is not empty
		// ---------compare gf and object from the slot
		if(gf != null){
			int slot = hash(gf);
			if(table[slot] != null){
				return gf.equals(table[slot]);
			}
		}
		return false;
	}

	@Override
	public boolean remove(GeomFigure gf) {

		// if gf is not null, return false
		// ---Calculate number of slot where should be object gf
		// ---if slot is not empty
		// -------write null into the slot
		// -------decrease the size of hash table
		// -------return true
		if(gf != null){
			int slot = hash(gf);
			if(contains(gf)){
				table[slot] = null;
				size --;
				return true;
			}
		}

		return false;
	}

	@Override
	public boolean isEmpty() {

		return 0 == size;

	}

	@Override
	public void print() {

		// Output the table , where each row contains a number of the hash-table
		// slot, and the element itself.For example,

		// System.out.println(String.format(" %-6d|%s", index, table [index]));

		// If a slot is empty the row contains a number of the hash-table slot
		// and the message �The slot is empty�.
		for(int index = 0 ; index < table.length; index++ ){

			if( table[index] != null){
				System.out.println(String.format(" %-6d|%s", index, table [index]));
			}
			else {
				System.out.println(String.format("the slot %-6d is empty", index ));
			}
		}

	}

}
