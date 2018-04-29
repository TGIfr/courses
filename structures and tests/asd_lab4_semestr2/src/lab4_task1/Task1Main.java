package lab4_task1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;

import com.opencsv.CSVReader;
import common.FigureSet;
import common.GeomFigure;

public class Task1Main {
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
			FigureSet figures = new Hashtable();
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

	public static List<String[]> readcsvFile(String fileName, String dirName) {
		CSVReader reader = null;
		//GeomFigure[] figures = null;
		String path = Paths.get(currenDir, fileName).toString();
		List<String[]> list = null;

		// read data from a file
		try {

			reader = new CSVReader(new FileReader(path));
			System.out.println("File \"" + path + " \"  have been reading ");

			// read all lines from a file
			list = reader.readAll();
			reader.close();

		} catch (FileNotFoundException e) {
			System.out.println("Error: file  " + path + "   not found");
		} catch (IOException e) {
			System.err.println("Error:read file " + path + "   error");
		} catch (SecurityException e) {
			System.err.println(e.getMessage());
		}

		return list;
	}

	public static GeomFigure[] createArrayOfFigures(List<String[]> list) {

		int num = 0;

		// create empty array of geometric figures with the length = list.size()
		GeomFigure[] farray = new GeomFigure[list.size()];

		// start reading and analyzing each line from this list
		for (String[] line : list) {

			// line contains data about one geometric figures
			try {
				// check information about geometric figure and fill
				// fields of GeomFigure object
				if (line.length != GeomFigure.class.getDeclaredFields().length - 2) {
					System.err.println("Error: the line  \"" + Arrays.toString(line)
							+ "\" not completed");
					throw new NumberFormatException();

				}


				double centerX = Double.valueOf(line[0].trim());
				double centerY = Double.valueOf(line[1].trim());
				double radius = Double.valueOf(line[2].trim());
				if ( radius > 0) {
					farray[num++] = new GeomFigure(centerX, centerY, radius);
				} else {
					throw new NumberFormatException();
				}


			} catch (NumberFormatException e) {
				System.err.println("Error: wrong line");
			}

		}
		// check if all data in a file are valid
		if (num != list.size()) {

			// if not, create new array with smaller length
			farray = copyOf(farray, num);
		}

		return farray;
	}

	public static GeomFigure[] copyOf(GeomFigure[] farray, int num) {

		// Create new array of geometric figures of size num
		// Copy num first elements from farray students to the new array
		// Return new array
		if(num < 0 ) return new GeomFigure[0];
		if(num > farray.length ) num = farray.length;
		GeomFigure newArray []= new GeomFigure[num];
		System.arraycopy( farray, 0, newArray, 0, num );
		return newArray;
	}

}
