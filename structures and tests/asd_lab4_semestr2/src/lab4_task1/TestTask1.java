package lab4_task1;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import org.junit.Test;

import common.GeomFigure;

public class TestTask1 {

	@Test
	public void testEmptyTable() {
		Hashtable tableEmpty = new Hashtable(3);
		assertEquals(tableEmpty.size(), 0);
		assertTrue(tableEmpty.isEmpty());

		// remove from empty hashTable
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		assertFalse(tableEmpty.remove(gf));
		assertEquals(tableEmpty.size(), 0);

		// search in empty hashTable
		assertFalse(tableEmpty.contains(gf));

	}

	@Test
	public void testAddOneElement() {

		// add one element, check the size
		Hashtable tableOneEl = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		tableOneEl.add(gf);
		assertEquals(tableOneEl.size(), 1);
		assertFalse(tableOneEl.isEmpty());

	}

	@Test
	public void testAddSomeNotUniqueElements() {

		Hashtable table = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		GeomFigure gfCopy = new GeomFigure(gf);
		table.add(gf);
		table.add(gfCopy);
		assertEquals(table.size(), 1);
		assertFalse(table.isEmpty());

	}

	@Test
	public void testAddSomeUniqueElements() {

		Hashtable table = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		GeomFigure gfUnique = new GeomFigure(27.7555, 6, 55651.54);
		table.add(gf);
		table.add(gfUnique);
		assertEquals(table.size(), 2);
		assertFalse(table.isEmpty());
	}

	@Test
	public void testRehash() {

		Hashtable table = new Hashtable(1);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		GeomFigure gfUnique = new GeomFigure(285, 6, 55651.54);
		table.add(gf);
		table.add(gfUnique);
		assertEquals(table.size(), 2);
		assertFalse(table.isEmpty());
		assertTrue(table.contains(gf));
		assertTrue(table.contains(gfUnique));
	}

	@Test
	public void testRemove() {
		Hashtable table = new Hashtable(1);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		table.remove(gf);
		assertEquals(table.size(), 0);
		assertTrue(table.isEmpty());

	}

	@Test
	public void testContains() {
		Hashtable table = new Hashtable(1);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		assertTrue(table.contains(gf));
		table.remove(gf);
		assertFalse(table.contains(gf));

	}

	@Test
	public void testSameHashAdd(){
		Hashtable table = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		GeomFigure gfSameHash = new GeomFigure(14.1, 20, 30);
		table.add(gfSameHash);
		assertEquals(table.size(), 1);
		assertFalse(table.isEmpty());
	}
	@Test
	public void testSameHashRemove(){
		Hashtable table = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		GeomFigure gfSameHash = new GeomFigure(11, 20, 30);
		table.remove(gfSameHash);
		assertEquals(table.size(), 1);
		assertFalse(table.isEmpty());
	}
	@Test
	public void testEmptyTableSearch(){
		Hashtable table = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		assertFalse(table.contains(gf));
	}
	@Test
	public void testSearch(){
		Hashtable table = new Hashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		GeomFigure gfSameHash = new GeomFigure(11, 20, 30);
		assertTrue(table.contains(gf));
		assertFalse(table.contains(gfSameHash));
	}

}
