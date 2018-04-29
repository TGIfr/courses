package lab4_task2;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;


import org.junit.Test;

import common.GeomFigure;



public class TestTask2 {

	@Test
	public void testEmptyTable() {
		OAHashtable tableEmpty = new OAHashtable(3);
		assertEquals(tableEmpty.size(), 0);
		assertTrue(tableEmpty.isEmpty());

		// remove from empty hashTable
		GeomFigure gf = new GeomFigure(10, 20 , 30);
		assertFalse(tableEmpty.remove(gf));
		assertEquals(tableEmpty.size(), 0);

		// search in empty hashTable
		assertFalse(tableEmpty.contains(gf));

	}

	@Test
	public void testAddOneElement() {
		// add one element, check the size
		OAHashtable tableOneEl = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		tableOneEl.add(gf);
		assertEquals(tableOneEl.size(), 1);
		assertFalse(tableOneEl.isEmpty());
	}

	@Test
	public void testAddSomeNotUniqueElements() {
		OAHashtable table = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		GeomFigure gfCopy = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		table.add(gfCopy);
		assertEquals(table.size(), 1);
		assertFalse(table.isEmpty());
	}

	@Test
	public void testAddSomeUniqueElements() {
		OAHashtable table = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		GeomFigure gfUnique = new GeomFigure(27.7555, 6, 55651.54);
		table.add(gf);
		table.add(gfUnique);
		assertEquals(table.size(), 2);
		assertFalse(table.isEmpty());
		assertTrue(table.contains(gf));
		assertTrue(table.contains(gfUnique));
	}

	@Test
	public void testRehash() {
		OAHashtable table = new OAHashtable(1);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		GeomFigure gfUnique = new GeomFigure(27.7555, 6, 55651.54);
		table.add(gf);
		table.add(gfUnique);
		assertEquals(table.size(), 2);
		assertFalse(table.isEmpty());
		assertTrue(table.contains(gf));
		assertTrue(table.contains(gfUnique));

	}

	@Test
	public void testRemove() {
		OAHashtable table = new OAHashtable();
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		table.remove(gf);
		assertEquals(table.size(), 0);
		assertTrue(table.isEmpty());


		table.add(gf);
		GeomFigure gf2 = new GeomFigure(20, 30, 45.1);
		GeomFigure gf3 = new GeomFigure(256.4, 33, 45959.54);
		table.add(gf2);
		table.add(gf3);
		assertTrue(table.contains( gf));
		assertTrue(table.contains( gf2));
		assertTrue(table.contains( gf3));

		table.remove(gf);
		assertFalse(table.contains(gf));
		assertTrue(table.contains(gf2));

		table.remove(gf2);
		assertFalse(table.contains(gf2));
		assertTrue(table.contains(gf3));

		table.remove(gf3);
		assertFalse(table.contains(gf3));
		assertTrue(table.isEmpty());
	}

	@Test
	public void testContains() {
		OAHashtable table = new OAHashtable(1);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		assertTrue(table.contains(gf));
		table.remove(gf);
		assertFalse(table.contains(gf));
	}
	@Test
	public void testSameHashAdd(){
		OAHashtable table = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		GeomFigure gfSameHash = new GeomFigure(11, 20, 30);
		table.add(gfSameHash);
		assertEquals(table.size(), 2);
		assertTrue(table.contains(gf));
		assertTrue(table.contains(gfSameHash));
		assertFalse(table.isEmpty());
	}
	@Test
	public void testSameHashRemove(){
		OAHashtable table = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		GeomFigure gfSameHash = new GeomFigure(11, 20, 30);
		table.remove(gfSameHash);
		assertEquals(table.size(), 1);
		assertFalse(table.isEmpty());
	}
	@Test
	public void testEmptyTableSearch(){
		OAHashtable table = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		assertFalse(table.contains(gf));
	}
	@Test
	public void testSearch(){
		OAHashtable table = new OAHashtable(3);
		GeomFigure gf = new GeomFigure(10, 20 , 30  );
		table.add(gf);
		GeomFigure gfSameHash = new GeomFigure(11, 20, 30);
		assertTrue(table.contains(gf));
		assertFalse(table.contains(gfSameHash));
		table.add(gfSameHash);
		assertTrue(table.contains(gfSameHash));
	}

}
