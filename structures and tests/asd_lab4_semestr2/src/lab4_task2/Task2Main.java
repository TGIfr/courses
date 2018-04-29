package lab4_task2;

import com.opencsv.CSVReader;
import common.FigureSet;
import common.GeomFigure;
import lab4_task1.Hashtable;

import java.io.File;

import java.util.List;

import static lab4_task1.Task1Main.createArrayOfFigures;
import static lab4_task1.Task1Main.readcsvFile;

public class Task2Main {
	// name of file which stores data about geometric figures
	private static String fileName = "data/figures.csv";

	// path to the current directory that contains directory "data"
	private static String currenDir = System.getProperty("user.dir")
			+ File.separatorChar + "data";

	public static void main(String[] args) {
// 1) read all lines from a file

		List<String[]> lines = readcsvFile(fileName, currenDir);

		if (!lines.isEmpty()) {
			int numLines = lines.size();
			System.out.println("File contains " + numLines + "  lines");

			// 2) create the array of geometric figures and check data from the
			// file
			GeomFigure[] farray = createArrayOfFigures(lines);

			// 3) Create a set of figures
			//!! OAHashtable
			FigureSet figures = new OAHashtable();
			for (GeomFigure f : farray) {
				figures.add(f);
			}

			// 4) Print a set of figures
			figures.print();

		} else {
			System.out.println("Error: file  " + fileName + "   is empty");
			System.exit(0);
		}

	}



}
